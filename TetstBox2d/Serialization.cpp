#include "Serialization.h"

void Serialization::WriteToFile(std::vector<objects*>&arr){
	std::ofstream ofs("SaveFile.bin", std::ios::binary);
	size_t  numObj = arr.size();

	ofs.write(reinterpret_cast<char*>(&numObj), sizeof(size_t));
	
	for (auto& x : arr) {
		x->serialize(ofs);
	}

}

void Serialization::loadFile(std::vector<objects*>& arr, b2World &w) {

	std::ifstream ifs("SaveFile.bin", std::ios::binary);
   
	size_t  numObj=arr.size();

	ifs.read(reinterpret_cast<char*>(&numObj), sizeof(size_t));

	for (size_t i = 0; i < numObj; i++)
	{
		objects* x = new objects(Type::DYNAMIC, sf::Vector2f(20, 1), w,
			"img/ball.png");
		x->deserialize(ifs, w);
		arr.push_back(x);

	}
	


}

