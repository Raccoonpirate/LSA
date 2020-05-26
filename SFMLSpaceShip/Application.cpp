#include "Application.hpp"

Application::Application() 
	: _window {sf::VideoMode(1280, 1024), "Little spaceship adventures", sf::Style::Close | sf::Style::Titlebar}
	, _stateData {_window}
	, _stateMachine {_stateData} {

	_stateMachine.RegisterState<TitleState>(StateType::Title);
	_stateMachine.RegisterState<GameState>(StateType::Game);
	_stateMachine.RegisterState<MenuState>(StateType::Menu);
	_stateMachine.RegisterState<PauseState>(StateType::Pause);

	//_stateMachine.PushState(StateType::Title);
	_stateMachine.PushState(StateType::Game);
}

void Application::run(int minimumFramePerSeconds) {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

	while (_window.isOpen()) {
		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;

			HandleEvents();
			Update(timePerFrame);
		}
		Render();
	}
}

void Application::HandleEvents() {
	sf::Event input;
	while (_window.pollEvent(input)) {
		if (input.type == sf::Event::Closed) {
			_window.close();
		}

		_stateMachine.HandleEvent(input);
	}
}

void Application::Update(sf::Time dt) {
	_stateMachine.Update(dt);
}

void Application::Render() {
	_window.clear();

	_stateMachine.Draw();

	_window.setView(_window.getDefaultView());

	_window.display();
}