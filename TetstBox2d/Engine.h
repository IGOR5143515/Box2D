#pragma once
#include"objects.h"
#include<vector>
#include <SFML/Graphics.hpp>
class Engine{
private:
	const float SCALE = 30.f;
	std::vector<objects>Buffer;
	b2Vec2 gravity;
	b2World world;
public:
	Engine();

	void start(sf::RenderWindow&);


};

