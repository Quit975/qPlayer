#pragma once
#include "widget.h"

namespace gui {
	class SpriteWidget : public gui::Widget
	{
	private:
		sf::Sprite& m_sprite_noHover;
		sf::Sprite& m_sprite_hover;
		sf::Sprite& m_sprite_click;
		sf::Sprite* mp_currentSprite;

	public:
		SpriteWidget(sf::Vector2f pos, Task task, sf::Sprite& noHover, sf::Sprite& hover, sf::Sprite& click):
			Widget(pos, task),
			m_sprite_noHover{noHover},
			m_sprite_hover{hover},
			m_sprite_click{click},
			mp_currentSprite{&m_sprite_noHover} {}

		virtual ~SpriteWidget() {}
	};
}
