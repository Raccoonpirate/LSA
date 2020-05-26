#pragma once

#include <SFML/Graphics.hpp>

#include "ActionTarget.hpp"
#include "Spacecraft.hpp"

class Player : public ActionTarget<int> {
	public:
		Player(const Player&) = delete;
		Player& operator=(const Player&) = delete;

		Player();

		template<typename ... Args>
		void SetPosition(Args&& ... args);

		void PollEvents(const sf::Event& event);
		void RealTimeEvents();

		void SetSpaceship(Spacecraft* spaceship);

	private:
		Spacecraft* _spaceship;
};

template<typename ...Args>
void Player::SetPosition(Args && ...args) {
	// Now we can use both setPosition method from sf::Transformable
	//_ship.setPosition(std::forward<Args>(args)...);
}
