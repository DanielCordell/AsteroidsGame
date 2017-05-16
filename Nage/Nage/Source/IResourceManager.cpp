#include "Includes/IResourceManager.h"
#include <memory>
#include <string>

template<class T, typename ID>
void IResourceManager<T, ID>::Load(ID id, const std::string& filename) {
	if (Map.find(id) == Map.end())
		throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to load Resource with ID that already exists " + std::to_string(int(id)) + " while loading" + filename);
	auto resource = std::make_shared<T>();
	if (!resource->loadFromFile(filename))
		throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Failed to Load " + filename);
	Map.insert(std::make_pair(id, resource));

}

template <class T, typename ID>
T& IResourceManager<T, ID>::Get(ID id) {
	auto data = Map.find(id);
	if (data == Map.end) throw std::runtime_error("Error in ResourceHolder of Type: " + std::string(typeid(T).name()) + " - Trying to get Resource of ID " + std::to_string(int(id)) + " that does not exist");
	return *(data->second);
}
