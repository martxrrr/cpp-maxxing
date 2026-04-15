#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>

void printFloat(float val){
    std::cout << val << std::endl;
}


int main(){

    sf::Texture texture;
    if(!texture.loadFromFile("/home/martin/programming/MAIN/C++/100daysOfCpp/day19/assets/bash.jpg")){
        return -1;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition({750, 450});

    //set the absolute rotation of the entity
    // sprite.setRotation(sf::degrees(45));
    sf::Angle rotation = sprite.getRotation();

    //retrieve the absolute position of an entity in this case, the sprite
    sf::Vector2f position = sprite.getPosition();
    float x = position.x;
    float y = position.y;

    std::cout << "X: " << x << "\nY: " << y << std::endl;


    //==============
    //SCALE FACTOR//
    //==============
    //set the absolute scale of the entity
    // sprite.setScale({2.0f, 1.5f});
    sprite.scale({1.5f, 1.5f}); //scale relative to  its current scale
    sf::Vector2f scale = sprite.getScale(); //retrieve the absolute scale
    float X = scale.x;
    float Y = scale.y;
    printFloat(X);
    printFloat(Y);

    //==============
    //   ORIGIN   //
    //==============
    auto bounds = sprite.getLocalBounds();
    float valueX = bounds.size.x;
    float valueY = bounds.size.x; //now you can set the origin by dividing the x and y by or use this pro tip below
    sprite.setOrigin(sprite.getLocalBounds().getCenter());
    sf::Vector2f center = sprite.getOrigin();
    float originX = center.x;
    float originY = center.y;
    printFloat(originX);
    printFloat(originY);

    //===================
    //   TRANSLATION   //
    //===================
    sf::Transform t;
    t.translate({10.f, 100.f});
    t.rotate(sf::degrees(45.f));
    t.translate({-10.f, 50.f});
    t.scale({0.5f, 0.75f});    

    //====================
    //   BOUNDING BOX   //
    //====================
    //useful for checking for collisions
    sf::FloatRect bounds = sprite.getGlobalBounds();
    sf::Vector2f point = {750.f, 450.f};
    if(bounds.contains(point)){
        std::cout << "Colllision with the specified point!" << std::endl;
    }else{
        std::cout << "No collision detected!" << std::endl;
    }

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "ROTATIONS AND TRANSFORMATIONS");
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

        window.clear(sf::Color::Black);

        // window.draw(sprite, t); //you can also pass in a transformation if you want to transform an entity
        window.draw(sprite);

        window.display();
    }


    return 0;
}