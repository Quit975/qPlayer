#include "resourceManager.h"

ResourceManager::ResourceManager()
{
	if (!m_texture.loadFromFile("tex/tex.png")) {
		ERR("Failed to load the texture file");
		throw ResourceException("Failed to load the texture file");
	}
	DEBUG("Texture loaded");

	m_sprites.emplace(Sprite::PLAY_BUTTON, sf::Sprite(m_texture, sf::IntRect(0, 0, 20, 20)));
	m_sprites.emplace(Sprite::STOP_BUTTON, sf::Sprite(m_texture, sf::IntRect(20, 0, 20, 20)));
	m_sprites.emplace(Sprite::PAUSE_BUTTON, sf::Sprite(m_texture, sf::IntRect(40, 0, 20, 20)));
	m_sprites.emplace(Sprite::PREV_BUTTON, sf::Sprite(m_texture, sf::IntRect(60, 0, 20, 20)));
	m_sprites.emplace(Sprite::NEXT_BUTTON, sf::Sprite(m_texture, sf::IntRect(80, 0, 20, 20)));
	m_sprites.emplace(Sprite::VOL_SLIDER, sf::Sprite(m_texture, sf::IntRect(100, 0, 20, 20)));
	m_sprites.emplace(Sprite::DISPLAY_BKGD, sf::Sprite(m_texture, sf::IntRect(0, 20, 120, 20)));

	DEBUG("Sprite vector populated");

	DEBUG("Resource Manager created");
}

ResourceManager::~ResourceManager()
{
	DEBUG("Resource Manager destroyed");
}

sf::Sprite & ResourceManager::getSprite(Sprite sprite)
{
	return m_sprites.at(sprite);
}
