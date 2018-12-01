#include "eventHandler.h"

gui::EventHandler::EventHandler()
{
	DEBUG("Event handler created");
}

gui::EventHandler::~EventHandler()
{
	DEBUG("Event handler destroyed");
}

void gui::EventHandler::processEvents(sf::RenderWindow & window) const
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {

		}
	}
}
