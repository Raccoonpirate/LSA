#pragma once

#include <vector>
#include "Layout.hpp"

class VLayout : public Layout {
	public:
		VLayout(const VLayout&) = delete;
		VLayout& operator=(const VLayout&) = delete;

		VLayout(Widget* parent = nullptr);
		~VLayout();

		void add(Widget* widget);
		Widget* at(unsigned int index)const;

		virtual sf::Vector2f GetSize()const override;

	protected:
		virtual bool ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos) override;
		virtual void ProcessEvents(const sf::Vector2f& parent_pos) override;

	private:
		virtual void UpdateShape() override;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		std::vector<Widget*> _widgets;
};

