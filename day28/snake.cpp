#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>

class Snake{
    public:
    Snake(sf::RectangleShape &snake, sf::RenderWindow &window){
        snake.setSize({50.f, 25.f});
        snake.setFillColor(sf::Color::Red);
        snake.setPosition({20.f, 20.f});

    }
};


int main(){

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "SNAKE");
    constexpr int FPS = 60;
    window.setFramerateLimit(FPS);

    float snakeVel = 6.0f;
    bool up =    false;
    bool down =  false;
    bool left =  false;
    bool right = false;

    
    sf::RectangleShape snake;
    Snake(snake, window);
    
    
    while(window.isOpen()){
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            else if(const auto* keyPress = event->getIf<sf::Event::KeyPressed>()){
                if(keyPress->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            bool up = true;
            bool down = false;
            bool left = false;
            bool right =false;
            if(up){
                snake.move({0.f, -snakeVel});
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            bool up = false;
            bool down = true;
            bool left = false;
            bool right =false;
            if(down){
                 snake.move({0.f, snakeVel});
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            bool up = false;
            bool down = false;
            bool left = true;
            bool right =false;
            if(left){
                snake.move({-snakeVel, 0.f});
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            bool up = false;
            bool down = false;
            bool left = false;
            bool right =true;
            if(right){
                snake.move({snakeVel, 0.f});
            }
        }
       
        window.clear();
        window.draw(snake);
        window.display();

    }

    return 0;
}