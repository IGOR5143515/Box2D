#include "Serialization.h"

void Serialization::WriteToFile(std::vector<objects*>&arr){
	std::ofstream ofs("SaveFile.bin", std::ios::binary);
	std::ofstream ofsType("Type.bin", std::ios::binary);
	size_t  numObj = arr.size();

	ofs.write(reinterpret_cast<char*>(&numObj), sizeof(size_t));
	
	for (auto& x : arr) {
		
		x->serialize(ofs,ofsType);
	}

}

void Serialization::loadFile(std::vector<objects*>& arr, b2World &w) {
	objects* x=nullptr;

	std::ifstream ifs("SaveFile.bin", std::ios::binary);
	std::ifstream ifsType("Type.bin", std::ios::binary);
	Type t;
	size_t  numObj=arr.size();

	ifs.read(reinterpret_cast<char*>(&numObj), sizeof(size_t));
	
	for (size_t i = 0; i < numObj; i++)
	{
		ifsType.read(reinterpret_cast<char*>(&t), sizeof(Type));
		if (t == Type::DYNAMIC) {
			x = new objects(Type::DYNAMIC, sf::Vector2f(20, 10), w,
				"img/ball.png");
			x->getType() = Type::DYNAMIC;
		}
		if (t == Type::STATIC) {
			x = new objects(Type::STATIC, sf::Vector2f(20, 10), w, "img/ball.png");
			x->getType() = Type::STATIC;
		}

		x->deserialize(ifs, w);
		arr.push_back(x);

	}
	


}

