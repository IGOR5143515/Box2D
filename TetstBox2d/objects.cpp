#include "objects.h"


objects::objects(Type t,sf::Vector2f vec,b2World world) {
	
	if (t == Type::STATIC) {

		groundDef.position.Set(vec.x, vec.y);
		body = world.CreateBody(&groundDef);
		groundbox.SetAsBox(vec.x, vec.y);
		body->CreateFixture(&groundbox, 0.0f);
	}

	if (t == Type::DYNAMIC) {

	}
	

}