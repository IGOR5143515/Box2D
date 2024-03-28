#include "Engine.h"
#include <cstdlib>

void Console(Engine *e) {   //��������� ������ ��������� ������
    std::string choose;
    std::string AdressOfSprite;
    while (true) {
        std::cin >> e->GetString();
        if (e->BufferComand == "New") {
            std::cout << "1- New dynamic obj" << std::endl;
            std::cout << "2- New static obj" << std::endl;
            std::cout << "3- Back Ground" << std::endl;

            std::cin >> choose;

            if (choose == "1") {
                std::cin >> AdressOfSprite;// ���� ������ �������
                objects* x = new objects(Type::DYNAMIC, sf::Vector2f(20, 10), e->world,
                    "img/"+AdressOfSprite);
                e->Buffer.push_back(x);

            }
            if (choose == "2") {
                std::cin >> AdressOfSprite;
                objects* x = new objects(Type::STATIC, sf::Vector2f(20, 10), e->world, "img/" + AdressOfSprite);
                e->Buffer.push_back(x);
               

            }
            if (choose == "3") {
                std::cin >> AdressOfSprite;
                objects* x = new objects(Type::BACK_GROUND, sf::Vector2f(20, 10), e->world, "img/" + AdressOfSprite);
                e->Buffer.push_back(x);

            }
        
        }
        if (e->BufferComand == "Save") {

            std::cout << "Enter a number of save file" << std::endl;
            std::string a; std::cin >> a;
            e->getSer().WriteToFile(e->Buffer, a);

        }
        if (e->BufferComand == "Load") {
            std::cout << "Enter a number load file" << std::endl;
            std::string a; std::cin >> a;
            e->getSer().loadFile(e->Buffer,e->world, a);
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
       
        world.Step(2 / 60.f, 8, 3);//������ ���������� ��� Box2D

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
           
            
           /* if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::A) {
                   
                    levelManager("1");

                }*/
          
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Z) {

                    levelManager("2");

                }
            
         
           
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            h->getBody()->ApplyLinearImpulseToCenter(b2Vec2(0.25, 0), true);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            h->getBody()->ApplyLinearImpulseToCenter(b2Vec2(-0.25, 0), true);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            h->getBody()->SetLinearVelocity(b2Vec2(0, -10));

      

        
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

        

      
      
        window.clear();
        r.RenderAndMoving(Buffer, window);
        window.display();
        deleteBuffer();// �������� ������ ��� ������������ �������
     
    }
    
    tr.join();
   
}

void Engine::levelManager(std::string num) {
    std::vector<objects*>arr;
    arr.push_back(h);

    for (auto& obj : Buffer) {
        if (obj->status == "Hero")
            continue;

        delete obj;
    }
    Buffer.clear();
  
    
    ser.loadFile(arr, world, num);
    Buffer = arr;
                                            //Delete buffer
  
    
   
}

void Engine::StartFunk() {
   /* ��� ����� ������������� ���� �������*/
  
    
    
}

Engine::Engine() :gravity(0.0f, 9.8f), world(gravity) {
    StartFunk();
    h= new Hero(Type::HERO, sf::Vector2f(20, 10), world, "img/ball.png");//Hero
    h->status = "Hero";
 
   
    Buffer.push_back(h);
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
Engine::~Engine() {

    delete copy;
    for (auto& obj : Buffer) {
        delete obj;                    
    }
    Buffer.clear();
}


//change

