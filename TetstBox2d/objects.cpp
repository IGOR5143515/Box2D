#include "objects.h"
#include<iostream>
b2Body* objects::getBody() {
	return body;
}




objects::objects(Type t,sf::Vector2f vec,
	b2World &world,std::string str):SM(str){
	
	fileName = str;

	if (t == Type::DYNAMIC) {
		groundDef.type = b2_dynamicBody;
		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);
		type = Type::DYNAMIC;
		groundbox.SetAsBox(0.5f, 0.5f);

		fixDef.shape = &groundbox;
		fixDef.density = 5.0f;				
		fixDef.friction = 5.3f;
		body->CreateFixture(&fixDef);
	}

	if (t == Type::STATIC) {
	

		SM.GetSprite().setOrigin(SM.GetSprite().getGlobalBounds().width/2, SM.GetSprite().getGlobalBounds().height / 2);


		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);	
		groundbox.SetAsBox(SM.GetSprite().getGlobalBounds().width/60,SM.GetSprite().getGlobalBounds().height/60);
		body->CreateFixture(&groundbox, 0.0f);
		type = Type::STATIC;
	}

	if (t == Type::BACK_GROUND) {
		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);
		groundbox.SetAsBox(1.5f, 1.5f);
	
		type = Type::STATIC;
	}


}

void objects::serialize(std::ofstream& ofs,std::ofstream &ofType,std::ofstream &ofsTexture) {
	b2Vec2 pos = this->body->GetPosition();
	ofs.write(reinterpret_cast<char*>(&pos), sizeof(b2Vec2)); //write position object

	
	ofsTexture << fileName << std::endl;

	ofType.write(reinterpret_cast<char*>(&type), sizeof(Type));  // write type object

	
}

void objects::deserialize(std::ifstream& ifs, std::ifstream& ifsTexture, b2World& world) {

	b2Vec2 pos;
	ifs.read(reinterpret_cast<char*>(&pos), sizeof(b2Vec2));
	body->SetTransform(pos,body->GetAngle());

	
}

objects::~objects() {
	
	b2World *world = body->GetWorld();

	world->DestroyBody(body);
	body = nullptr;

}