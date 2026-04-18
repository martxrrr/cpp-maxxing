#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>

using namespace sf::Literals;

void displayWindow(sf::RenderWindow &window){
    sf::RenderWindow window(sf::VideoMode({1500, 900}), "EFFECTS AND CAMERA!");
}
void angles(sf::Angle &angle){
    sf::Angle angle1 = sf::degrees(45);
    sf::Angle angle2 = sf::radians(3.1415f);

    //====================
    // ANGLE ARITHMETIC //
    //====================
    angle1 *= 2.f; //becomes 90
    angle2 = angle1 + sf::radians(0.5f); //converts the radians to degrees and adds them together
    angle2 = -angle2; //makes the angle -ve
    angle2 /= 2; //divides angle2 by 2


    //=======================================================
    // CONFINING ANGLES TO RANGE i.e [-pi, pi] or [0, 2pi] //
    //=======================================================
    sf::Angle angle3 = sf::degrees(540).wrapUnsigned(); //put in the range [-pi, pi]
    sf::Angle angle4 = sf::radians(2 * 3.1415f).wrapSigned(); //put in the range [0, 2pi]

    //=========================
    // USER-DEFINED LITERALS //
    //========================
    sf::Angle angle5 = 45_deg; //45 degrees
    sf::Angle angle6 = angle5 + 3.1415_rad; // 45 + 180 = 225 degrees

    //===============================
    // ACCESSING UNDERLYING VALUES //
    //===============================
    sf::Angle angle7 = sf::degrees(180);
    std::cout << angle7.asRadians() << std::endl;
    sf::Angle angle8 = sf::radians(2);
    std::cout << angle8.asDegrees() << std::endl;
}


void Time(sf::Time &time, sf::Clock &clock){
    sf::Time t1 = sf::microseconds(1000);
    sf::Time t2 = sf::milliseconds(10);
    sf::Time t3 = sf::seconds(0.01);

    //==============
    // CONVERSION //
    //==============
    sf::Time time = sf::seconds(1);
    std::int64_t microsec = time.asMicroseconds();
    std::int32_t millisec = time.asMilliseconds();
    float sec = time.asSeconds();

    //========================
    // ARITHMETIC OPERATION //
    //========================
    sf::Time t4 = sf::seconds(10);
    sf::Time t5 = sf::seconds(20);

    sf::Time t6 = t4 + t5;
    bool equal = (sec == microsec);

    //==========
    // CLOCK //
    //========
    sf::Clock clock;
    clock.start(); //starts the clock

    sf::Time elapsedT = clock.getElapsedTime(); //returns the elapsed time
    std::cout << elapsedT.asSeconds() << std::endl;
    clock.restart(); //restarts the clock and also returns the elapsed time before restarting   

    sf::Time elapsedT2 = clock.getElapsedTime();
    std::cout << elapsedT2.asMilliseconds() << std::endl;

    clock.stop(); //stops the clock
    std::cout << std::boolalpha << clock.isRunning() << std::endl; //returns either true or false depending on whether the clock i running
    clock.reset(); //resets the clock

    clock.start();
    std::cout << "Elapsed Time: " << elapsedT2.asMicroseconds() << std::endl;
}


int main(){
    sf::RenderWindow window;
    sf::Angle angle;

    displayWindow(window);
    angles(angle);

    
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