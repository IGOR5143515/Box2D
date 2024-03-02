#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include"Engine.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280,720), "Gravity Simulation");
    window.setFramerateLimit(60);
 
    Engine e;
    e.start(window);



   

    
}