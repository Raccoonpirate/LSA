#include <utility>
#include <iostream>

#include "Player.hpp"

Player::Player() 
	: ActionTarget {Configuration::playerInputs} {
	
	bind(Configuration::PlayerInputs::Up, [this] (const sf::Event&) {
		_spaceship->Accelerate(sf::Vector2f(0.f, -200.f));
	});

	bind(Configuration::PlayerInputs::Left, [this] (const sf::Event&) {
		_spaceship->Accelerate(sf::Vector2f(-200.f, 0.f));
	});

	bind(Configuration::PlayerInputs::Right, [this] (const sf::Event&) {
		_spaceship->Accelerate(sf::Vector2f(200.f, 0.f));
	});

	bind(Configuration::PlayerInputs::Down, [this] (const sf::Event&) {
		_spaceship->Accelerate(sf::Vector2f(0.f, 200.f));
	});
	
	bind(Configuration::PlayerInputs::Shoot, [this] (const sf::Event&) {
		//_spaceship->Accelerate(sf::Vector2f(0.f, 200.f));
		_spaceship->Fire();
	});
	
	bind(Configuration::PlayerInputs::Missile, [this] (const sf::Event&) {
		//_spaceship->Accelerate(sf::Vector2f(0.f, 200.f));
		_spaceship->LaunchMissile();
	});
}

void Player::RealTimeEvents() {
	ActionTarget::RealTimeEvents();
}

void Player::PollEvents(const sf::Event& event) {
	ActionTarget::PollEvents(event);
}

void Player::SetSpaceship(Spacecraft* spaceship) {
	_spaceship = spaceship;
}