#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "ActionMap.hpp"

class Configuration {
	public:
		Configuration() = delete;
		Configuration(const Configuration&) = delete;
		Configuration& operator=(const Configuration&) = delete;

		enum Textures : int { Player };
		static ResourceManager<sf::Texture, int> textures;

		enum PlayerInputs : int { Up, Left, Right };
		static ActionMap<int> playerInputs;

		static void Initialize();

	private:
		static void InitTextures();
		static void InitPlayerInputs();
};

