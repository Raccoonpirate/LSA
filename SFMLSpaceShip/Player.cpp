#include <utility>
#include "Player.hpp"

Player::Player() : ActionTarget(Configuration::playerInputs) {
	_ship.setTexture(Configuration::textures.Get(Configuration::Textures::Player));
	_ship.setOrigin(32.f, 32.f);

	bind(Configuration::PlayerInputs::Up, [this] (const sf::Event&) {
		_isMoving = true;
	});

	bind(Configuration::PlayerInputs::Left, [this] (const sf::Event&) {
		_rotation -= 1;
	});

	bind(Configuration::PlayerInputs::Right, [this] (const sf::Event&) {
		_rotation += 1;
	});
}

void Player::ProcessEvents() {
	_rotation = 0;
	_isMoving = false;
	ActionTarget::RealTimeEvents();
}

void Player::Update(sf::Time dt) {
	float seconds = dt.asSeconds();

	if (_rotation) {
		float angle = _rotation * 180 * seconds;
		_ship.rotate(angle);
	}
	if (_isMoving) {
		float angle = _ship.getRotation() / 180.f * M_PI - M_PI / 2.f;
		_velocity += sf::Vector2f(cos(angle), sin(angle)) * 60.f * seconds;
	}

	_ship.move(seconds * _velocity);
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(_ship, states);
}