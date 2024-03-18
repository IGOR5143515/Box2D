#include "objects.h"

b2Body* objects::getBody() {
	return body;
}

objects::objects(b2World& world, std::string str):SM(str) {
	groundDef.position.Set(0,0);
	body = world.CreateBody(&groundDef);
	groundbox.SetAsBox(1.5f, 1.5f);
	body->CreateFixture(&groundbox, 0.0f);
}


objects::objects(Type t,sf::Vector2f vec,
	b2World &world,std::string str):SM(str){
	
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
		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);
		groundbox.SetAsBox(1.5f, 1.5f);
		body->CreateFixture(&groundbox, 0.0f);
		type = Type::STATIC;
	}

}

void objects::serialize(std::ofstream& of,std::ofstream &ofType) {
	b2Vec2 pos = this->body->GetPosition();
	of.write(reinterpret_cast<char*>(&pos), sizeof(b2Vec2));

	ofType.write(reinterpret_cast<char*>(&type), sizeof(Type));
	

}

void objects::deserialize(std::ifstream& ifs, b2World& world) {
	
	b2Vec2 pos;
	ifs.read(reinterpret_cast<char*>(&pos), sizeof(b2Vec2));
	

	//groundDef.position = pos;
	
	body->SetTransform(pos,body->GetAngle());
	
	

	
	

}