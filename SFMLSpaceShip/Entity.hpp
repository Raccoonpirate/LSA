#pragma once

#include <SFML/Graphics.hpp>

#include "Configuration.hpp"
#include "SceneNode.hpp"

class Entity : public SceneNode {
	public:
		void SetVelocity (sf::Vector2f velocity);
		void SetVelocity (float vx, float vy);
		sf::Vector2f GetVelocity() const;

	private:
		virtual void UpdateCurrent(sf::Time dt) override;
		
		sf::Vector2f _velocity;
};