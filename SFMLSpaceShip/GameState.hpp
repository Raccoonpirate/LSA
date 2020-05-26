#pragma once

#include "World.hpp"
//#include "Player.hpp"
#include "State.hpp"
#include "StateMachine.hpp"

class GameState : public State {
	public:
		GameState(StateMachine& stateMachine, StateData& stateData);

		virtual void HandleEvent(const sf::Event& event) override;
		virtual void Update(sf::Time dt) override;
		virtual void Draw() override;

	private:
		World _world;
		//Player& _player;
};

