#include "Engine.h"

void Console(Engine *e) {

    while (true) {
        std::cin >> e->GetString();
    }

}

void Engine::start(sf::RenderWindow &window) {
    
    std::thread tr(Console, this);//Вызов функции Console в отдельном потоке


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
        
       
       deleteBuffer();// очищение буфера при определенном условии
      
        window.clear();
        r.RenderAndMoving(Buffer, window);
        window.display();

     
    }

    tr.join();
}


Engine::Engine():gravity(0.0f, 9.8f),world(gravity) {

}

void Engine::deleteBuffer() {

    for (auto it = Buffer.begin(); it != Buffer.end();) {

        if ((*it)->GetSprite().getPosition().y >400) {
            it = Buffer.erase(it);
        }
        else
            it++;
        
    }

}
