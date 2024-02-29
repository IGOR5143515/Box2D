#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <iostream>

const float SCALE = 30.f;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Simulation");
    window.setFramerateLimit(60);
 

    while (window.isOpen())
    {
       
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

      
        window.clear();
       
        window.display();
    }

    return 0;
}