#pragma once

#include "Widget.hpp"
#include "Layout.hpp"

class Container : public Widget {
	public:
		//Container(const Container&) = delete;
		//Container& operator=(const Container&) = delete;

		Container(Widget* parent = nullptr);
		virtual ~Container();

		void SetLayout(Layout* layout);
		Layout* GetLayout()const;

		virtual sf::Vector2f GetSize()const override;

	protected:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		virtual bool ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;
		virtual void ProcessEvents(const sf::Vector2f& parent_pos)override;

	private:
		Layout* _layout;

};