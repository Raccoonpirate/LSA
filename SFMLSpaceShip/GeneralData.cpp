#include "GeneralData.hpp"

std::map<SpacecraftTypes, SpacecraftData> InitializeSpacecraftData() {
	// TODO: load data from external XML or YAML file
	std::map<SpacecraftTypes, SpacecraftData> dataMap;

	dataMap[SpacecraftTypes::Eagle].hitpoints = 100;
	dataMap[SpacecraftTypes::Eagle].speed = 200.f;
	dataMap[SpacecraftTypes::Eagle].texture = Textures::Eagle;
	dataMap[SpacecraftTypes::Eagle].fireRate = sf::seconds(1);
	
	dataMap[SpacecraftTypes::UFO].hitpoints = 20;
	dataMap[SpacecraftTypes::UFO].speed = 80.f;
	dataMap[SpacecraftTypes::UFO].texture = Textures::UFO;
	dataMap[SpacecraftTypes::UFO].fireRate = sf::seconds(1);
	dataMap[SpacecraftTypes::UFO].directions.push_back(Direction(+45.f, 80.f));
	dataMap[SpacecraftTypes::UFO].directions.push_back(Direction(-45.f, 160.f));
	dataMap[SpacecraftTypes::UFO].directions.push_back(Direction(+45.f, 80.f));

	dataMap[SpacecraftTypes::Raptor].hitpoints = 20;
	dataMap[SpacecraftTypes::Raptor].speed = 80.f;
	dataMap[SpacecraftTypes::Raptor].texture = Textures::Raptor;
	dataMap[SpacecraftTypes::Raptor].fireRate = sf::Time::Zero;
	dataMap[SpacecraftTypes::Raptor].directions.push_back(Direction(+45.f,  80.f));
	dataMap[SpacecraftTypes::Raptor].directions.push_back(Direction(-45.f, 160.f));
	dataMap[SpacecraftTypes::Raptor].directions.push_back(Direction(+45.f,  80.f));

	/*dataMap[SpacecraftTypes::Avenger].hitpoints = 40;
	dataMap[SpacecraftTypes::Avenger].speed = 50.f;
	dataMap[SpacecraftTypes::Avenger].texture = Textures::Avenger;
	dataMap[SpacecraftTypes::Avenger].fireInterval = sf::seconds(2);
	dataMap[SpacecraftTypes::Avenger].directions.push_back(Direction(+45.f,  50.f));
	dataMap[SpacecraftTypes::Avenger].directions.push_back(Direction(  0.f,  50.f));
	dataMap[SpacecraftTypes::Avenger].directions.push_back(Direction(-45.f, 100.f));
	dataMap[SpacecraftTypes::Avenger].directions.push_back(Direction(  0.f,  50.f));
	dataMap[SpacecraftTypes::Avenger].directions.push_back(Direction(+45.f,  50.f));*/

	return dataMap;
}

std::map<ProjectileTypes, ProjectileData> InitializeProjectileData() {
	std::map<ProjectileTypes, ProjectileData> dataMap;

	dataMap[ProjectileTypes::AlliedBullet].damage = 10;
	dataMap[ProjectileTypes::AlliedBullet].speed = 300.f;
	dataMap[ProjectileTypes::AlliedBullet].texture = Textures::PlayerBullet;

	dataMap[ProjectileTypes::UfoBullet].damage = 10;
	dataMap[ProjectileTypes::UfoBullet].speed = 300.f;
	dataMap[ProjectileTypes::UfoBullet].texture = Textures::UfoBolt;

	dataMap[ProjectileTypes::Missile].damage = 200;
	dataMap[ProjectileTypes::Missile].speed = 150.f;
	dataMap[ProjectileTypes::Missile].texture = Textures::Missile;

	return dataMap;
}

/*std::vector<PickupData> initializePickupData() {
	std::vector<PickupData> data(Pickup::TypeCount);

	data[Pickup::HealthRefill].texture = Textures::HealthRefill;
	data[Pickup::HealthRefill].action = [] (Spacecraft& a) { a.repair(25); };

	data[Pickup::MissileRefill].texture = Textures::MissileRefill;
	data[Pickup::MissileRefill].action = std::bind(&Spacecraft::collectMissiles, _1, 3);

	data[Pickup::FireSpread].texture = Textures::FireSpread;
	data[Pickup::FireSpread].action = std::bind(&Spacecraft::increaseSpread, _1);

	data[Pickup::FireRate].texture = Textures::FireRate;
	data[Pickup::FireRate].action = std::bind(&Spacecraft::increaseFireRate, _1);

	return data;
}*/