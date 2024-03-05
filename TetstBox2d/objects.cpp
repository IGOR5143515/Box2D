#include "objects.h"

b2Body* objects::getBody() {
	return body;
}



objects::objects(Type t,sf::Vector2f vec,
	b2World &world,std::string str):SM(str){
	
	if (t == Type::DYNAMIC) {
		groundDef.type = b2_dynamicBody;
		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);

		groundbox.SetAsBox(1.5f, 1.5f);

		fixDef.shape = &groundbox;
		fixDef.density = 1.0f;
		fixDef.friction = 0.3f;
		body->CreateFixture(&fixDef);
	}

	if (t == Type::STATIC) {
		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);
		groundbox.SetAsBox(1.5f, 1.5f);
		body->CreateFixture(&groundbox, 0.0f);
	}

}