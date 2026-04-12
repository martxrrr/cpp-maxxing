//CORDINATING USER EVENTS AND USER INPUT
//AND ALSO PASSING EVENTS TO A FUNCTION

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <tuple>

void  mouseClick(sf::RenderWindow &window, const sf::Event &event){
    if(const auto* mouseClick = event.getIf<sf::Event::MouseButtonPressed>()){
        if(mouseClick->button == sf::Mouse::Button::Left){
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int mouse_x = pos.x;
            int mouse_y = pos.y;

            std::cout << "(" << mouse_x << "," << mouse_y << ")" << std::endl;

        }
    }
}

void anotherMouse(sf::RenderWindow &window, sf::CircleShape &circ, const sf::Font &font, sf::Text &text){

    std::string info = "Drawing 2D sprites";
    text.setFont(font);
    text.setCharacterSize(30);
    text.setString(info);
    text.setFillColor(sf::Color::Green);
    text.setStyle(sf::Text::Italic | sf::Text::Underlined);

    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        sf::Vector2i position = sf::Mouse::getPosition();
        float posX = position.x;
        float posY = position.y;
        
        circ.setPosition({posX, posY});
        circ.setFillColor(sf::Color::Blue);
        circ.setPointCount(100);

        window.draw(circ);
        window.draw(text);
        
        std::cout << "(" << posX << "," << posY << ")" << std::endl;
    }
}

int main(){
    sf::RenderWindow window(sf::VideoMode({1500, 900}), "SPRITES AND 2D STUFF!");
    sf::CircleShape circ(100.f);
    sf::RectangleShape rect({100.f, 100.f});
    rect.setSize({100.f, 100.f});
    rect.setFillColor(sf::Color::Cyan);
    rect.setPosition({300.f, 300.f});

    sf::Font font("/home/martin/Pictures/wallpapers/Dynamic-Wallpapers/fonts/ToThePointRegular-n9y4.ttf");
    sf::Text text(font);

    bool visible = true;
    
    while(window.isOpen()){
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
                if(keyPressed->scancode == sf::Keyboard::Scancode::Space){
                    visible = !visible;
                }
            }
            // mouseClick(window, *event);
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            rect.move({0.1f, 0.f}); //{x, y} : x for moving right y for moving up
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            rect.move({-0.1f, 0.f}); //{x, y} : -x for moving left -y for moving down
        }

        window.clear(sf::Color::Black);
        anotherMouse(window, circ, font, text);
        if(visible){
            window.draw(rect);
        }
        window.draw(rect);
        window.display();
    }

    return 0;
}