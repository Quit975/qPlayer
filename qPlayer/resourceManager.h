#pragma once
#include "core.h"
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

class ResourceManager
{
private:
	sf::Texture m_texture;
	std::map<Sprite, sf::Sprite> m_sprites;

public:
	ResourceManager();
	~ResourceManager();

	sf::Sprite& getSprite(Sprite sprite);

};
