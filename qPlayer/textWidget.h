#pragma once
#include "widget.h"

namespace gui {
	class TextWidget : public gui::Widget
	{
	private:
		sf::Text m_text;

	public:
		TextWidget(sf::Vector2f pos, Task task, sf::Font& font) :
			Widget(pos, task) {
			m_text.setFont(font);
		}

		~TextWidget() {}
	};
}
