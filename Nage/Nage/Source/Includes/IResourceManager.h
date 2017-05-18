#pragma once
#include <unordered_map>
#include <memory>

#include "SFML/Audio/Music.hpp"

template <class T, typename  ID>
class IResourceManager {
private:
	std::unordered_map<ID,std::shared_ptr<T>> Map;
public:
	T& Get(ID id) {
		auto data = Map.find(id);
		if (data == Map.end()) throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to get Resource of ID " + std::to_string(int(id)) + " that does not exist");
		return *(data->second);
	}
	void Load(ID id, const std::string& filename) {
		if (Map.find(id) != Map.end())
			throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
		auto resource = std::make_shared<T>();
		if (!resource->loadFromFile(filename))
			throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Failed to Load " + filename);
		Map.insert(std::make_pair(id, resource));
	}
	template <typename Parameter>
	void Load(ID id, const std::string& filename, Parameter& secondParam) {
		if (Map.find(id) != Map.end())
			throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(sf::Shader).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
		auto resource = std::make_shared<sf::Shader>();


		if (!resource->loadFromFile(filename, secondParam))
			throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(sf::Shader).name()) + " - Failed to Load " + filename);
		Map.insert(std::make_pair(id, resource));

	}
};

enum class IDSound {one};
enum class IDTexture { one };
enum class IDShader { one };
enum class IDMusic { one };
enum class IDFont { one };

template<>
inline void IResourceManager<sf::Music, IDMusic>::Load(IDMusic id, const std::string& filename) {
	if (Map.find(id) != Map.end())
		throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(sf::Music).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
	auto resource = std::make_shared<sf::Music>();
	if (!resource->openFromFile(filename))
		throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(sf::Music).name()) + " - Failed to Load " + filename);
	Map.insert(std::make_pair(id, resource));

}
