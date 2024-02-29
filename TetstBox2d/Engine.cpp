#include "Engine.h"

void Engine::start(sf::RenderWindow &window) {
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

}


Engine::Engine():gravity(0.0f, 9.8f),world(gravity) {

}