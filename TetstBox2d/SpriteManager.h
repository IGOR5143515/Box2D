#pragma once
#include <SFML/Graphics.hpp>
class SpriteManager
{
private:
	sf::Texture t;
	sf::Sprite s;
public:
	sf::Texture &GetTexture() { return t; }
	SpriteManager(std::string&);
	sf::Sprite& GetSprite() { return s; }
	void setSprite(std::string str) {
		 
		t.loadFromFile(str);
		s.setTexture(t);
	}
	SpriteManager(){}
};
