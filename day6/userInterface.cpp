//I discovered the SFML library today, a library for basically handling 2D GUI
//I think it is a great place to practice c++

//shit was a headache to setup nkt!!
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


int main(){

    sf::RenderWindow window(sf::VideoMode(1800, 1200), "CPP-MAXXING", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    while(window.isOpen()){

        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    break;
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape){
                        window.close();
                        break;
                    }
            }
        }
        window.clear(sf::Color(124, 56, 76));
        window.display();
    }

    return 0;
}