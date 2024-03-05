#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include"SpriteManager.h"



enum class Type {
	STATIC,
	DYNAMIC
};

class objects{
private:
	SpriteManager SM;
	b2BodyDef groundDef;
	b2Body* body;
	b2PolygonShape groundbox;
	b2FixtureDef fixDef;
	sf::CircleShape shape;

public:

	objects(Type,sf::Vector2f,b2World&,std::string);
	b2Body* getBody();
	sf::Sprite& GetSprite() { return SM.GetSprite(); }

	



};

