#pragma once
#include<iostream>
#include"objects.h"
#include<vector>
#include <SFML/Graphics.hpp>
#include"Render.h"




class Engine{
private:
	
	std::vector<objects*>Buffer;
	b2Vec2 gravity;
	b2World world;
	Render r;
	
public:
	Engine();
	
	void start(sf::RenderWindow&);


};

