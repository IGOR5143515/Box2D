#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include"SpriteManager.h"
#include<fstream>

enum class Type {
	STATIC,
	DYNAMIC
};

class objects{
private:
	
	std::string fileName;
	Type type;
	SpriteManager SM;
	b2BodyDef groundDef;
	b2Body* body;
	b2PolygonShape groundbox;
	b2FixtureDef fixDef;
	

public:
	
	Type &getType() { return type; }
	b2BodyDef& getBodyDef() { return groundDef; }
	objects(Type,sf::Vector2f,b2World&,std::string);
	b2Body* getBody();
	sf::Sprite& GetSprite() { return SM.GetSprite(); }
	objects(b2World& world, std::string str);
	objects(){}

	void serialize(std::ofstream&,std::ofstream&, std::ofstream&);
	void deserialize(std::ifstream&, std::ifstream& ,b2World&);
	~objects();
};

