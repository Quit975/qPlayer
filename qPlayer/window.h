#pragma once

#include <SFML/Graphics.hpp>
#include "core.h"
#include "eventHandler.h"
#include "spriteWidget.h"
#include "textWidget.h"
#include <vector>
#include "resourceManager.h"
#include "task.h"

namespace gui {
	class Window 
	{
	private:
		sf::RenderWindow m_window;
		gui::EventHandler m_eventHandler;

		//gui elements
		std::vector<gui::Widget*> m_guiElements;

	public:
		Window();
		~Window();

		//public interface
		void processEvents();
		Task update();
		void draw();
		void buildGUI(ResourceManager& rm);
		void close();
	};
}