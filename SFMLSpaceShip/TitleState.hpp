#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "State.hpp"
#include "StateData.hpp"
#include "StateMachine.hpp"

class TitleState : public State {
	public:
		TitleState(StateMachine& stack, StateData& stateData);

		virtual void HandleEvent(const sf::Event& event);
		virtual void Update(sf::Time dt);
		virtual void Draw();

	private:
		sf::Sprite _background;
		sf::Sprite _planet;
		sf::Text _gameTitle;
		sf::Text _pressToContinueText;
		sf::Time _textEffectTime;

		bool _showText;
};

