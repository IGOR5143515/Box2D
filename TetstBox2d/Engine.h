#pragma once
#include<iostream>
#include"objects.h"
#include<vector>
#include <SFML/Graphics.hpp>
#include"Render.h"
#include<thread>
#include"Serialization.h"


class Engine{
private:
	
	Serialization ser;
	objects* copy{};
	bool action = false;
	std::string BufferComand;
	std::vector<objects*>Buffer;
	b2Vec2 gravity;
	b2World world;
	Render r;
	sf::Vector2i cursor;
	
public:
	Serialization& getSer() { return ser; }
	Engine();
	void levelManager(std::string);
	friend void Console(Engine* );
	void start(sf::RenderWindow&);
	void deleteBuffer();
	std::string& GetString() { return BufferComand; }
	void AddObject();
	void StartFunk();
	void FollowingCursor(objects *,sf::Vector2f);
	~Engine();
};

