#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Spacecraft.hpp"

/*Textures toTextureID(Aircraft::Type type) {
	switch (type) {
		case Aircraft::Eagle:
			return Textures::Eagle;

		case Aircraft::Raptor:
			return Textures::Raptor;
	}
	return Textures::Eagle;
}*/

//Aircraft::Aircraft(Type type, const TextureHolder& textures)
//	: mType(type)
//	, mSprite(textures.get(toTextureID(type))) {
//	sf::FloatRect bounds = mSprite.getLocalBounds();
//	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
//}

//Aircraft::Aircraft(Type type) : _type(type) {
//	_sprite.setTexture(Configuration::textures.Get(toTextureID(_type)));
//}

Spacecraft::Spacecraft(const Textures & texture) : _sprite(Configuration::textures.Get(texture)) {
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

Spacecraft::Spacecraft(const sf::Texture & texture) : _sprite(texture) {
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Spacecraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
