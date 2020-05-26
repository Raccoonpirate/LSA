#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <unordered_map>

#include "State.hpp"
#include "StateType.hpp"
#include "StateData.hpp"

class StateMachine {
	public:
		using StatePtr = std::unique_ptr<State>;

		StateMachine(StateData& stateData);
		StateMachine(const StateMachine&) = delete;
		StateMachine& operator=(const StateMachine&) = delete;

		void HandleEvent(const sf::Event& event);
		void Update(sf::Time dt);
		void Draw();

		void ChangeState(StateType stateType);

		void PushState(StateType stateType);
		void PopState();
		void ClearStates();

		template<typename T>
		void RegisterState(StateType stateType);

	private:
		StatePtr GetState(StateType statetype);
		void RunStateActions();

		std::vector<std::pair<StateType, StatePtr>> _stateStack;
		std::vector<std::function<void()>> _stateActions;

		StateData& _stateData;
		std::unordered_map<StateType, std::function<StatePtr()>> _stateFactory;
};

template<typename T>
void StateMachine::RegisterState(StateType stateType) {
	_stateFactory[stateType] = [this] () {
		return std::make_unique<T>(*this, this->_stateData);
	};
}