#include "Button.hpp"

Button::FuncType Button::emptyFunction = [] (const sf::Event&, Button&)->void {};

Button::Button(Widget* parent) : Widget(parent), onClick(emptyFunction), _status(Status::None) {
}

Button::~Button() {
}

bool Button::ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos) {
	bool res = false;
	if (event.type == sf::Event::MouseButtonReleased) {
		const sf::Vector2f pos = _position + parent_pos;
		const sf::Vector2f size = GetSize();
		sf::FloatRect rect;

		rect.left = pos.x;
		rect.top = pos.y;
		rect.width = size.x;
		rect.height = size.y;

		if (rect.contains(event.mouseButton.x, event.mouseButton.y)) {
			onClick(event, *this);
			res = true;
		}
	} else if (event.type == sf::Event::MouseMoved) {
		const sf::Vector2f pos = _position + parent_pos;
		const sf::Vector2f size = GetSize();
		sf::FloatRect rect;

		rect.left = pos.x;
		rect.top = pos.y;
		rect.width = size.x;
		rect.height = size.y;

		int old_status = _status;
		_status = Status::None;

		const sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
		if (rect.contains(mousePos)) {
			_status |= Status::Hover;
		}

		if ((old_status & Status::Hover) && !(_status & Status::Hover)) {
			onMouseLeft();
		} else if (!(old_status & Status::Hover) && (_status & Status::Hover)) {
			onMouseEntered();
		}

	}
	return res;
}

void Button::onMouseEntered() {
}

void Button::onMouseLeft() {
}