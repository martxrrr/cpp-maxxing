//==============================
// CAMERA AND SPECIAL EFFECTS //
//==============================

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode({1800, 900}),"CAMERA AND SPECIAL EFFECTS");

    // create a view with the rectangular area of the 2D world to show
    sf::View view1(sf::FloatRect({200.f, 200.f}, {300.f, 200.f}));
    // create a view with its center and size
    sf::View view2({350.f, 300.f}, {300.f, 200.f});
    sf::View view1;

    view1 = sf::View(sf::FloatRect({200.f, 200.f}, {300.f, 200.f}));
    sf::View view2;
    view2.setCenter({350.f, 300.f});
    view2.setSize({200.f, 200.f});

    //======================
    // SCROLLING THE VIEW //
    //======================
    // move the view at point (200, 200)
    sf::View view;
    view.setCenter({200.f, 200.f});
    // move the view by an offset of (100, 100) (so its final position is (300, 300))
    view.move({100.f, 100.f});

    //======================
    // ROTATING THE VIEW //
    //=====================
    view.setRotation(sf::degrees(20));
    view.rotate(sf::degrees(5));

    //===========
    // ZOMMING //
    //===========
    // resize the view to show a 1200x800 area (we see a bigger area, so this is a zoom out)
    view.setSize({1200.f, 800.f});
    view.zoom(0.5f);

    //============
    // VIEWPORT //
    //============
    view.setViewport(sf::FloatRect({0.25f, 0.25}, {0.5f, 0.5f}));
    //======================
    // SPLITTING THE SCREEN
    //=====================
    sf::View player1View;
    sf::View player2View;
    player1View.setViewport(sf::FloatRect({0.f, 0.f}, {0.5f, 1.f}));
    player2View.setViewport(sf::FloatRect({0.5f, 0.f}, {0.5f, 1.f}));

    //======================
    // DRAW SOMETHING USING A VIEW
    // let's define a view
    sf::View view(sf::FloatRect({0.f, 0.f}, {1000.f, 600.f}));
    window.setView(view);
    window.draw(sprite);
    sf::View currentView = window.getView();



    //============================
    // COORDINATE CONVERSIONS
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);


    while(window.isOpen()){
        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }else if(const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if(keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }

        window.clear(sf::Color::Black);
        window.display();

    }

    return 0;
}