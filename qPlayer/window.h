#pragma once

#include <SFML/Graphics.hpp>
#include "core.h"

namespace gui {
	class Window 
	{
	private:
		sf::RenderWindow m_window;

		//flags
		bool m_closureRequested;

	public:
		Window();
		~Window();

		//public interface
		void processEvents();
		void draw();

		//setters & getters
		bool closureRequested() { return m_closureRequested; }
	};
}