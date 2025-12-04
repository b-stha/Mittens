#include "Player.h"
#include "RiotAPI.h"
#include "parsejson.h"
#include "bot.h"
#include "apikeys.h"
#include "Worker.h"
#include "data.h"
#include <dpp/dpp.h>
#include <atomic>
#include <memory>

using json = nlohmann::json;
std::atomic <bool> running = false;
std::unique_ptr<Data> loadedData;

void stop() {
    running = false;
}

int main() {
    try {
        loadedData = std::make_unique<Data>();
    } catch (const std::exception& e) {
        std::cerr << "Error loading data: " << e.what() << std::endl;
        return 1;
    }
    
    Bot mittens;
    Riot riotAPI(&mittens.getBotCluster(), TFT_APIKEY);
    Worker worker(&riotAPI, &mittens, loadedData.get());
    mittens.run();
    signal(SIGINT, [](int code) {
        running = false;
        });

    running = true;
    auto &bot = mittens.getBotCluster();
    try {
            while (running) {
            if (!mittens.getUserVec().empty()) {
                for (auto& user : mittens.getUserVec())
                {
                    worker.enqueue(user.get());
                    worker.startTask();
                }
            }
            std::this_thread::sleep_for(std::chrono::seconds(10));
        };
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        
        return 1;
    }

    return 0;
}
