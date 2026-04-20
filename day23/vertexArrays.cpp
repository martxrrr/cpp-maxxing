/*
                _                                             
__   _____ _ __| |_ _____  __   __ _ _ __ _ __ __ _ _   _ ___ 
\ \ / / _ \ '__| __/ _ \ \/ /  / _` | '__| '__/ _` | | | / __|
 \ V /  __/ |  | ||  __/>  <  | (_| | |  | | | (_| | |_| \__ \
  \_/ \___|_|   \__\___/_/\_\  \__,_|_|  |_|  \__,_|\__, |___/
                                                    |___/ 

*/
//this shit sucks tbh
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>

int main(){
    int FPS = 60;
    sf::RenderWindow window(sf::VideoMode({1500, 900}), "PONG");
    window.setFramerateLimit(FPS);

    // sf::Vertex vertex;
    // vertex.color = sf::Color::Red;
    // vertex.position = sf::Vector2f(10.f, 50.f);
    // vertex.texCoords = sf::Vector2f(100.f, 100.f);

    // //OR - aggregate initialization
    // sf::Vertex vertex{{10.f, 50.f}, sf::Color::Red, {100.f, 100.f}};

    //create an array of 3 vertices that define a triangle primitive
    sf::VertexArray triangle(sf::PrimitiveType::Triangles, 3);

    //define the vertices location
    triangle[0].position = sf::Vector2f({10.f, 10.f});
    triangle[1].position = sf::Vector2f({100.f, 10.f});
    triangle[2].position = sf::Vector2f({100.f, 100.f});

    //define the colors
    triangle[0].color = sf::Color::Red;
    triangle[1].color = sf::Color::Blue;
    triangle[2].color = sf::Color::Green;

    //other primitive types
    sf::PrimitiveType::Lines;
    sf::PrimitiveType::LineStrip;
    sf::PrimitiveType::Triangles;
    sf::PrimitiveType::TriangleStrip;
    sf::PrimitiveType::Points;
    sf::PrimitiveType::TriangleFan;

    
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
        window.clear();
        window.draw(triangle);
        window.display();
    }

    return 0;
}