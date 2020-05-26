#pragma once

#include <SFML/Graphics.hpp>

#include "Configuration.hpp"
#include "SceneNode.hpp"

class Entity : public SceneNode {
	public:
		explicit Entity(int hitpoints);

		void SetVelocity (sf::Vector2f velocity);
		void SetVelocity (float vx, float vy);
		void Accelerate (sf::Vector2f velocity);
		void Accelerate (float vx, float vy);
		sf::Vector2f GetVelocity() const;

		int GetHitpoints() const;
		void Repair(int points);
		void Damage(int points);
		void Destroy();
		virtual bool IsDestroyed() const;
		
	protected:
		virtual void UpdateCurrent(sf::Time dt) override;
		
	private:
		sf::Vector2f _velocity;
		int _hitpoints;
};