#pragma once
#include <SFML/Graphics.hpp>
class SpriteManager
{
private:
	sf::Texture t;
	sf::Sprite s;
public:
	SpriteManager(std::string&);
	sf::Sprite& GetSprite() { return s; }
	SpriteManager(){}
};
