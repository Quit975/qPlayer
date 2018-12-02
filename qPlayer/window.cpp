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

	for (gui::Widget* widget : m_guiElements) {
		m_window.draw(*widget);
	}

	m_window.display();
}

void gui::Window::buildGUI(ResourceManager & rm)
{
	//SpriteWidget(sf::Vector2f pos, Task task, sf::Sprite& noHover, sf::Sprite& hover, sf::Sprite& click):
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(0.f, 0.f), Operation::PLAY, rm.getSprite(Sprite::PLAY_BUTTON), rm.getSprite(Sprite::PLAY_BUTTON), rm.getSprite(Sprite::PLAY_BUTTON)));
	DEBUG("Play button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(20.f, 0.f), Operation::PAUSE, rm.getSprite(Sprite::PAUSE_BUTTON), rm.getSprite(Sprite::PAUSE_BUTTON), rm.getSprite(Sprite::PAUSE_BUTTON)));
	DEBUG("Pause button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(40.f, 0.f), Operation::STOP, rm.getSprite(Sprite::STOP_BUTTON), rm.getSprite(Sprite::STOP_BUTTON), rm.getSprite(Sprite::STOP_BUTTON)));
	DEBUG("Stop button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(60.f, 0.f), Operation::PREV, rm.getSprite(Sprite::PREV_BUTTON), rm.getSprite(Sprite::PREV_BUTTON), rm.getSprite(Sprite::PREV_BUTTON)));
	DEBUG("Prev button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(80.f, 0.f), Operation::NEXT, rm.getSprite(Sprite::NEXT_BUTTON), rm.getSprite(Sprite::NEXT_BUTTON), rm.getSprite(Sprite::NEXT_BUTTON)));
	DEBUG("Next button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(0.f, 20.f), Operation::NO_OP, rm.getSprite(Sprite::DISPLAY_BKGD), rm.getSprite(Sprite::DISPLAY_BKGD), rm.getSprite(Sprite::DISPLAY_BKGD)));
	DEBUG("Display widget added");
	DEBUG("GUI built");
}
