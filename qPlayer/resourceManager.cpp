#include "resourceManager.h"

ResourceManager::ResourceManager()
{
	if (!m_texture.loadFromFile("tex/tex.png")) {
		ERR("Failed to load the texture file");
		throw ResourceException("Failed to load the texture file");
	}

	m_texCoordMap.emplace(Sprite::PLAY_BUTTON, sf::IntRect(0, 0, 20, 20));
	m_texCoordMap.emplace(Sprite::STOP_BUTTON, sf::IntRect(20, 0, 20, 20));
	m_texCoordMap.emplace(Sprite::PAUSE_BUTTON, sf::IntRect(40, 0, 20, 20));
	m_texCoordMap.emplace(Sprite::PREV_BUTTON, sf::IntRect(60, 0, 20, 20));
	m_texCoordMap.emplace(Sprite::NEXT_BUTTON, sf::IntRect(80, 0, 20, 20));
	m_texCoordMap.emplace(Sprite::VOL_SLIDER, sf::IntRect(100, 0, 20, 20));
	m_texCoordMap.emplace(Sprite::DISPLAY_BKGD, sf::IntRect(0, 20, 120, 20));
}

ResourceManager::~ResourceManager()
{
}

sf::Sprite & ResourceManager::getSprite(Sprite sprite)
{
	m_sprites.emplace_back(m_texture, m_texCoordMap.at(sprite));
	return m_sprites.back();
}
