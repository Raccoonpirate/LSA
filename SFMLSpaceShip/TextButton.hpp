#pragma once

#include "Button.hpp"
#include "Label.hpp"

class TextButton : public Button {
	public:
		//TextButton(const TextButton&) = delete;
		//TextButton& operator=(const TextButton&) = delete;

		TextButton(const std::string& text, Widget* parent = nullptr);

		virtual ~TextButton();

		void SetText(const std::string& text);
		void SetCharacterSize(unsigned int size);
		void SetTextColor(const sf::Color& color);
		
		void SetFillColor(const sf::Color& color);
		void SetOutlineColor(const sf::Color& color);
		void SetOutlineThickness(float thickness);

		virtual sf::Vector2f GetSize()const override;

	private:
		void UpdateShape()override;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		virtual void onMouseEntered()override;
		virtual void onMouseLeft()override;

		const float _highLightAmount = 1.4f;
		sf::RectangleShape _shape;
		Label _label;

		sf::Color _fillColor;
		sf::Color _outlineColor;
		sf::Color _fillHoverColor;
		sf::Color _outlineHoverColor;
};

