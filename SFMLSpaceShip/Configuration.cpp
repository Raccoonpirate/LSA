#include "Configuration.hpp"

//ResourceManager<sf::Font, int> Configuration::fonts;
//ResourceManager<sf::Texture, int> Configuration::textures;
ResourceManager<sf::Font, Fonts> Configuration::fonts;
ResourceManager<sf::Music, int> Configuration::musics;
ResourceManager<sf::Texture, Textures> Configuration::textures;
ResourceManager<sf::SoundBuffer, int> Configuration::sounds;

ActionMap<int> Configuration::guiInputs;
ActionMap<int> Configuration::playerInputs;

void Configuration::Initialize() {
	InitTextures();
	InitFonts();
	InitSounds();
	InitMusics();

	InitPlayerInputs();
	InitGuiInputs();
}

void Configuration::InitTextures() {
	textures.Load(Textures::Eagle,  "assets/textures/spaceships/1.png");
	textures.Load(Textures::Raptor, "assets/textures/spaceships/2.png");
}

void Configuration::InitFonts() {
	fonts.Load(Fonts::Gui, "assets/fonts/trs-million.ttf");
}

void Configuration::InitSounds() {
}

void Configuration::InitMusics() {
}

void Configuration::InitPlayerInputs() {
	playerInputs.map(PlayerInputs::Up,	  Action(sf::Keyboard::Up));
	playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
	playerInputs.map(PlayerInputs::Left,  Action(sf::Keyboard::Left));
}

void Configuration::InitGuiInputs() {
	guiInputs.map(GuiInputs::Escape, Action(sf::Keyboard::Escape, Action::Type::Pressed));
}