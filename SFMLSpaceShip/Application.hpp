#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Configuration.hpp"
#include "StateMachine.hpp"
#include "GameState.hpp"
#include "TitleState.hpp"
#include "MenuState.hpp"
#include "PauseState.hpp"

class Application {
	public:
		Application();
		Application(const Application& application) = delete;
		Application& operator=(const Application& application) = delete;

		void run(int minimumFramePerSeconds);

	private:
		void HandleEvents();
		void Update(sf::Time dt);
		void Render();

		sf::RenderWindow _window;

		StateData _stateData;
		StateMachine _stateMachine;
};

