#pragma once

#include "Configuration.hpp"
#include "Widget.hpp"

class Label : public Widget {
	public:
		//Label(const Label&) = delete;
		//Label& operator=(const Label&) = delete;

		Label(const std::string& text, Widget* parent = nullptr);

		virtual ~Label();

		void SetText(const std::string& text);
		void SetTextColor(const sf::Color& color);
		void SetCharacterSize(unsigned int size);
		unsigned int GetCharacterSize()const;

		virtual sf::Vector2f GetSize()const override;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::Text _text;
};