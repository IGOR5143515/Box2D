#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
enum class TypeOfObj {
	STATIC,
	DYNAMIC
};
class objects{
private:
	b2BodyDef groundDef;
	b2Body* body;
	b2PolygonShape groundbox;
	b2FixtureDef fixDef;

public:
	
	objects(TypeOfObj);




};

