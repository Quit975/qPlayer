#pragma once
#include "widget.h"

namespace gui {
	class TextWidget : public gui::Widget
	{
	private:
		sf::Text m_text;

	public:
		TextWidget(sf::Vector2f pos, Operation op, sf::Font& font) :
			Widget(pos, op) {
			m_text.setFont(font);
		}

		~TextWidget() {}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(m_text);
		}
	};
}
