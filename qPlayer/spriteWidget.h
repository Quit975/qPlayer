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
		SpriteWidget(sf::Vector2f pos, sf::Vector2f size, Operation op, sf::Sprite& noHover, sf::Sprite& hover, sf::Sprite& click):
			Widget(pos, size, op),
			m_sprite_noHover{noHover},
			m_sprite_hover{hover},
			m_sprite_click{click},
			mp_currentSprite{&m_sprite_noHover} {
		
			m_sprite_click.setPosition(pos);
			m_sprite_hover.setPosition(pos);
			m_sprite_noHover.setPosition(pos);
		}

		virtual ~SpriteWidget() {}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(*mp_currentSprite);
		}

		virtual void update() {
			if (m_hover) {
				mp_currentSprite = &m_sprite_hover;
			}
			else {
				mp_currentSprite = &m_sprite_noHover;
			}
		}
	};
}
