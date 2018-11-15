#include "window.h"

gui::Window::Window():
	m_window(sf::VideoMode(400, 200), "qPlayer"),
	m_closureRequested{false}
{
	DEBUG("Window created");
}

gui::Window::~Window()
{
	m_window.close();
	DEBUG("Window destroyed");
}

void gui::Window::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			DEBUG("Closure requested");
			m_closureRequested = true;
		}
	}
}

void gui::Window::draw()
{
	m_window.clear();
	m_window.display();
}
