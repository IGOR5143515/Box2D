#include "Serialization.h"


void Serialization::WriteToFile(std::vector<objects*>&arr,std::string num){
	std::ofstream ofs(num+"SaveFile.bin", std::ios::binary);
	std::ofstream ofsType(num+"Type.bin", std::ios::binary);
	std::ofstream ofsTexture(num+"Texture.txt");
	size_t  numObj = arr.size();

	ofs.write(reinterpret_cast<char*>(&numObj), sizeof(size_t));
	
	for (auto& x : arr) {
		
		x->serialize(ofs,ofsType,ofsTexture);
	}

}

void Serialization::loadFile(std::vector<objects*>& arr, b2World &w,std::string num) {
	//objects* x=nullptr;

	std::ifstream ifs(num+"SaveFile.bin", std::ios::binary);
	std::ifstream ifsType(num + "Type.bin", std::ios::binary);
	std::ifstream ifsTexture(num + "Texture.txt");
	std::string FileName;
	Type t;
	size_t  numObj=arr.size();

	ifs.read(reinterpret_cast<char*>(&numObj), sizeof(size_t));
	
	for (size_t i = 0; i < numObj; i++)
	{
		ifsTexture >> FileName;
		ifsType.read(reinterpret_cast<char*>(&t), sizeof(Type));
		objects* x = nullptr;
		if (t == Type::DYNAMIC) {
			x = new objects(Type::DYNAMIC, sf::Vector2f(20, 10), w,
				FileName);
			x->getType() = Type::DYNAMIC;
		}
		if (t == Type::STATIC) {
			x = new objects(Type::STATIC, sf::Vector2f(20, 10), w, FileName);
			x->getType() = Type::STATIC;
		}

		x->deserialize(ifs,ifsTexture, w);
		
		arr.push_back(x);

	}
	

	ifs.close();
	ifsType.close();
	ifsTexture.close();
}

