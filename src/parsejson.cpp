#include "parsejson.h"

void from_json(const json& j, Unit& u)
{
    j.at("character_id").get_to(u.characterID);
    j.at("itemNames").get_to(u.items);
    j.at("rarity").get_to(u.rarity);
    j.at("tier").get_to(u.tier);
};

void from_json(const json& j, Trait& t) {
    j.at("name").get_to(t.apiName);
    j.at("style").get_to(t.style);
    j.at("tier_current").get_to(t.level);
    j.at("num_units").get_to(t.numUnits);
}

void from_json(const json& j, PlayerMatchInfo& p)
{
    //j.at("augments").get_to(p.augments);
    j.at("units").get_to(p.units);
    std::reverse(p.units.begin(), p.units.end());
    j.at("gold_left").get_to(p.goldLeft);
    j.at("level").get_to(p.level);
    j.at("placement").get_to(p.placement);
    j.at("puuid").get_to(p.puuid);
    j.at("traits").get_to(p.traits);
    j.at("companion").at("item_ID").get_to(p.companionID);
    std::sort(p.traits.begin(), p.traits.end(), sortByStyle);
};

void from_json(const json& j, Info& i)
{
    j.at("participants").get_to(i.playerInfoList);
    j.at("game_length").get_to(i.gameLength);
};

void from_json(const json& j, League& l) {
    j.at("tier").get_to(l.tier);
    j.at("rank").get_to(l.rank);
    j.at("leaguePoints").get_to(l.currLP);
}

void from_json(const json& j, TraitTemplate& t) {
    j.at("name").get_to(t.name);
    j.at("breakpoints").get_to(t.breakpoints);
    j.at("styles").get_to(t.styles);
}

json parseJSON(cpr::Response r) {
    try {
        std::cout << "Response text: " << r.text << std::endl;
        
        if (r.text.empty()) {
            throw std::runtime_error("Empty response text");
        }

        return json::parse(r.text);
    }
    catch (json::parse_error& e) {
        throw std::runtime_error(std::string("JSON parse error: ") + e.what());
    }
    catch (json::type_error& e) {
        throw std::runtime_error(std::string("JSON type error: ") + e.what());
    }
    catch (json::exception& e) {
        throw std::runtime_error(std::string("JSON error: ") + e.what());
    }
    catch (std::exception& e) {
        throw std::runtime_error(std::string("Error: ") + e.what());
    }
}

json makeReq(const std::string& url, int maxTries, int delayMs) {
    cpr:: Response r;
    for (int attempt = 1; attempt <= maxTries; attempt++) {
        r = cpr::Get(cpr::Url{url});
        /*
        std::cout << "Attempt " << attempt << ": Response text: " << r.text << std::endl;
        std::cout << "Status code: " << r.status_code << std::endl;
        std::cout << "Response headers: " << std::endl;
        for (const auto& header : r.header) {
            std::cout << header.first << ": " << header.second << std::endl;
        }
        */
        try {
            return parseJSON(r);
        }
        catch (const std::runtime_error& e) {
            std::cerr << e.what() << std::endl;
            if (attempt < maxTries) {
                std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            }
            else {
                throw;
            }
        }
    }
    throw std::runtime_error("Failed to retrieve valid JSON");
}