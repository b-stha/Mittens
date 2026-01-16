#include "Player.h"
#include "RiotAPI.h"
#include "bot.h"
#include "apikeys.h"
#include "Worker.h"
#include "data.h"
#include <dpp/dpp.h>
#include <atomic>
#include <memory>

std::atomic <bool> running = false;

void stop() {
    running = false;
}

int main() {
    Bot mittens;
    mittens.run();

    signal(SIGINT, [](int code) {
        running = false;
        });

    running = true;
    auto &bot = mittens.getBotCluster();
    Worker* worker = mittens.getWorker();
    try {
        while (running) {
            auto userSnapshot = mittens.getUserSnapshot();
            if (!userSnapshot.empty()) {
                for (auto& user : userSnapshot) {
                    if (worker->enqueue(user)) {
                        std::cout << "enqueued: " << user->getPUUID() << "\n";
                    } else {
                        std::cout << "skipped dup: " << user->getPUUID() << "\n";
                    }
                }
                worker->startTask();
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
