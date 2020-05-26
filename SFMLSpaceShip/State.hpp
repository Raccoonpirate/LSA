#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>

#include <memory>

#include "StateType.hpp"
//#include "StateData.hpp"
//#include "StateMachine.hpp"
//#include "Configuration.hpp"

struct StateData;
class StateMachine;

class State {
	public:
		State(StateMachine& FSM, StateData& stateData);
		virtual ~State();

		virtual void Draw() = 0;
		virtual void Update(sf::Time dt) = 0;
		virtual void HandleEvent(const sf::Event& event) = 0;

		virtual bool IsTransparent() const;
		virtual bool IsDependent() const;

	protected:
		StateMachine& _FSM;
		StateData& _stateData;

};

