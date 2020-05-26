#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include "Spacecraft.hpp"

//const std::vector<SpacecraftData> Table = InitializeSpacecraftData();

//const std::map<int, SpacecraftData> hui = test();
//const std::map<SpacecraftTypes, SpacecraftData> hui = test();

const std::map<SpacecraftTypes, SpacecraftData> Table = InitializeSpacecraftData();
/*
Spacecraft::Spacecraft(const Textures & texture) : _sprite(Configuration::textures.Get(texture)) {
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}*/

Spacecraft::Spacecraft(SpacecraftTypes type)
	: _type {type}
	, Entity {Table.at(type).hitpoints}
	, _sprite {Configuration::textures.Get(Table.at(type).texture)} {
	
	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

float Spacecraft::GetMaxSpeed() const {
	return Table.at(_type).speed;
}

void Spacecraft::Fire() {
	// Only ships with fire interval != 0 are able to fire
	if (Table.at(_type).fireRate != sf::Time::Zero) {
		_isFiring = true;
	}
}

void Spacecraft::LaunchMissile() {
	if (_missileAmmo > 0) {
		_isLaunchingMissile = true;
		--_missileAmmo;
	}
}

bool Spacecraft::IsAllied() const {
	return _type == SpacecraftTypes::Eagle;
}

void Spacecraft::UpdateCurrent(sf::Time dt) {
	// Entity has been destroyed: Possibly drop pickup, mark for removal
	//if (isDestroyed()) {
	//	checkPickupDrop(commands);
	//
	//	mIsMarkedForRemoval = true;
	//	return;
	//}

	// Check if bullets or missiles are fired
	//CheckProjectileLaunch(dt, commands);

	// Update enemy movement pattern; apply velocity
	UpdateMovement(dt);
	Entity::UpdateCurrent(dt);

	// Update texts
	//UpdateTexts();
}

void Spacecraft::CheckProjectileLaunch(sf::Time dt) {
	// Enemies try to fire all the time
	if (!IsAllied())
		Fire();

	// Check for automatic gunfire, allow only in intervals
	if (_isFiring && _fireRate <= sf::Time::Zero) {
		// Interval expired: We can fire a new bullet
		_fireRate += Table.at(_type).fireRate / (_fireRateLevel + 1.f);
		_isFiring = false;
	} else if (_fireRate > sf::Time::Zero) {
		// Interval not expired: Decrease it further
		_fireRate -= dt;
		_isFiring = false;
	}

	if (_isLaunchingMissile) {
		_isLaunchingMissile = false;
	}
}

void Spacecraft::UpdateMovement(sf::Time dt) {
	// Enemy airplane: Movement pattern
	const std::vector<Direction>& directions = Table.at(_type).directions;
	if (!directions.empty()) {
		// Moved long enough in current direction: Change direction
		if (_travelledDistance > directions[_directionIndex].distance) {
			_directionIndex = (_directionIndex + 1) % directions.size();
			_travelledDistance = 0.f;
		}

		// Compute velocity from direction
		float radians = (directions[_directionIndex].angle + 90.f) * M_PI / 180.f;
		float vx = GetMaxSpeed() * std::cos(radians);
		float vy = GetMaxSpeed() * std::sin(radians);

		SetVelocity(vx, vy);

		_travelledDistance += GetMaxSpeed() * dt.asSeconds();
	}
}

void Spacecraft::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}
