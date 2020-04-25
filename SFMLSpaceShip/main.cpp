#include <iostream>

#include "Game.hpp"
#include "Configuration.hpp"

int main() {
	try {
		Configuration::Initialize();
		Game game;
		game.run(60);
	} catch (std::exception& e) {
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}
}