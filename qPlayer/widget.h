#pragma once
#include "core.h"
#include <SFML/Graphics.hpp>
#include "task.h"

namespace gui {

	class Widget
	{
	private:
		sf::Vector2f m_pos;
		Task m_task;
		bool m_hover;

	public:
		Widget(sf::Vector2f pos, Task task) : m_pos{ pos }, m_task{ task }, m_hover{ false } {}
		virtual ~Widget() {}

		virtual Task click() = 0;
		sf::Vector2f pos() { return m_pos; }

		void setHover(bool hov) { m_hover = hov; }
		virtual void update() = 0;

	};
}

