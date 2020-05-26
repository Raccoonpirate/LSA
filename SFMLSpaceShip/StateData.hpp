#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <vector>

#include "Configuration.hpp"

struct StateData {
	StateData(/*std::vector<Game>& games, 
			  ResourceManager& resourceManager, 
			  SoundManager& soundManager,
			  GUIManager& guiManager, 
			  InputHandler& inputHandler,*/ 
			  sf::RenderWindow& window);

	//std::vector<Game>& games;

	//ResourceManager& resourceManager;
	//SoundManager& soundManager;
	//GUIManager& guiManager;
	//InputHandler& inputHandler;

	sf::RenderWindow& window;
};