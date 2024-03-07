#include "Engine.h"

void Console(Engine *e) {   //Обработка команд командной строки
    std::string choose;
    while (true) {
        std::cin >> e->GetString();
        if (e->BufferComand == "New") {
            std::cout << "1- New dynamic obj" << std::endl;
            std::cout << "1- New static obj" << std::endl;

            std::cin >> choose;

            if (choose == "1") {
                objects* x = new objects(Type::DYNAMIC, sf::Vector2f(20, 1), e->world,
                    "img/ball.png");
                e->Buffer.push_back(x);

            }
            if (choose == "2") {
                objects* x = new objects(Type::STATIC, sf::Vector2f(20, 20), e->world, "img/ball.png");
                e->Buffer.push_back(x);
               

            }
        }
        if (e->BufferComand == "Help") {
            std::cout << "New - Add new object to buffer" << std::endl;
        }

    }
    

}

void Engine::start(sf::RenderWindow &window) {
    
    std::thread tr(Console, this);//Вызов функции Console в отдельном потоке


    while (window.isOpen())
    {
        cursor = sf::Mouse::getPosition(window);//считывание позиции курсора 

       
        world.Step(1 / 60.f, 8, 3);//Физики притяжения для Box2D

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
