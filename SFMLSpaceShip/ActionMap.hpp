#pragma once

#include <unordered_map>

#include "Action.hpp"

template<typename T = int>
class ActionMap {
	public:
		ActionMap() = default;
		ActionMap(const ActionMap<T>&) = delete;
		ActionMap<T>& operator=(const ActionMap<T>&) = delete;

		void map(const T& key, const Action& action);
		const Action& get(const T& key)const;

	private:
		std::unordered_map<T, Action> _map;
};

template<typename T>
void ActionMap<T>::map(const T& key, const Action& action) {
	_map.emplace(key, action);
}

template<typename T>
const Action& ActionMap<T>::get(const T& key) const {
	return _map.at(key);
}
