#include "Engine.h"

void Console(Engine *e) {   //��������� ������ ��������� ������
    std::string choose;
    std::string AdressOfSprite;
    while (true) {
        std::cin >> e->GetString();
        if (e->BufferComand == "New") {
            std::cout << "1- New dynamic obj" << std::endl;
            std::cout << "2- New static obj" << std::endl;

            std::cin >> choose;

            if (choose == "1") {
                std::cin >> AdressOfSprite;// ���� ������ �������
                objects* x = new objects(Type::DYNAMIC, sf::Vector2f(20, 1), e->world,
                    AdressOfSprite);
                e->Buffer.push_back(x);

            }
            if (choose == "2") {
                std::cin >> AdressOfSprite;
                objects* x = new objects(Type::STATIC, sf::Vector2f(1, 1), e->world, AdressOfSprite);
                e->Buffer.push_back(x);
               

            }
        }
        if (e->BufferComand == "Help") {
            std::cout << "New - Add new object to buffer" << std::endl;
        }

    }
    

}



void Engine::start(sf::RenderWindow &window) {
    
    std::thread tr(Console, this);//����� ������� Console � ��������� ������
    sf::Vector2f pos;

    while (window.isOpen())
    {
        cursor = sf::Mouse::getPosition(window);//���������� ������� ������� 
        pos= window.mapPixelToCoords(cursor);
       
        world.Step(1 / 60.f, 8, 3);//������ ���������� ��� Box2D

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
                    objects *x= new objects(Type::STATIC, sf::Vector2f(20, 10), world, "img/ball.png");
                    Buffer.push_back(x);
                }
            
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::R) {
                   ser.WriteToFile(Buffer);
                   std::cout << "Is saving";
                }
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::S) {
                    ser.loadFile(Buffer,world);
                    std::cout << "Is reading";
                }
            
           
        }
        
        if (event.type == sf::Event::MouseButtonPressed)
            if (event.key.code == sf::Mouse::Left) {
                for (size_t i = 0; i < Buffer.size(); i++)
                {
                    if (Buffer[i]->GetSprite().getGlobalBounds().contains(cursor.x, cursor.y)) {
                        copy = Buffer[i];
                        action = true;
                        //break;
                    }
                }
               
            }


        if (event.type == sf::Event::MouseButtonReleased)
            if (event.key.code == sf::Mouse::Left)
                action = false;
                

        if (action) {
            FollowingCursor(copy, pos);
        }

        StartFunk();

      
      
        window.clear();
        r.RenderAndMoving(Buffer, window);
        window.display();

     
    }

    tr.join();
}

void Engine::StartFunk() {
   /* ��� ����� ������������� ���� �������*/
    deleteBuffer();// �������� ������ ��� ������������ �������
}

Engine::Engine():gravity(0.0f, 9.8f),world(gravity) {

}

void Engine::deleteBuffer() {
    objects* ob;
    for (auto it = Buffer.begin(); it != Buffer.end();) {

        if ((*it)->GetSprite().getPosition().y >800) {
            ob = (*it);
            it = Buffer.erase(it);
           delete ob;
            
        }
        else
            it++;
        
    }


}


void Engine::FollowingCursor(objects * obj,sf::Vector2f vec) {

  
    b2Vec2 pos(vec.x/32, vec.y/32);// ������ � ����� 
    obj->getBody()->SetTransform(pos,obj->getBody()->GetAngle());

}