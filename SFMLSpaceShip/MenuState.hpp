#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "State.hpp"
#include "StateData.hpp"
#include "StateMachine.hpp"
#include "GUI.hpp"

class MenuState : public State {
	public:
		MenuState(StateMachine& stateMachine, StateData& stateData);

		virtual void Draw() override;
		virtual void Update(sf::Time dt) override;
		virtual void HandleEvent(const sf::Event & event) override;

	private :
		sf::Sprite _background;
		sf::Sprite _planet;
		Frame _mainMenu;
};

