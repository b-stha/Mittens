#include "data.h"
#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include "parsejson.h"

using json = nlohmann::json;

int main() {
    std::string url, set;

    std::string unitAPIName, unitDispName;

    std::string traitAPIName, traitDispName;

    json outJson;

    std::cout << "Enter link to data: ";
    std::getline(std::cin, url);
    std::cout << "Current set: ";
    std::getline(std::cin, set);

    json raw = makeReq(url, 10, 1000);

    for (auto& unit : raw["sets"][set]["champions"]) {
        unitAPIName = unit["apiName"];
        unitDispName = unit["name"];

        outJson["unitData"][unitAPIName] = { unitDispName, "" };
    }

    for (auto& trait : raw["sets"][set]["traits"]) {
        traitAPIName = trait["apiName"];
        traitDispName = trait["name"];

        std::vector<int> traitLevels;
        std::unordered_map<int, std::string> traitStyles;

        for (auto& level : trait["effects"]) {
            traitLevels.push_back(level["minUnits"]);
            traitStyles[level["style"]] = "";

        }

        outJson["traitData"][traitAPIName]["name"] = traitDispName;
        outJson["traitData"][traitAPIName]["breakpoints"] = traitLevels;
        outJson["traitData"][traitAPIName]["styles"] = traitStyles;
    }

    std::ofstream out("setdata.json");
    out << outJson.dump(4);
    return 0;
}
