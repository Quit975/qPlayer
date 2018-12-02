#include "window.h"

gui::Window::Window():
	m_window(sf::VideoMode(400, 200), "qPlayer")
{
	DEBUG("Window created");
}

gui::Window::~Window()
{
	for (gui::Widget* widget : m_guiElements) {
		delete widget;
	}
	DEBUG("Gui widgets deleted");
	m_window.close();
	DEBUG("Window destroyed");
}

void gui::Window::processEvents()
{
	m_eventHandler.processEvents(m_window);
}

Task gui::Window::update()
{
	// Check if there is closure event and return it if so
	if (m_eventHandler.event() == Event::CLOSE) {
		return Task(Operation::CLOSE);
	}

	// Temp pointer to hovered widget
	Widget* hWidget = nullptr;
	sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

	for (gui::Widget* widget : m_guiElements) {
		if (widget->isMouseOver(mousePos)) {
			hWidget = widget;
		}
	}

	// Check for other event types
	if (m_eventHandler.event() == Event::NO_OP) {
		return Task(Operation::NO_OP);
	}

	if (m_eventHandler.event() == Event::LEFT_PRESS) {
		if (hWidget) {
			return hWidget->click();
		}
	}
	return Task(Operation::NO_OP);
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
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(0.f, 0.f), sf::Vector2f(20.f, 20.f), Operation::PLAY, rm.getSprite(Sprite::PLAY_BUTTON), rm.getSprite(Sprite::PLAY_BUTTON), rm.getSprite(Sprite::PLAY_BUTTON)));
	DEBUG("Play button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(20.f, 0.f), sf::Vector2f(20.f, 20.f), Operation::PAUSE, rm.getSprite(Sprite::PAUSE_BUTTON), rm.getSprite(Sprite::PAUSE_BUTTON), rm.getSprite(Sprite::PAUSE_BUTTON)));
	DEBUG("Pause button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(40.f, 0.f), sf::Vector2f(20.f, 20.f), Operation::STOP, rm.getSprite(Sprite::STOP_BUTTON), rm.getSprite(Sprite::STOP_BUTTON), rm.getSprite(Sprite::STOP_BUTTON)));
	DEBUG("Stop button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(60.f, 0.f), sf::Vector2f(20.f, 20.f), Operation::PREV, rm.getSprite(Sprite::PREV_BUTTON), rm.getSprite(Sprite::PREV_BUTTON), rm.getSprite(Sprite::PREV_BUTTON)));
	DEBUG("Prev button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(80.f, 0.f), sf::Vector2f(20.f, 20.f), Operation::NEXT, rm.getSprite(Sprite::NEXT_BUTTON), rm.getSprite(Sprite::NEXT_BUTTON), rm.getSprite(Sprite::NEXT_BUTTON)));
	DEBUG("Next button widget added");
	m_guiElements.push_back(new gui::SpriteWidget(sf::Vector2f(0.f, 20.f), sf::Vector2f(120.f, 40.f), Operation::NO_OP, rm.getSprite(Sprite::DISPLAY_BKGD), rm.getSprite(Sprite::DISPLAY_BKGD), rm.getSprite(Sprite::DISPLAY_BKGD)));
	DEBUG("Display widget added");
	DEBUG("GUI built");
}

void gui::Window::close()
{
	DEBUG("Closing window");
}
