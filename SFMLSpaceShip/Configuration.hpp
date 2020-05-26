#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ResourceManager.hpp"
#include "ActionMap.hpp"

enum class Fonts : int { Gui };

enum class Textures : int {
	Eagle, Raptor, Avenger, UFO,
	MenuBackground, MenuPlanet,
	PlayerBullet, UfoBolt, Missile };

class Configuration {
	public:
		Configuration() = delete;
		Configuration(const Configuration&) = delete;
		Configuration& operator=(const Configuration&) = delete;

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

		static ResourceManager<sf::Texture, Textures> textures;

		enum PlayerInputs : int { Up, Left, Right, Down, Shoot, Missile };
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

