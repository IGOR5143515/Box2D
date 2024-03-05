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
                objects *x= new objects(Type::DYNAMIC,sf::Vector2f(20, 1), world,
                    "img/ball.png");
                Buffer.push_back(x);
               
            }
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::W) {
                    objects *x= new objects(Type::STATIC, sf::Vector2f(20, 20), world, "img/ball.png");
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