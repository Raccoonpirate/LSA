#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.hpp"

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

		sf::RenderWindow _window;
		Player _player;
};
