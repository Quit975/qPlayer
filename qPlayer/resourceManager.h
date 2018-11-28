#pragma once
#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

class ResourceManager
{
public:
	enum class Sprite {

	};


private:
	std::map<Sprite, sf::IntRect> m_texCoordMap;
	std::vector<sf::Sprite> m_sprites;

public:
	ResourceManager();
	~ResourceManager();

	sf::Sprite& getSprite(Sprite sprite);

};
