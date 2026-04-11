//TEXT RENDERING AND FONTS!

#include <iostream>
#include <optional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


int main(){

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "TEXT RENDERING");

    while(window.isOpen()){
        //passing the ttf file
        //and defining how you want the text to look
        sf::Font font("/home/martin/Pictures/wallpapers/Dynamic-Wallpapers/fonts/ToThePointRegular-n9y4.ttf");
        sf::Text text(font);
        std::string info = "Hello there, I am Martin Wainaina, I kinda like c++ and the low level stuff. I am eager to learn and also interested in AI, ML and Neural Networks!";
        text.setString(info);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::Blue);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }else if(const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
                window.draw(text);
            }
        }

        window.clear(sf::Color::Black);
        window.display();
        
    }

    return 0;
}