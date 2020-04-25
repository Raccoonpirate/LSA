#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GUI.hpp"
#include "Player.hpp"
#include "World.hpp"

class Game {
	public:
		Game(const Game&) = delete;
		Game& operator=(const Game&) = delete;

		Game();
		void run(int);

	private:
		void ProcessEvents();
		void Update(const sf::Time&);
		void Render();

		void InitGui();
		void InitGame();

		enum State {
			StateMainMenu,
			StateGame,
			StateConfiguration,
			StatePaused,
			StateExit
		} _state;

		sf::RenderWindow _window;

		World _world;

		Frame _mainMenu;
		Frame _configurationMenu;
		Frame _pauseMenu;
};
