#include "eventHandler.h"

gui::EventHandler::EventHandler()
{
}

gui::EventHandler::~EventHandler()
{
}

void gui::EventHandler::processEvents(sf::RenderWindow & window) const
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {

		}
	}
}
