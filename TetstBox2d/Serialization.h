#pragma once
#include<fstream>
class Serialization
{
private:
	std::fstream f;
public:
	void WriteToFile();
};

