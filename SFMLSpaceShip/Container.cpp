#include "Container.hpp"

Container::Container(Widget* parent) : Widget(parent), _layout(nullptr) {
}

Container::~Container() {
	if (_layout != nullptr && _layout->_parent == this) {
		_layout->_parent = nullptr;
		delete _layout;
	}
}

void Container::SetLayout(Layout* layout) {
	if (_layout != nullptr && _layout->_parent == this) {
		_layout->_parent = nullptr;
		delete _layout;
	}

	if ((_layout = layout) != nullptr) {
		_layout->_parent = this;
		_layout->UpdateShape();
	}
}

Layout* Container::GetLayout()const {
	return _layout;
}

sf::Vector2f Container::GetSize()const {
	sf::Vector2f res(0, 0);
	if (_layout) {
		res = _layout->GetSize();
	}
	return res;
}

void Container::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	if (_layout) {
		target.draw(*_layout, states);
	}
}

bool Container::ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos) {
	bool res = false;
	if (!res && _layout) {
		res = _layout->ProcessEvent(event, parent_pos);
	}
	return res;
}

void Container::ProcessEvents(const sf::Vector2f& parent_pos) {
	if (_layout) {
		_layout->ProcessEvents(parent_pos);
	}
}