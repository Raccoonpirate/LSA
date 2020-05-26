#include "Game.hpp"

Game::Game() : _window(sf::VideoMode(800, 600), "Spaceship not adventures", sf::Style::Close | sf::Style::Titlebar),
_world {_window},
_configurationMenu {_window},
_pauseMenu {_window},
_state {State::StateMainMenu},
_player {} {
	InitGui();
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
		if (input.type == sf::Event::Closed) {
			_window.close();
		} else if (input.type == sf::Event::KeyPressed && input.key.code == sf::Keyboard::Escape && _state == State::StateGame) {
			_state = StatePaused;
		} else {
			switch (_state) {
				case StateMainMenu: {
					break;
				}
				case StateGame: {
					_player.PollEvents(input);
					break;
				}
				case StateConfiguration: {
					_configurationMenu.ProcessEvent(input);
					break;
				}
				case StatePaused: {
					_pauseMenu.ProcessEvent(input);
					break;
				}
				default: break;
			}
		}
	}

	switch (_state) {
		case StateMainMenu: {
			break;
		}
		case StateGame: {
			_player.RealTimeEvents();
			break;
		}
		case StateConfiguration: {
			_configurationMenu.ProcessEvents();
			break;
		}
		case StatePaused: {
			_pauseMenu.ProcessEvents();
			break;
		}
		default: break;
	}
}

void Game::Update(const sf::Time& dt) {
	_world.Update(dt);
}

void Game::Render() {
	_window.clear();

	switch (_state) {
		case StateMainMenu: {
			break;
		}
		case StateGame: {
			_world.Draw();
			break;
		}
		case StateConfiguration: {
			_window.draw(_configurationMenu);
			break;
		}
		case StatePaused: {
			_window.draw(_pauseMenu);
			break;
		}
		default: break;
	}

	_window.display();
}

void Game::InitGame() {
}

void Game::InitGui() {
	//_pauseMenu
	{
		VLayout* layout = new VLayout;
		layout->SetSpace(50);

		Label* pause = new Label("Pause");
		pause->SetCharacterSize(70);
		layout->add(pause);

		TextButton* exit = new TextButton("Exit");
		exit->onClick = [this] (const sf::Event&, Button& button) {
			_state = StateMainMenu;
		};
		layout->add(exit);

		_pauseMenu.SetLayout(layout);

		_pauseMenu.bind(Configuration::GuiInputs::Escape, [this] (const sf::Event& event) {
			_state = StateGame;
		});
	}

	//configuration
	{
		VLayout* layout = new VLayout;
		layout->SetSpace(50);

		Label* conf = new Label("Config");
		conf->SetCharacterSize(70);
		layout->add(conf);

		TextButton* exit = new TextButton("Back");
		exit->onClick = [this] (const sf::Event&, Button& button) {
			_state = StateMainMenu;
		};
		layout->add(exit);

		_configurationMenu.SetLayout(layout);

		_configurationMenu.bind(Configuration::GuiInputs::Escape, [this] (const sf::Event& event) {
			_state = StateMainMenu;
		});
	}
}