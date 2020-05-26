#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "State.hpp"
#include "StateData.hpp"
#include "StateMachine.hpp"

class PauseState : public State {
	public:
		PauseState(StateMachine& stateMachine, StateData& stateData);
		virtual void HandleEvent(const sf::Event & event) override;
		virtual void Update(sf::Time dt) override;
		virtual void Draw() override;

	private:
		sf::Sprite _background;
		sf::Text _pausedText;
		sf::Text _instructionText;

};

