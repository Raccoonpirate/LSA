#include "VLayout.hpp"

VLayout::VLayout(Widget* parent) : Layout(parent) {
}

VLayout::~VLayout() {
	for (Widget* widget : _widgets) {
		if (widget->_parent == this) {
			delete widget;
		}
	}
}

void VLayout::add(Widget* widget) {
	widget->_parent = this;
	_widgets.emplace_back(widget);
	UpdateShape();
}

Widget* VLayout::at(unsigned int index)const {
	return _widgets.at(index);
}

sf::Vector2f VLayout::GetSize()const {
	float max_x = 0;
	float y = 0;
	for (Widget* widget : _widgets) {
		sf::Vector2f size = widget->GetSize();
		if (size.x > max_x) {
			max_x = size.x;
		}
		y += _space + size.y;
	}
	return sf::Vector2f(max_x + _space * 2, y + _space);
}

bool VLayout::ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos) {
	for (Widget* widget : _widgets) {
		if (widget->ProcessEvent(event, parent_pos)) {
			return true;
		}
	}

	return false;
}

void VLayout::ProcessEvents(const sf::Vector2f& parent_pos) {
	for (Widget* widget : _widgets) {
		widget->ProcessEvents(parent_pos);
	}
}

void VLayout::UpdateShape() {
	float max_x = (_parent ? _parent->GetSize().x : 0);
	for (Widget* widget : _widgets) {
		sf::Vector2f size = widget->GetSize();
		float widget_x = size.x;

		if (widget_x > max_x) {
			max_x = widget_x;
		}
	}

	float pos_y = _space;
	if (_parent) {
		pos_y = (_parent->GetSize().y - GetSize().y) / 2.f;
	}

	for (Widget* widget : _widgets) {
		sf::Vector2f size = widget->GetSize();
		widget->SetPosition((max_x - size.x) / 2.0, pos_y);
		pos_y += size.y + _space;
	}

	Widget::UpdateShape();

}

void VLayout::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Widget* widget : _widgets) {
		target.draw(*widget, states);
	}
}