#include "eventHandler.h"

gui::EventHandler::EventHandler()
{
	DEBUG("Event handler created");
}

gui::EventHandler::~EventHandler()
{
	DEBUG("Event handler destroyed");
}

void gui::EventHandler::processEvents(sf::RenderWindow & window)
{
	m_event = Event::NO_OP; //default noop to return

	sf::Event event;
	while (window.pollEvent(event)) {
		// check events from the least to the most important, so that the most important is returned
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				m_event = Event::LEFT_PRESS;
			}
		}

		if (event.type == sf::Event::Closed) {
			m_event = Event::CLOSE;
		}
	}
}
