#include "Projectile.hpp"

const std::map<ProjectileTypes, ProjectileData> Table = InitializeProjectileData();

sf::Vector2f Normalize(const sf::Vector2f& v) {
	float mag = sqrtf((v.x * v.x) + (v.y * v.y));
	return sf::Vector2f(v.x / mag, v.y / mag);
}

Projectile::Projectile(ProjectileTypes type, const sf::Texture& texture)
	: Entity {1}
	, _type {type}
	, _sprite {Configuration::textures.Get(Table.at(type).texture)}
	, _targetDirection {} {

	sf::FloatRect bounds = _sprite.getLocalBounds();
	_sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Projectile::GuideTowards(sf::Vector2f position) {
	if (IsGuided()) {
		_targetDirection = Normalize(position - GetWorldPosition());
	}
}

bool Projectile::IsGuided() const {
	return _type == ProjectileTypes::Missile;
}

void Projectile::UpdateCurrent(sf::Time dt) {
	if (IsGuided()) {
		const float approachRate = 200.f;

		sf::Vector2f newVelocity = Normalize(approachRate * dt.asSeconds() * _targetDirection + GetVelocity());
		newVelocity *= GetMaxSpeed();
		float angle = std::atan2(newVelocity.y, newVelocity.x);

		setRotation((angle * 180.f) / M_PI + 90.f);
		SetVelocity(newVelocity);
	}

	Entity::UpdateCurrent(dt);
}

void Projectile::DrawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_sprite, states);
}

unsigned int Projectile::GetCategory() const {
	return (_type == ProjectileTypes::EnemyBullet) ? ((unsigned int) SceneNodeType::EnemyProjectile) : ((unsigned int) SceneNodeType::AlliedProjectile);
}

sf::FloatRect Projectile::GetBoundingRect() const {
	return GetWorldTransform().transformRect(_sprite.getGlobalBounds());
}

float Projectile::GetMaxSpeed() const {
	return Table.at(_type).speed;
}

int Projectile::GetDamage() const {
	return Table.at(_type).damage;
}
