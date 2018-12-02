#pragma once
#include "core.h"
#include <SFML/Graphics.hpp>
#include "task.h"

namespace gui {

	class Widget : public sf::Drawable, public sf::Transformable
	{
	protected:
		sf::Vector2f m_pos;
		sf::Vector2f m_size;
		Operation m_op;
		bool m_hover;

	public:
		Widget(sf::Vector2f pos, sf::Vector2f size, Operation op) : m_pos{ pos }, m_size{ size }, m_op{ op }, m_hover{ false } {}
		virtual ~Widget() {}

		virtual Task click() { return Task(m_op); }
		sf::Vector2f pos() { return m_pos; }
		sf::Vector2f size() { return m_size; }

		virtual void setHover(bool hov) { m_hover = hov; }
		bool isMouseOver(sf::Vector2i mpos) {
			if (mpos.x >= m_pos.x && mpos.x <= m_pos.x + m_size.x && mpos.y >= m_pos.y && mpos.y <= m_pos.y + m_size.y) {
				setHover(true);
				return true;
			}
			else {
				setHover(false);
				return false;
			}
		}

		virtual void update() {}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	};
}

