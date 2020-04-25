#include "World.hpp"

World::World(sf::RenderWindow& window)
	: _window(window)
	, _worldView(window.getDefaultView())
	, _textures()
	, _sceneGraph()
	, _sceneLayers()
	, _worldBounds(0.f, 0.f, _worldView.getSize().x, 2000.f)
	, _spawnPosition(_worldView.getSize().x / 2.f, _worldBounds.height - _worldView.getSize().y / 2.f)
	, _scrollSpeed(-50.f)
	, _playerSpacecraft(nullptr) {
	LoadTextures();
	BuildScene();
	
	// Prepare the view
	_worldView.setCenter(_spawnPosition);
}

void World::Update(sf::Time dt) {
	// Scroll the world
	_worldView.move(0.f, _scrollSpeed * dt.asSeconds());

	// Move the player sidewards (plane scouts follow the main Spacecraft)
	sf::Vector2f position = _playerSpacecraft->getPosition();
	//sf::Vector2f velocity = _playerSpacecraft->getVelocity();

	// If player touches borders, flip its X velocity
	if (position.x <= _worldBounds.left + 150.f
		|| position.x >= _worldBounds.left + _worldBounds.width - 150.f) {
		//velocity.x = -velocity.x;
		//_playerSpacecraft->setVelocity(velocity);
	}

	// Apply movements
	_sceneGraph.Update(dt);
}

void World::Draw() {
	_window.setView(_worldView);
	_window.draw(_sceneGraph);
}

void World::LoadTextures() {
	//_textures.load(Textures::Eagle, "Media/Textures/Eagle.png");
	//_textures.load(Textures::Raptor, "Media/Textures/Raptor.png");
	//_textures.load(Textures::Desert, "Media/Textures/Desert.png");
}

void World::BuildScene() {
	// Initialize the different layers
	for (std::size_t i = 0; i < LayerCount; ++i) {
		SceneNode::Ptr layer(new SceneNode());
		_sceneLayers[i] = layer.get();

		_sceneGraph.AttachChild(std::move(layer));
	}

	// Prepare the tiled background
	//sf::Texture& texture = _textures.get(Textures::Desert);
	//sf::IntRect textureRect(_worldBounds);
	//texture.setRepeated(true);

	// Add the background sprite to the scene
	//std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	//backgroundSprite->setPosition(_worldBounds.left, _worldBounds.top);
	//_sceneLayers[Background]->AttachChild(std::move(backgroundSprite));

	// Add player's Spacecraft
	//std::unique_ptr<Spacecraft> leader(new Spacecraft(Spacecraft::Eagle, _textures));
	std::unique_ptr<Spacecraft> leader(new Spacecraft(Configuration::textures.Get(Textures::Eagle)));
	_playerSpacecraft = leader.get();
	_playerSpacecraft->setPosition(_spawnPosition);
	//_playerSpacecraft->setVelocity(40.f, _scrollSpeed);
	_sceneLayers[Air]->AttachChild(std::move(leader));

	// Add two escorting Spacecrafts, placed relatively to the main plane
	std::unique_ptr<Spacecraft> leftEscort(new Spacecraft(Configuration::textures.Get(Textures::Raptor)));
	leftEscort->setPosition(-80.f, 50.f);
	_playerSpacecraft->AttachChild(std::move(leftEscort));

	std::unique_ptr<Spacecraft> rightEscort(new Spacecraft(Configuration::textures.Get(Textures::Raptor)));
	rightEscort->setPosition(80.f, 50.f);
	_playerSpacecraft->AttachChild(std::move(rightEscort));
}
