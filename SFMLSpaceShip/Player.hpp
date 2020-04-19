#pragma once

#include <SFML/Graphics.hpp>

#include "Configuration.hpp"
#include "ActionTarget.hpp"

class Player : public sf::Drawable, public ActionTarget<int> {
	public:
		Player(const Player&) = delete;
		Player& operator=(const Player&) = delete;

		Player();

		template<typename ... Args>
		void SetPosition(Args&& ... args);

		void ProcessEvents();

		void Update(sf::Time dt);

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		bool _isMoving {false};
		int _rotation {0};
		
		sf::Vector2f _velocity;
		sf::Sprite _ship;
};

template<typename ...Args>
void Player::SetPosition(Args && ...args) {
	// Now we can use both setPosition method from sf::Transformable
	_ship.setPosition(std::forward<Args>(args)...);
}
