#include "data.h"
#include <fstream>
#include <thread>

const nlohmann::json* Data::getObj(const nlohmann::json& j, const std::string& key) const {
	if (j.contains(key) && j[key].is_object()) {
		return &j[key];
	}
	return nullptr;
}

std::optional<std::string> Data::getJsonStr(const nlohmann::json& j, const std::string& key) const {
	if (j.contains(key) && j[key].is_string()) {
		return j[key].get<std::string>();
	}
	return std::nullopt;
}

std::optional<int> Data::getJsonInt(const nlohmann::json& j, const std::string& key) const{
	if (j.contains(key) && j[key].is_number_integer()) {
		return j[key].get<int>();
	}
	return std::nullopt;
}

std::unordered_map<std::string, UnitInfo> Data::loadUnitData(const nlohmann::json& dataJson, const std::string& set) {
	std::unordered_map<std::string, UnitInfo> infoList;
	for (auto& unit : dataJson["sets"][set]["champions"]) {
        std::string apiName = unit["apiName"].get<std::string>();
        std::string dispName = unit["name"].get<std::string>();
		int rarity = unit["cost"].get<int>() - 1;
		UnitInfo unitInfo;
		unitInfo.name = dispName;
		unitInfo.rarity = rarity;
		infoList[apiName] = unitInfo;
    }
	return infoList;
}

std::unordered_map<std::string, TraitInfo> Data::loadTraitData(const nlohmann::json& dataJson, const std::string& set) {
	std::unordered_map<std::string, TraitInfo> infoList;
	for (auto& trait : dataJson["sets"][set]["traits"]) {
		std::string apiName = trait["apiName"];
		std::string dispName = trait["name"];
		std::vector<int> traitLevels;

		for (auto& level : trait["effects"]) {
			auto levelVal = getJsonInt(level, "minUnits");
			traitLevels.push_back(levelVal.value_or(0));
		}
		TraitInfo traitInfo;
		traitInfo.name = dispName;
		traitInfo.breakpoints = traitLevels;
		infoList[apiName] = traitInfo;
	}
	return infoList;
}

const std::string& Data::getEmote(const std::string& emoteName) const {
	auto it = emoteMap.find(emoteName);
	if (it != emoteMap.end()) {
		return it->second;
	} else {
		static const std::string defaultEmote = "<:steamhappy:1123798178030964848>";
		return defaultEmote;
	}
}

std::future<void> Data::loadData(dpp::cluster& cluster) {
	auto pPromise = std::make_shared<std::promise<void>>();
	auto future = pPromise->get_future();

	std::string url = "https://raw.communitydragon.org/pbe/cdragon/tft/en_us.json";
	cluster.request(url, dpp::m_get, [this, pPromise](const dpp::http_request_completion_t& http) mutable {
		if (http.status != 200 ) {
			try {
				throw std::runtime_error("HTTP request failed with status: " + std::to_string(http.status));
			} catch (...) {
				pPromise->set_exception(std::current_exception());
			}
    		return;
		}
		nlohmann::json dataJson = nlohmann::json::parse(http.body);
		std::string latestSet = "16";

		this->unitData = loadUnitData(dataJson, latestSet);
		this->traitData = loadTraitData(dataJson, latestSet);

		pPromise->set_value();
	});
	return future;
}

std::future<void> Data::loadEmojis(dpp::cluster& cluster) {
	auto pPromise = std::make_shared<std::promise<void>>();
	auto future = pPromise->get_future();
	std::cout << "Cluster app id: " << cluster.me.id << std::endl;
	cluster.application_emojis_get([this, pPromise](const dpp::confirmation_callback_t& cc) mutable {
		if (cc.is_error()) {			
			try {
			throw std::runtime_error("HTTP request failed with status: " + cc.get_error().human_readable);
			} catch (...) {
				pPromise->set_exception(std::current_exception());
			}
			return;
		}
		dpp::emoji_map returnedMap = cc.get<dpp::emoji_map>();
		for (auto& [key, value] : returnedMap) {
			emoteMap[value.name] = key;
		}
		pPromise->set_value();
	});
	return future;
}

std::future<std::shared_ptr<Data>> Data::asyncCreateData(dpp::cluster& cluster) {
    auto promise = std::make_shared<std::promise<std::shared_ptr<Data>>>();
    auto future = promise->get_future();

	auto pData = std::shared_ptr<Data>(new Data());

    std::future<void> fData = pData->loadData(cluster);
    std::future<void> fEmojis = pData->loadEmojis(cluster);

    std::thread([promise, pData, fData = std::move(fData), fEmojis = std::move(fEmojis)]() mutable {
        try {
            fData.get();
            fEmojis.get();

            promise->set_value(pData);
        } catch (...) {
			promise->set_exception(std::current_exception());
        }
    }).detach();

    return future;
}