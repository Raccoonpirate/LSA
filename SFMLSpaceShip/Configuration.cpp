#include "Configuration.hpp"

ResourceManager<sf::Texture, int> Configuration::textures;
ActionMap<int> Configuration::playerInputs;

void Configuration::Initialize() {
	InitTextures();
	InitPlayerInputs();
}

void Configuration::InitTextures() {
	textures.Load(Textures::Player, "assets/player/ShipSprite.png");
}

void Configuration::InitPlayerInputs() {
	playerInputs.map(PlayerInputs::Up,	  Action(sf::Keyboard::Up));
	playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
	playerInputs.map(PlayerInputs::Left,  Action(sf::Keyboard::Left));
}