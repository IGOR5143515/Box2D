#pragma once
#include<fstream>
#include"objects.h"
#include<iostream>
class Serialization
{
private:
	
public:
	sf::Vector2f vec;
	void WriteToFile(std::vector<objects*>&,std::string);
	void loadFile(std::vector<objects*>&,b2World&,std::string);

};

