//I just felt like I have learnt enough from the documentation and I can already start trying things
//I haven't finished the documentation but I feel like the part that I have studied is good enough to be applicable
//not everything I code I commit here, there are some stuff that I actually do but I do not commit
/*
                       _ _         
  __ _ _ __ __ ___   _(_) |_ _   _ 
 / _` | '__/ _` \ \ / / | __| | | |
| (_| | | | (_| |\ V /| | |_| |_| |
 \__, |_|  \__,_| \_/ |_|\__|\__, |
 |___/                       |___/ 

 */

#include <iostream>
#include <optional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(){
    float vel = 0.01;
    bool bounce = true;

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "JUST TRYING SHIT!");
    window.setFramerateLimit(60);
    sf::CircleShape ball(50.f);
    ball.setOrigin({ball.getRadius(), ball.getRadius()});
    ball.setFillColor(sf::Color::Green);
    ball.setPosition({750.f, 10.f});


    while(window.isOpen()){
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }
        sf::Vector2f pos = ball.getPosition();
        float posY = pos.y;

        if(bounce){ 
            ball.move({0.f, vel}); 
            vel += 0.2;
        }
        if (posY > 890){ bounce = false; }

        if(!bounce){
            ball.move({0.f, -vel}); 
            vel -= 0.3;  
        }
        if(vel <= 0){
            bounce = true;
        }
        // if(posY < 0){ bounce = true;}

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}