#pragma once

#include <SFML/Graphics.hpp>

class Widget : public sf::Drawable {
	public:
		//Widget(const Widget&) = delete;
		//Widget& operator=(const Widget&) = delete;

		Widget(Widget* parent = nullptr);
		virtual ~Widget();

		void SetPosition(const sf::Vector2f& pos);
		void SetPosition(float x, float y);
		const sf::Vector2f& GetPosition()const;
		virtual sf::Vector2f GetSize()const = 0;

	protected:
		friend class Containers;
		friend class VLayout;

		virtual bool ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos);
		virtual void ProcessEvents(const sf::Vector2f& parent_pos);

		virtual void UpdateShape();

		Widget* _parent;
		sf::Vector2f _position;
};