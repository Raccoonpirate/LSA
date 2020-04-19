#include "Game.hpp"
#include "Configuration.hpp"

int main() {
	Configuration::Initialize();

	Game game;
	game.run(60);
}