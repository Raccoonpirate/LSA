#include "World.hpp"

World::World(sf::RenderWindow& window)
	: _window {window}
	, _worldView {window.getDefaultView()}
	, _textures {}
	, _sceneGraph {}
	, _sceneLayers {}
	, _worldBounds {0.f, 0.f, _worldView.getSize().x, 2000.f}
	, _spawnPosition{_worldView.getSize().x / 2.f, _worldBounds.height - _worldView.getSize().y / 2.f}
	, _scrollSpeed {-50.f}
	, _playerSpacecraft {nullptr}
	, _player {}
	, _enemies {}
	, _enemySpawnPoints {} {
	
	BuildScene();
	//_worldBounds = sf::FloatRect (0.f, 0.f, _worldView.getSize().x, 2000.f);
	_worldView.setCenter(_spawnPosition);
}

void World::HandleEvent(const sf::Event& event) {
	_playerSpacecraft->SetVelocity(0.f, 0.f);
	
	_player.PollEvents(event);
	_player.RealTimeEvents();

	CorrectPlayerVelocity();
}

void World::Update(sf::Time dt) {
	// Scroll the world
	_worldView.move(0.f, _scrollSpeed * dt.asSeconds());

	_sceneGraph.Update(dt);
	_playerSpacecraft->Update(dt);

	SpawnEnemies();

	CorrectPlayerPosition();
}

void World::Draw() {
	_window.setView(_worldView);
	_window.draw(_sceneGraph);
}

void World::BuildScene() {
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i) {
		SceneNode::Ptr layer(new SceneNode());
		_sceneLayers[i] = layer.get();

		_sceneGraph.AttachChild(std::move(layer));
	}

	//std::unique_ptr<Spacecraft> player(new Spacecraft(SpacecraftTypes::Eagle, Configuration::textures.Get(Textures::Eagle)));
	std::unique_ptr<Spacecraft> player(new Spacecraft(SpacecraftTypes::Eagle));
	_playerSpacecraft = player.get();
	_playerSpacecraft->setPosition(_spawnPosition);
	_playerSpacecraft->SetVelocity(0.f, 0.f);
	_sceneLayers[Air]->AttachChild(std::move(player));
	_player.SetSpaceship(_playerSpacecraft);

	AddEnemies();
}

void World::CorrectPlayerPosition() {
	// Keep player's position inside the screen bounds, at least borderDistance units from the border
	sf::FloatRect viewBounds(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
	const float borderDistance = 40.f;

	sf::Vector2f position = _playerSpacecraft->getPosition();
	position.x = std::max(position.x, viewBounds.left + borderDistance);
	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
	position.y = std::max(position.y, viewBounds.top + borderDistance);
	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
	_playerSpacecraft->setPosition(position);
}

void World::CorrectPlayerVelocity() {
	sf::Vector2f velocity = _playerSpacecraft->GetVelocity();

	// If moving diagonally, reduce velocity (to have always same velocity)
	if ((velocity.x != 0.f) && (velocity.y != 0.f)) {
		_playerSpacecraft->SetVelocity(velocity / std::sqrt(2.f));
	}
}

void World::AddEnemies() {
	// Add enemies to the spawn point container
	//AddEnemy(SpacecraftTypes::Raptor, 0.f, 500.f);
	//AddEnemy(SpacecraftTypes::Raptor, 0.f, 1000.f);
	//AddEnemy(SpacecraftTypes::Raptor, +100.f, 1100.f);
	//AddEnemy(SpacecraftTypes::Raptor, -100.f, 1100.f);
	AddEnemy(SpacecraftTypes::UFO, 0.f, 500.f);
	AddEnemy(SpacecraftTypes::UFO, 0.f, 1000.f);
	AddEnemy(SpacecraftTypes::UFO, +100.f, 1100.f);
	AddEnemy(SpacecraftTypes::UFO, -100.f, 1100.f);
	//AddEnemy(SpacecraftTypes::Avenger, -70.f, 1400.f);
	//AddEnemy(SpacecraftTypes::Avenger, -70.f, 1600.f);
	//AddEnemy(SpacecraftTypes::Avenger, 70.f, 1400.f);
	//AddEnemy(SpacecraftTypes::Avenger, 70.f, 1600.f);

	// Sort all enemies according to their y value, such that lower enemies are checked first for spawning
	std::sort(_enemySpawnPoints.begin(), _enemySpawnPoints.end(), [] (SpawnPoint lhs, SpawnPoint rhs) {
		return lhs.y < rhs.y;
	});
}

void World::AddEnemy(SpacecraftTypes type, float relX, float relY) {
	SpawnPoint spawn(type, _spawnPosition.x + relX, _spawnPosition.y - relY);
	_enemySpawnPoints.push_back(spawn);
}

void World::SpawnEnemies() {
	// Spawn all enemies entering the view area (including distance) this frame
	while (!_enemySpawnPoints.empty() && (_enemySpawnPoints.back().y > GetBattlefieldBounds().top)) {
		SpawnPoint spawn = _enemySpawnPoints.back();
		
		//std::unique_ptr<Spacecraft> enemy(new Spacecraft(spawn.type, Configuration::textures.Get(Textures::Eagle)));
		std::unique_ptr<Spacecraft> enemy(new Spacecraft(spawn.type));
		enemy->setPosition(spawn.x, spawn.y);
		enemy->setRotation(180.f);

		_sceneLayers[Air]->AttachChild(std::move(enemy));

		// Enemy spawn point is used, remove from the list
		_enemySpawnPoints.pop_back();
	}
}

sf::FloatRect World::GetViewBounds() const {
	return sf::FloatRect(_worldView.getCenter() - _worldView.getSize() / 2.f, _worldView.getSize());
}

sf::FloatRect World::GetBattlefieldBounds() const {
	sf::FloatRect viewBounds = GetViewBounds();
	viewBounds.top -= 100.f;
	viewBounds.height += 100.f;

	return viewBounds;
}
