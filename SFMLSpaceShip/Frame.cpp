#include "Frame.hpp"
#include "Configuration.hpp"

Frame::Frame(sf::RenderWindow& window) : Container(nullptr), ActionTarget(Configuration::guiInputs), _window(window) {
}

Frame::~Frame() {
}

void Frame::draw() {
	_window.draw(*this);
}

void Frame::ProcessEvents() {
	sf::Vector2f parent_pos(0, 0);
	ProcessEvents(parent_pos);
}

bool Frame::ProcessEvent(const sf::Event& event) {
	sf::Vector2f parent_pos(0, 0);
	return ProcessEvent(event, parent_pos);
}

void Frame::bind(int key, const FuncType& callback) {
	ActionTarget::bind(key, callback);
}

void Frame::unbind(int key) {
	ActionTarget::unbind(key);
}

sf::Vector2f Frame::GetSize()const {
	sf::Vector2u size = _window.getSize();
	return sf::Vector2f(size.x, size.y);
}

bool Frame::ProcessEvent(const sf::Event& event, const sf::Vector2f& parent_pos) {
	bool res = ActionTarget::PollEvents(event);
	if (!res)
		res = Container::ProcessEvent(event, parent_pos);
	return res;
}

void Frame::ProcessEvents(const sf::Vector2f& parent_pos) {
	ActionTarget::RealTimeEvents();
	Container::ProcessEvents(parent_pos);

	sf::Event event;
	while (_window.pollEvent(event)) {
		Container::ProcessEvent(event, parent_pos);
	}
}