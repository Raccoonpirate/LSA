#pragma once

#include <functional>
#include "Widget.hpp"

class Button : public Widget {
	public:
		//Button(const Button&) = delete;
		//Button& operator=(const Button&) = delete;

		using FuncType = std::function<void(const sf::Event& event, Button& self)>;
		static FuncType emptyFunction;

		Button(Widget* parent = nullptr);
		virtual ~Button();

		FuncType onClick;

	protected:
		virtual bool ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos)override;

		virtual void onMouseEntered();
		virtual void onMouseLeft();

		private:
		enum Status {
			None = 0,
			Hover
		};

		int _status;
};