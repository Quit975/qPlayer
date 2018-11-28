#pragma once
#include "core.h"
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
	enum class Sprite {
		PLAY_BUTTON,
		STOP_BUTTON,
		PAUSE_BUTTON,
		PREV_BUTTON,
		NEXT_BUTTON,
		VOL_SLIDER,
		DISPLAY_BKGD
	};


private:
	sf::Texture m_texture;
	std::map<Sprite, sf::IntRect> m_texCoordMap;
	std::vector<sf::Sprite> m_sprites;

public:
	ResourceManager();
	~ResourceManager();

	sf::Sprite& getSprite(Sprite sprite);

};
