//sfml focus today, finally configured this shit successfully after almost one week
//more mouse events

#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>

int main(){

    sf::Window window(sf::VideoMode({1800, 1200}), "SFML part 2");
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

            //checking whether the mouse is in our window or not
            if(event->is<sf::Event::MouseEntered>()){
                std::cout << "The mouse has entered the window!" << std::endl;
            }
            if(event->is<sf::Event::MouseLeft>()){
                std::cout << "The mouse has left the window!" << std::endl;
            }

            //checking input devices
            //sf::Keyboard - this namespace let's us access the state of the keys on the keyboard.
            // regardless of whether the window is active or not
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
                std::cout << "Left key has been pressed!" << std::endl;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Up)){
                std::cout << "Up arror key pressed! " << std::endl;
            }

            //sf::Mouse does the same but for mouse
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){ //can either be right, middle or any other 2 extra
                std::cout << "Clicked the left button!" << std::endl;
            }

            // get the mouse position relative to the desktop
            sf::Vector2i globalPosition = sf::Mouse::getPosition();

            // get the mouse position relative to a window
            sf::Vector2i localPosition = sf::Mouse::getPosition(window);

            //you can also set the mouse postion (local or global)
            sf::Mouse::setPosition({10, 50});
            sf::Mouse::setPosition({10, 50}, window);
                    }
    }

    return 0;
}
//tomorrow is now drawing stuff on the window, the cool stuff now