#include "parsejson.h"

void from_json(const json& j, Trait& t)
{
    j.at("name").get_to(t.name);
    j.at("num_units").get_to(t.numUnits);
    j.at("style").get_to(t.style);
    j.at("tier_current").get_to(t.tierCurrent);
    j.at("tier_total").get_to(t.tierTotal);
};

void from_json(const json& j, Unit& u)
{
    j.at("character_id").get_to(u.characterID);
    j.at("itemNames").get_to(u.items);
    j.at("rarity").get_to(u.rarity);
    j.at("tier").get_to(u.tier);
};

void from_json(const json& j, PlayerMatchInfo& p)
{
    j.at("augments").get_to(p.augments);
    j.at("traits").get_to(p.traits);
    j.at("units").get_to(p.units);
    std::reverse(p.units.begin(), p.units.end());
    j.at("gold_left").get_to(p.goldLeft);
    j.at("level").get_to(p.level);
    j.at("placement").get_to(p.placement);
    j.at("puuid").get_to(p.puuid);
};

void from_json(const json& j, Info& i)
{
    j.at("participants").get_to(i.playerInfoList);
    j.at("game_length").get_to(i.gameLength);
};

json parseJSON(cpr::Response r) {
    try {
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

Player 
