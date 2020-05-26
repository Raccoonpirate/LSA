#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "GeneralData.hpp"
#include "ProjectileTypes.hpp"

class Projectile : public Entity {
	public:
		Projectile(ProjectileTypes type, const sf::Texture& textures);

		void GuideTowards(sf::Vector2f position);
		bool IsGuided() const;

		virtual unsigned int GetCategory() const;
		virtual sf::FloatRect GetBoundingRect() const;
		float GetMaxSpeed() const;
		int GetDamage() const;

	private:
		virtual void UpdateCurrent(sf::Time dt);
		virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

		ProjectileTypes _type;
		sf::Sprite _sprite;
		sf::Vector2f _targetDirection;
};

