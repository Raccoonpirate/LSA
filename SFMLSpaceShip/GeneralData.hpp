#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <functional>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

#include "Configuration.hpp"
#include "SpacecraftTypes.hpp"
#include "ProjectileTypes.hpp"

class Spacecraft;

struct Direction {
	Direction(float angle, float distance)
		: angle {angle}
		, distance {distance} {
	}

	float angle;
	float distance;
};

struct SpacecraftData {
	int hitpoints;
	float speed;
	Textures texture;
	sf::Time fireRate;
	std::vector<Direction> directions;
};

struct ProjectileData {
	int damage;
	float speed;
	Textures texture;
};

struct PickupData {
	std::function<void(Spacecraft&)> action;
	Textures texture;
};

std::map<SpacecraftTypes, SpacecraftData> InitializeSpacecraftData();
std::map<ProjectileTypes, ProjectileData> InitializeProjectileData();

std::vector<PickupData>		InitializePickupData();
