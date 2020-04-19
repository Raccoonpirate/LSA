#pragma once

#include <SFML/Audio.hpp>

#include <unordered_map>
#include <string>
#include <memory>

template<typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager {
	public:
		ResourceManager() = default;
		ResourceManager(const ResourceManager&) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;

		template<typename ... Args>
		void Load(const IDENTIFIER& id, Args&& ... args);

		RESOURCE& Get(const IDENTIFIER& id)const;

	private:
		std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> _map;
};

template<typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER> {
	public:
		ResourceManager() = default;
		ResourceManager(const ResourceManager&) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;

		template<typename ... Args>
		void Load(const IDENTIFIER& id, Args&& ... args);

		sf::Music& Get(const IDENTIFIER& id)const;

	private:
		std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> _map;
};

template<typename RESOURCE, typename IDENTIFIER>
template<typename ...Args>
void ResourceManager<RESOURCE, IDENTIFIER>::Load(const IDENTIFIER & id, Args && ...args) {
	std::unique_ptr<RESOURCE> ptr(new RESOURCE);
	if (not ptr->loadFromFile(std::forward<Args>(args)...)) {
		throw std::runtime_error("Impossible to load file");
	}
	_map.emplace(id, std::move(ptr));
}

template<typename RESOURCE, typename IDENTIFIER>
RESOURCE & ResourceManager<RESOURCE, IDENTIFIER>::Get(const IDENTIFIER & id) const {
	return *_map.at(id);
}

// Only sf::Music not sound effects
template<typename IDENTIFIER>
template<typename ... Args>
void ResourceManager<sf::Music, IDENTIFIER>::Load(const IDENTIFIER& id, Args&& ... args) {
	std::unique_ptr<sf::Music> ptr(new sf::Music);
	if (not ptr->openFromFile(std::forward<Args>(args)...)) {
		throw std::runtime_error("Impossible to load file");
	}
	_map.emplace(id, std::move(ptr));
};

template<typename IDENTIFIER>
sf::Music& ResourceManager<sf::Music, IDENTIFIER>::Get(const IDENTIFIER& id) const {
	return *_map.at(id);
}