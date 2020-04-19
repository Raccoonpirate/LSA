#include "Game.hpp"

Game::Game() : _window(sf::VideoMode(800, 600), "Spaceship not adventures"), _player() {
	_player.SetPosition(100.f, 100.f);
}

void Game::run(int minimumFramePerSeconds) {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

	while (_window.isOpen()) {
		ProcessEvents();
		timeSinceLastUpdate = clock.restart();
		while (timeSinceLastUpdate > timePerFrame) {
			timeSinceLastUpdate -= timePerFrame;
			Update(timePerFrame);
		}

		Update(timeSinceLastUpdate);
		Render();
	}
}

void Game::ProcessEvents() {
	sf::Event input;
	while (_window.pollEvent(input)) {
		if ((input.type == sf::Event::Closed) ||
			((input.type == sf::Event::KeyPressed) && (input.key.code == sf::Keyboard::Escape))) {
			_window.close();
		}
	}
	_player.ProcessEvents();
}

void Game::Update(const sf::Time& dt) {
	_player.Update(dt);
}

void Game::Render() {
	_window.clear();
	_window.draw(_player);
	_window.display();
}
