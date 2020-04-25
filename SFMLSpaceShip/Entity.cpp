#include "Entity.hpp"

void Entity::SetVelocity(sf::Vector2f velocity) {
	_velocity = velocity;
}

void Entity::SetVelocity(float vx, float vy) {
	_velocity.x = vx;
	_velocity.y = vy;
}

sf::Vector2f Entity::GetVelocity() const {
	return _velocity;
}

void Entity::UpdateCurrent(sf::Time dt) {
	move(_velocity * dt.asSeconds());
}