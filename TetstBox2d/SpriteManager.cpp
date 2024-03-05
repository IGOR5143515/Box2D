#include "SpriteManager.h"


SpriteManager::SpriteManager(std::string &str) {
	
	t.loadFromFile(str);
	s.setTexture(t);

}