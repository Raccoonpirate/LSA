#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"

class Spacecraft : public Entity {
	public:
		//enum Type {
		//	Eagle,
		//	Raptor,
		//};

		Spacecraft(const Textures& texture);
		Spacecraft(const sf::Texture& texture);

	private:
		virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
		
		sf::Sprite _sprite;
};

