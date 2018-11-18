#pragma once

#include <SFML/Graphics.hpp>

namespace gui {
	class EventHandler
	{
	private:

	public:
		EventHandler();
		~EventHandler();

		//public interface
		void processEvents(sf::RenderWindow& window) const;

		
	};
}