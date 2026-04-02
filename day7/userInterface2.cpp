
//Today I could have done more, I realised that yesterday I was using sfml 2.6 instead of sfml 3.0
//I have to use SFML 3.0 version because the documentation I am using is majorly in SFML 3.0
//Configuring this shit was so cumbersome man! I have 2 versions installed, the system is prioritizing sfml 2.6 so I had to 
// configure the task.json file manually and googling stuff around, fighting path conflicts and many more

//ANYWAYS, The sfml stuff themselves are quite cool, it's kinda like the pygame in python, I do not know who borrowed from the other one :)


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <optional>

int main(){
    sf::Window window(sf::VideoMode({1800,1200}), "WINDOW", sf::Style::Resize | sf::Style::Close);
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
            if (const auto* textEntered = event->getIf<sf::Event::TextEntered>()){  //text entered

                if (textEntered->unicode < 128){
                    std::cout << "ascii character typed: " << static_cast<char>(textEntered->unicode) << std::endl;
                }
            }

            //MOUSE EVENTS
            //scroll wheel
            if (const auto* mouseWheelScrolled = event->getIf<sf::Event::MouseWheelScrolled>()) //checking for mouse scroll of the wheel
            {
                switch (mouseWheelScrolled->wheel)
                {
                    case sf::Mouse::Wheel::Vertical:
                        std::cout << "wheel type: vertical" << std::endl;
                        break;
                    case sf::Mouse::Wheel::Horizontal:
                        std::cout << "wheel type: horizontal" << std::endl;
                        break;
                }
                std::cout << "wheel movement: " << mouseWheelScrolled->delta << std::endl;
                std::cout << "mouse x: " << mouseWheelScrolled->position.x << std::endl;
                std::cout << "mouse y: " << mouseWheelScrolled->position.y << std::endl;
            }
            //Pressing of the mouse buttons
            if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButtonPressed->button == sf::Mouse::Button::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << mouseButtonPressed->position.x << std::endl;
                    std::cout << "mouse y: " << mouseButtonPressed->position.y << std::endl;
                }
            }
            //Mouse movement
            if (const auto* mouseMoved = event->getIf<sf::Event::MouseMoved>())
            {
                std::cout << "new mouse x: " << mouseMoved->position.x << std::endl;
                std::cout << "new mouse y: " << mouseMoved->position.y << std::endl;
            }
        }
        
    } 
    return 0;
}