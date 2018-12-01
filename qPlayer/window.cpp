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

void gui::Window::buildGUI(ResourceManager & rm)
{
	//SpriteWidget(sf::Vector2f pos, Task task, sf::Sprite& noHover, sf::Sprite& hover, sf::Sprite& click):
	//m_guiElements.insert(new gui::SpriteWidget(sf::Vector2f(0.f, 20.f), Task(Operation::PLAY), rm.getSprite(Sprite::PLAY_BUTTON), rm.getSprite(Sprite::PLAY_BUTTON), rm.getSprite(Sprite::PLAY_BUTTON));
}
