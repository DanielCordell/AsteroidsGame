#pragma once
#include <unordered_map>
#include <memory>

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/RenderTexture.hpp"

#include "ResourceTypes.h"
#include "EngineLogger.h"
#include "OS.h"


enum class IDSound { one };
enum class IDTexture { ASTEROID_HUGE, ASTEROID_LARGE, ASTEROID_NORMAL, ASTEROID_TINY, PLAYER, PLAYER_MOVE };
enum class IDShader { one };
enum class IDMusic { one };
enum class IDFont { one };

template <class T, typename  ID>
class ResourceManager {
	std::unordered_map<ID,std::shared_ptr<T>> Map;
	std::shared_ptr<T> defResource;
public:
	ResourceManager() {
		defResource = std::make_shared<T>();
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
};

template <>
inline void ResourceManager<sf::Music, IDMusic>::Load(IDMusic id, const std::string& filename) {
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
template <>
inline ResourceManager<sf::Texture, IDTexture>::ResourceManager() {
	// Defining Default Texture
	// I'm so sorry
	defResource = std::make_shared<sf::Texture>();
	sf::Image image;
	unsigned char x[16]{ 0, 0, 0, 255, 172, 0, 172, 255, 172, 0, 172, 255, 0, 0, 0, 255 };
	image.create(2, 2, x);
	sf::Texture tex;
	tex.loadFromImage(image);
	sf::Sprite sprite(tex);
	sprite.setScale(64, 64);
	sf::RenderTexture rt;
	rt.create(128, 128);
	rt.draw(sprite);
	rt.display();
	tex = rt.getTexture();
	defResource->loadFromImage(tex.copyToImage());
}


template <>
inline ResourceManager<sf::Shader, IDShader>::ResourceManager() {
	// Defining Default Shader
	defResource = std::make_shared<sf::Shader>();
	defResource->loadFromMemory("void main(){}", sf::Shader::Fragment);
}


template <>
inline ResourceManager<sf::Font, IDFont>::ResourceManager() {
	// Defining Default Font
	defResource = std::make_shared<sf::Font>();
	defResource->loadFromFile(FONTPATH);
}