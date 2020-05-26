#pragma once

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

#include "Configuration.hpp"
#include "SceneNode.hpp"
#include "Spacecraft.hpp"
#include "Player.hpp"

class World {
	public:
		explicit World(sf::RenderWindow& window);

		World(const World&) = delete;
		World& operator=(const World&) = delete;

		void HandleEvent(const sf::Event& event);
		void Update(sf::Time dt);
		void Draw();

	private:
		void BuildScene();
		void CorrectPlayerPosition();
		void CorrectPlayerVelocity();
		void AddEnemies();
		void AddEnemy(SpacecraftTypes type, float relX, float relY);
		void SpawnEnemies();

		sf::FloatRect GetViewBounds() const;
		sf::FloatRect GetBattlefieldBounds() const;
		
		enum Layer {
			Background,
			Air,
			LayerCount
		};

		struct SpawnPoint {
			SpawnPoint(SpacecraftTypes m_type, float m_x, float m_y)
				: type {m_type}
				, x {m_x}
				, y {m_y} {
			}

			SpacecraftTypes type;
			float x;
			float y;
		};

		sf::RenderWindow& _window;
		sf::View _worldView;
		sf::FloatRect _worldBounds;
		sf::Vector2f _spawnPosition;

		std::array<SceneNode*, LayerCount> _sceneLayers;

		SceneNode _sceneGraph;
		Player _player;
		const Textures _textures;
		float _scrollSpeed;
		Spacecraft* _playerSpacecraft;

		std::vector<SpawnPoint> _enemySpawnPoints;
		std::vector<Spacecraft*> _enemies;
};

