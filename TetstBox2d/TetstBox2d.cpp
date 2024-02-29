#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include"Engine.h"
const float SCALE = 30.f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "Gravity Simulation");
    window.setFramerateLimit(60);
 
    Engine e;
    e.start(window);



   

    
}