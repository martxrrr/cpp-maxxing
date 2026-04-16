#include <iostream>
#include <optional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

void loadSprite(){
    std::cout << "LOADING AN IMAGE, CREATING A SPRITE FROM IT" << std::endl;
    std::cout << "MODIFYING DIMENSIONS AND ROTATIONS" << std::endl;
    std::cout << "and I am kinda moving slow, I need to start building stuff in the next 5-7 days" << std::endl;
}


int main(){

    loadSprite();

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "SPRITES AND TEXTURES");

    sf::Texture texture;
    if(!texture .loadFromFile("/home/martin/programming/MAIN/C++/100daysOfCpp/day18/assets/bash.jpg")){
        return -1;
    }
    sf::Sprite sprite(texture);
    sprite.setTextureRect(sf::IntRect({10, 10}, {32, 32}));
    sprite.setColor(sf::Color(65, 124, 134));

    //position

    sprite.setPosition({750.f, 450.f});
    sprite.move({5.f, 10.f});

    //by default the origin of a sprite is the top-left corner
    //to change that:

    //sprite dimensions
    sf::Vector2u dimensions = texture.getSize();
    float x = dimensions.x;
    float y = dimensions.y;
    sprite.setOrigin({x/2, y/2});

     //rotation
    sprite.setRotation(sf::degrees(90)); //absolute angle
    sprite.rotate(sf::degrees(20)); //offset relative to the current angle


    while(window.isOpen()){
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }
        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display();
    }
    
    return 0;
}