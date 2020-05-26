#include "Entity.hpp"

Entity::Entity(int hitpoints)
	: _velocity {}
	, _hitpoints {hitpoints} {
}

void Entity::SetVelocity(sf::Vector2f velocity) {
	_velocity = velocity;
}

void Entity::SetVelocity(float vx, float vy) {
	_velocity.x = vx;
	_velocity.y = vy;
}

void Entity::Accelerate(sf::Vector2f velocity) {
	_velocity += velocity;
}

void Entity::Accelerate(float vx, float vy) {
	_velocity.x += vx;
	_velocity.y += vy;
}

sf::Vector2f Entity::GetVelocity() const {
	return _velocity;
}

int Entity::GetHitpoints() const {
	return _hitpoints;
}

void Entity::Repair(int points) {
	_hitpoints += points;
}

void Entity::Damage(int points) {
	_hitpoints -= points;
}

void Entity::Destroy() {
	_hitpoints = 0;
}

bool Entity::IsDestroyed() const {
	return _hitpoints <= 0;
}

void Entity::UpdateCurrent(sf::Time dt) {
	move(_velocity * dt.asSeconds());
}