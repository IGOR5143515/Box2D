#pragma once
#include<iostream>
#include"objects.h"
#include<vector>
#include <SFML/Graphics.hpp>
#include"Render.h"
#include<thread>

class Engine{
private:
	std::string BufferComand;
	std::vector<objects*>Buffer;
	b2Vec2 gravity;
	b2World world;
	Render r;
	sf::Vector2i cursor;
	
public:
	Engine();
	friend void Console(Engine* e);
	void start(sf::RenderWindow&);
	void deleteBuffer();
	std::string& GetString() { return BufferComand; }
	void AddObject();

};

