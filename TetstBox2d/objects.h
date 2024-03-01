#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>


enum class Type {
	STATIC,
	DYNAMIC
};

class objects{
private:
	b2BodyDef groundDef;
	b2Body* body;
	b2PolygonShape groundbox;
	b2FixtureDef fixDef;
	sf::CircleShape shape;

public:

	objects(Type,sf::Vector2f,b2World);



};

