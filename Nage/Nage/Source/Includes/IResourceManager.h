#pragma once
#include <unordered_map>


template <class T, typename  ID>
class IResourceManager {
private:
	std::unordered_map<ID,T*> Map;
public:
	T& Get(ID id);

	void Load(ID id, const std::string& filename);
};
