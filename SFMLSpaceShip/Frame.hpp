#pragma once

#include "Container.hpp"
#include "ActionTarget.hpp"

class Frame : public Container, protected ActionTarget<int> {
	public:
		//Frame(const Frame&) = delete;
		//Frame& operator=(const Frame&) = delete;

		using ActionTarget<int>::FuncType;

		Frame(sf::RenderWindow& window);

		virtual ~Frame();

		void ProcessEvents();
		bool ProcessEvent(const sf::Event& event);

		void bind(int key, const FuncType& callback);
		void unbind(int key);

		void draw();

		virtual sf::Vector2f GetSize()const override;

	private:
		virtual bool ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;
		virtual void ProcessEvents(const sf::Vector2f& parent_pos)override;

		sf::RenderWindow& _window;
};