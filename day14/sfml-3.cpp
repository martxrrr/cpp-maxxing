#include <iostream>
#include <optional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>



int main(){

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "SFML day 3", sf::Style::Close | sf::Style::Titlebar);

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

        //circle
        sf::CircleShape circle1(50.f);
        circle1.setFillColor(sf::Color(18, 34, 107));
        circle1.setOutlineThickness(4.f);
        circle1.setOutlineColor(sf::Color(21, 206, 211));
        circle1.setPointCount(100);


        // //rectangle
        sf::RectangleShape rect1({100.f, 90.f}); //define dimensions
        rect1.setSize({150.f, 100.f});

        //polygons
        //sfml does not have a specific way to draw a circle or rather a polygon
        //a circle is a bunch of triangles arranged in a way to look like a circle
        //the same as any other polygon, so to draw a polygon, we just use the circle class and reduce the number of triangle
        sf::CircleShape triangle(80.f, 3);
        triangle.setFillColor(sf::Color(171, 25, 204));

        sf::CircleShape square(80.f, 4);
        square.setFillColor(sf::Color(204, 25, 68));

        sf::CircleShape nonagon(130.f, 9);
        nonagon.setFillColor(sf::Color(171, 25, 204));

        //drawing convex shapes - u can draw anything
        sf::ConvexShape heart;
        heart.setPointCount(5);
        heart.setPoint(0, {0.f, 0.f});
        heart.setPoint(1, {150.f, 10.f});
        heart.setPoint(2, {120.f, 90.f});
        heart.setPoint(3, {30.f, 100.f});
        heart.setPoint(4, {0.f, 50.f});

        //lines
        //a line in sfml is basically a rectangle with very small width
        sf::RectangleShape line({600.f, 1.f});
        line.setFillColor(sf::Color(204, 25, 68));
        line.rotate(sf::degrees(45)); 


        window.draw(circle1);
        window.draw(rect1); 
        window.draw(triangle);
        window.draw(square);
        window.draw(nonagon);
        window.draw(line);

        window.display();
    }

    return 0;
}
//shit kinda fun, can't wait for tomorrow,
//I do not like learning too many stuff at once, I will end up forgetting, tommorrow more fun stuff