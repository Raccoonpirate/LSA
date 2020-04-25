#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.hpp"
#include "ActionMap.hpp"

enum class Fonts : int { Gui };

enum class Textures : int { Player, Eagle, Raptor, Desert };

class Configuration {
	public:
		Configuration() = delete;
		Configuration(const Configuration&) = delete;
		Configuration& operator=(const Configuration&) = delete;

		//enum Fonts : int { Gui };
		//static ResourceManager<sf::Font, int> fonts;

		static ResourceManager<sf::Font, Fonts> fonts;

		enum GuiInputs : int {
			Escape,
		};
		static ActionMap<int> guiInputs;

		enum Sounds : int {
			Spawn,
			Explosion,
			LevelUp,
		};
		static ResourceManager<sf::SoundBuffer, int> sounds;

		enum Musics : int {
			Theme
		};
		static ResourceManager<sf::Music, int> musics;

		//enum Textures : int { Player };
		//static ResourceManager<sf::Texture, int> textures;
		
		static ResourceManager<sf::Texture, Textures> textures;

		enum PlayerInputs : int { Up, Left, Right };
		static ActionMap<int> playerInputs;

		static void Initialize();

	private:
		static void InitTextures();
		static void InitFonts();
		static void InitSounds();
		static void InitMusics();

		static void InitPlayerInputs();
		static void InitGuiInputs();
};

