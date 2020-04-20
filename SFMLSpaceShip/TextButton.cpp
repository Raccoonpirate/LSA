#include "TextButton.hpp"

TextButton::TextButton(const std::string& text, Widget* parent) : Button(parent), _label(text, this) {
	SetFillColor(sf::Color(86, 20, 19));
	SetOutlineThickness(5);
	SetOutlineColor(sf::Color(146, 20, 19));
}

TextButton::~TextButton() {
}

void TextButton::SetText(const std::string& text) {
	_label.SetText(text);
}

void TextButton::SetCharacterSize(unsigned int size) {
	_label.SetCharacterSize(size);
}

void TextButton::SetTextColor(const sf::Color& color) {
	_label.SetTextColor(color);
}

void TextButton::SetFillColor(const sf::Color& color) {
	_fillColor = color;
	_fillHoverColor = sf::Color(color.r * _highLightAmount,
								color.g * _highLightAmount,
							    color.b * _highLightAmount);
	_shape.setFillColor(_fillColor);
}

void TextButton::SetOutlineColor(const sf::Color& color) {
	_outlineColor = color;
	_outlineHoverColor = sf::Color(color.r * _highLightAmount,
								   color.g * _highLightAmount,
								   color.b * _highLightAmount);
	_shape.setOutlineColor(_outlineColor);
}

void TextButton::SetOutlineThickness(float thickness) {
	_shape.setOutlineThickness(thickness);
}

sf::Vector2f TextButton::GetSize() const {
	sf::FloatRect rect = _shape.getGlobalBounds();
	return sf::Vector2f(rect.width, rect.height);
}

void TextButton::UpdateShape() {
	sf::Vector2f label_size = _label.GetSize();
	unsigned int char_size = _label.GetCharacterSize();

	_shape.setSize(sf::Vector2f(char_size * 2 + label_size.x, char_size * 2 + label_size.y));
	_label.SetPosition(char_size, char_size);

	Widget::UpdateShape();
}

void TextButton::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform.translate(_position);
	target.draw(_shape, states);
	target.draw(_label, states);
}

void TextButton::onMouseEntered() {
	//const float light = 1.4;
	_shape.setOutlineColor(_outlineHoverColor);
	_shape.setFillColor(_fillHoverColor);
	/*_shape.setOutlineColor(sf::Color(_outlineColor.r * light,
									 _outlineColor.g * light,
									 _outlineColor.b * light));
	_shape.setFillColor(sf::Color(_fillColor.r * light,
								  _fillColor.g * light,
								  _fillColor.b * light));*/
}

void TextButton::onMouseLeft() {
	_shape.setOutlineColor(_outlineColor);
	_shape.setFillColor(_fillColor);
}