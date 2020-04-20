#include "Label.hpp"

Label::Label(const std::string& text, Widget* parent) : Widget(parent) {
	_text.setFont(Configuration::fonts.Get(Configuration::Fonts::Gui));

	SetText(text);
	SetTextColor(sf::Color(180, 93, 23));
}

Label::~Label() {
}

void Label::SetText(const std::string& text) {
	_text.setString(text);
	UpdateShape();
}

void Label::SetCharacterSize(unsigned int size) {
	_text.setCharacterSize(size);
	UpdateShape();
}

unsigned int Label::GetCharacterSize()const {
	return _text.getCharacterSize();
}

void Label::SetTextColor(const sf::Color& color) {
	_text.setFillColor(color);
}

sf::Vector2f Label::GetSize()const {
	sf::FloatRect rect = _text.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}

void Label::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.translate(_position);
	target.draw(_text, states);
}