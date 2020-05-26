#pragma once

#include <SFML/Graphics/Sprite.hpp>

#include "Entity.hpp"
#include "GeneralData.hpp"

class Spacecraft : public Entity {
	public:
		Spacecraft(SpacecraftTypes type);
		float GetMaxSpeed() const;
		void Fire();
		void LaunchMissile();
		bool IsAllied() const;

	private:
		void UpdateMovement(sf::Time dt);
		virtual void DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual void UpdateCurrent(sf::Time dt) override;

		void CheckProjectileLaunch(sf::Time dt);
		
		bool _isFiring;
		bool _isLaunchingMissile;

		sf::Time _fireRate;
		sf::Sprite _sprite;
		SpacecraftTypes _type;
		float _travelledDistance;
		std::size_t _directionIndex;

		int _fireRateLevel;
		int _spreadLevel;
		int _missileAmmo;
};

