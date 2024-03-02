#include "Engine.h"

void Engine::start(sf::RenderWindow &window) {
   
    while (window.isOpen())
    {
        world.Step(1 / 60.f, 8, 3);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type==sf::Event::KeyPressed)
                if(event.key.code==sf::Keyboard::Q){
                objects x(sf::Vector2f(20, 1), world);
                Buffer.push_back(x);
            }
           
        }
        
        
       
      
        window.clear();
        r.RenderAndMoving(Buffer, window);
        window.display();
    }

}


Engine::Engine():gravity(0.0f, 9.8f),world(gravity) {

}