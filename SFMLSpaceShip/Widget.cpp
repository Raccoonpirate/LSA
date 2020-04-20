#include "Widget.hpp"

Widget::Widget(Widget* parent) : _parent(parent) {
}

Widget::~Widget() {
}

void Widget::SetPosition(const sf::Vector2f& pos) {
	_position = pos;
}

void Widget::SetPosition(float x, float y) {
	_position.x = x;
	_position.y = y;
}

const sf::Vector2f& Widget::GetPosition()const {
	return _position;
}

bool Widget::ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos) {
	return false;
}

void Widget::ProcessEvents(const sf::Vector2f& parent_pos) {
}

void Widget::UpdateShape() {
	if (_parent) {
		// Propagate updateShape through GUI tree
		_parent->UpdateShape();
	}
}