#include "GameState.hpp"

GameState::GameState(StateMachine& stateMachine, StateData& stateData)
	: State {stateMachine, stateData}
	, _world{stateData.window} {
}

void GameState::Draw() {
	_world.Draw();
}

void GameState::Update(sf::Time dt) {
	_world.Update(dt);
}

void GameState::HandleEvent(const sf::Event& event) {
	// Game input handling

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		this->_FSM.PushState(StateType::Pause);
	}

	_world.HandleEvent(event);
}