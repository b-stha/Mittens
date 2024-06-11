#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <cpr/cpr.h>

using json = nlohmann::json;

struct Trait {
    std::string name;
    int numUnits = 0;
    int style = 0;
    int tierCurrent = 0;
    int tierTotal = 0;
};

struct Unit {
    std::string characterID;
    std::vector<std::string> items;
    int rarity = 0;
    int tier = 0;
};

struct Participant {
    std::vector<std::string> augments;
    std::vector<Trait> traits;
    std::vector<Unit> units;
    int goldLeft = 0;
    int level = 0;
    int placement = 0;
    std::string puuid;
};

struct Info {
    long long gameLength;
    std::vector<Player> playerList;
};

Participant findP(const Info& info, const std::string& puuid) {
    for (const auto& participant : info.participants) {
        if (participant.puuid == puuid) {
            return participant;
        }
    }
    throw std::runtime_error("Participant with the specified PUUID not found");
};

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

void from_json(const json& j, Participant& p)
{
    j.at("augments").get_to(p.augments);
    j.at("traits").get_to(p.traits);
    j.at("units").get_to(p.units);
    j.at("gold_left").get_to(p.goldLeft);
    j.at("level").get_to(p.level);
    j.at("placement").get_to(p.placement);
    j.at("puuid").get_to(p.puuid);
};

void from_json(const json& j, Info& i)
{
    j.at("participants").get_to(i.participants);
    j.at("game_length").get_to(i.gameLength);
};

json parseJSON(cpr::Response& r)
{
    try {
        return json::parse(r.text);
    }
    catch (json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
        return 1;
    }
    catch (json::exception& e) {
        std::cerr << "JSON error: " << e.what() << std::endl;
        return 1;
    }
    catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

