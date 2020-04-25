#pragma once

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

#include "Configuration.hpp"
#include "SceneNode.hpp"
//#include "SpriteNode.hpp"
#include "Spacecraft.hpp"

class World {
	public:
	explicit World(sf::RenderWindow& window);

	World(const World&) = delete;
	World& operator=(const World&) = delete;

	void Update(sf::Time dt);
	void Draw();

	private:
		void LoadTextures();
		void BuildScene();
		
		enum Layer {
			Background,
			Air,
			LayerCount
		};

	sf::RenderWindow& _window;
	sf::View _worldView;
	sf::FloatRect _worldBounds;
	sf::Vector2f _spawnPosition;

	std::array<SceneNode*, LayerCount> _sceneLayers;

	SceneNode _sceneGraph;
	const Textures _textures;
	float _scrollSpeed;
	Spacecraft* _playerSpacecraft;
};

