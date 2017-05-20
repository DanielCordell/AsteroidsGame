#pragma once
#include <unordered_map>
#include <memory>

#include "ResourceTypes.h"
#include "EngineLogger.h"


enum class IDSound { one };
enum class IDTexture { one };
enum class IDShader { one };
enum class IDMusic { one };
enum class IDFont { one };

template <class T, typename  ID>
class IResourceManager {
	std::unordered_map<ID,std::shared_ptr<T>> Map;
	std::shared_ptr<T> defResource;
public:
	IResourceManager() {
		defResource = std::make_shared<T>();
	}

	IResourceManager(std::shared_ptr<T> def) {
		defResource = def;
	}

	T& Get(ID id) {
		auto data = Map.find(id);
		if (data == Map.end()) {
			EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to get Resource of ID " + std::to_string(int(id)) + " that does not exist");
			return *defResource;
		}
		return *(data->second);
	}

	// Load function for texture, font and sound
	void Load(ID id, const std::string& filename) {
		if (Map.find(id) != Map.end()) {
			EngineLogger::Log(EngineLogger::LOG_ERROR,"Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
			return;
		}
		auto resource = std::make_shared<T>();
		if (!resource->loadFromFile(filename)) {
			EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Failed to Load " + filename);
			resource = defResource;
		}
		Map.insert(std::make_pair(id, resource));
	}

	//Load function for resource (with second parameter).
	template <typename Param>
	void Load(ID id, const std::string& filename, Param secondParam) {
		if (Map.find(id) != Map.end()) {
			EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
			return;
		}
		auto resource = std::make_shared<T>();
		if (!resource->loadFromFile(filename, secondParam)) {
			EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Failed to Load " + filename);
			resource = defResource;
		}
		Map.insert(std::make_pair(id, resource));

	}
	
	
	void Load(ID id, std::shared_ptr<T> data) {
		std::shared_ptr<T> resource;
		if (Map.find(id) != Map.end()) {
			char str[17];
			sprintf(str, "%p", &data);
			EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading data from " + str);
			resource = defResource;
		}
		resource = data;
		Map.insert(std::make_pair(id, resource));
	}
};

template <>
inline void IResourceManager<sf::Music, IDMusic>::Load(IDMusic id, const std::string& filename) {
	if (Map.find(id) != Map.end()) {
		EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(sf::Music).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
		return;
	}
	auto resource = std::make_shared<sf::Music>();
	if (!resource->openFromFile(filename)) {
		EngineLogger::Log(EngineLogger::LOG_ERROR, "Error in ResourceHolder of Type: " + std::string(typeid(sf::Music).name()) + " - Failed to Load " + filename);
		resource = defResource;
	}
	Map.insert(std::make_pair(id, resource));
}