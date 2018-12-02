#pragma once
#include "core.h"
#include <SFML/Graphics.hpp>

namespace gui {
	class EventHandler
	{
	private:
		Event m_event;

	public:
		EventHandler();
		~EventHandler();

		//public interface
		void processEvents(sf::RenderWindow& window);

		//setters getters
		Event event() { return m_event; }
		
		
	};
}