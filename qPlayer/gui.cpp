#include "gui.h"

GUI::GUI():
	m_window(sf::VideoMode(200, 200), "SFML works!")
{
}

void GUI::run()
{
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_window.close();
		}

		m_window.clear();
		m_window.draw(shape);
		m_window.display();
	}
}
