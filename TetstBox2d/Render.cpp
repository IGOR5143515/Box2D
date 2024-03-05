#include "Render.h"

void Render::RenderAndMoving(std::vector<objects>&arr,sf::RenderWindow &window) {

	for (size_t i = 0; i < arr.size(); i++)
	{
		b2Vec2 pos = arr[i].getBody()->GetPosition();
		arr[i].GetSprite().setPosition(pos.x*30.f, pos.y * 30.f);
		
	}

	for (size_t i = 0; i < arr.size(); i++)
	{
		window.draw(arr[i].GetSprite());
		
	}
	
}