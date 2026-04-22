/*
 ____   ___  _   _  ____        ____    _    __  __ _____ 
|  _ \ / _ \| \ | |/ ___|      / ___|  / \  |  \/  | ____|
| |_) | | | |  \| | |  _ _____| |  _  / _ \ | |\/| |  _|  
|  __/| |_| | |\  | |_| |_____| |_| |/ ___ \| |  | | |___ 
|_|    \___/|_| \_|\____|      \____/_/   \_\_|  |_|_____|
*/

#include <iostream>
#include <optional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode({1500, 900}), "PONG");
    window.setFramerateLimit(60);

    sf::Vector2u dimensions = window.getSize();
    float width = dimensions.x;
    float height = dimensions.y;

    float vel = 15;
    bool bounce = true;
    float ballVel = 6.0;

    sf::RectangleShape player1;
    player1.setSize({50.f, 250.f});
    player1.setOrigin({25.f, 125.f});
    player1.setPosition({25, 450});
    player1.setFillColor(sf::Color::Green);

    sf::RectangleShape player2;
    player2.setSize({50.f, 250.f});
    player2.setOrigin({25.f, 125.f});
    player2.setPosition({1475, 450});
    player2.setFillColor(sf::Color::Cyan);

    sf::CircleShape ball(20.f);
    ball.setOrigin({ball.getRadius(), ball.getRadius()});
    ball.setFillColor(sf::Color::Red);
    ball.setPosition({width/2, height/2});

    
    while(window.isOpen()){
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }else if(const auto* key = event->getIf<sf::Event::KeyPressed>()){
                if(key->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }
        sf::FloatRect bounds1 = player1.getGlobalBounds();
        sf::FloatRect bounds2 = player2.getGlobalBounds();
        sf::FloatRect bounds3 = ball.getGlobalBounds();

        sf::Vector2f pos = ball.getPosition();
        float posX = pos.x;
        if(bounce){ 
            ball.move({ballVel, 0.f}); 
            ballVel += 0.02;
        }
        if (posX > 1445){ bounce = false; }

        if(!bounce){
            ball.move({-ballVel, 0.f}); 
            ballVel += 0.02;  
        }
        if(posX < 35){
            ball.move({ballVel, 0.f}); 
            bounce = true;
            ballVel += 0.02;
        }

        sf::Vector2f player1Pos = player1.getPosition();
        sf::Vector2f player2Pos = player2.getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ 
            player1.move({0.f, -vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ){
            player1.move({0.f, vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            player2.move({0.f, -vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            player2.move({0.f, vel});
        }

        float player1y = player1Pos.y;
        float player2y = player2Pos.y;
        
        if(player1Pos.y < 120){ player1.move({0.f, vel}); }
        if(player1Pos.y > 780){ player1.move({0.f, -vel}); }

        if(player2Pos.y < 120){ player2.move({0.f, vel}); }
        if(player2Pos.y > 780){ player2.move({0.f, -vel}); }

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.display();
    }

    return 0;
}