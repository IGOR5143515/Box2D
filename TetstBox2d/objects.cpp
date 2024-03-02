#include "objects.h"

b2Body* objects::getBody() {
	return body;
}

sf::CircleShape& objects::getCircle() {
	return shape;
}

objects::objects(sf::Vector2f vec,b2World &world){

	
	groundDef.type = b2_dynamicBody;
	groundDef.position.Set(vec.x, vec.y);
	body = world.CreateBody(&groundDef);

	groundbox.SetAsBox(1.0f, 1.0f);

	fixDef.shape = &groundbox;
	fixDef.density = 1.0f;
	fixDef.friction = 0.3f;
	shape.setRadius(50);
	body->CreateFixture(&fixDef);
	

}