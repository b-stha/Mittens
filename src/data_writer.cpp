#include <data.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include "parsejson.h"

using json = nlohmann::json;

int main() {
    std::string url;
    int set;

    std::string unitAPIName, unitDispName;

    json outJson;

    std::cout << "Enter link to data: ";
    std::getline(std::cin, url);
    std::cout << "Current set: ";
    std::cin >> set;

    json raw = makeReq(url, 10, 1000);

    for (auto& unit : raw["sets"][set]["champions"]) {
        unitAPIName = unit["apiName"];
        unitDispName = unit["name"];

        outJson["unitData"][unitAPIName] = { unitDispName, "" };
    }

    std::ofstream out("setdata.json");
    out << outJson.dump(4);
    return 0;
}
