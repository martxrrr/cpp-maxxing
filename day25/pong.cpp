/*
 ____   ___  _   _  ____        ____    _    __  __ _____ 
|  _ \ / _ \| \ | |/ ___|      / ___|  / \  |  \/  | ____|
| |_) | | | |  \| | |  _ _____| |  _  / _ \ | |\/| |  _|  
|  __/| |_| | |\  | |_| |_____| |_| |/ ___ \| |  | | |___ 
|_|    \___/|_| \_|\____|      \____/_/   \_\_|  |_|_____|
*/

#include <iostream>
#include <optional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int randDir(){
    srand(time(NULL));
    int min{1};
    int max{3};

    int num =  (rand() % max) + min;
    return num;
}

int main(){

    std::string title = R"(
 ____   ___  _   _  ____        ____    _    __  __ _____ 
|  _ \ / _ \| \ | |/ ___|      / ___|  / \  |  \/  | ____|
| |_) | | | |  \| | |  _ _____| |  _  / _ \ | |\/| |  _|  
|  __/| |_| | |\  | |_| |_____| |_| |/ ___ \| |  | | |___ 
|_|    \___/|_| \_|\____|      \____/_/   \_\_|  |_|_____|
    )";

    std::cout << title << std::endl;

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "PONG");
    window.setFramerateLimit(60);

    int player1Score{0};
    int player2Score{0};

    sf::Font font("/home/martin/programming/MAIN/C++/100daysOfCpp/day25/ToThePointRegular-n9y4.ttf");
    sf::Text text1(font);
    sf::Text text2(font);
    text1.setString(std::to_string(player1Score));
    text2.setString(std::to_string(player2Score));
    text1.setFillColor(sf::Color::Green);
    text2.setFillColor(sf::Color::Cyan);
    text1.setCharacterSize(50);
    text2.setCharacterSize(50);
    text1.setStyle(sf::Text::Bold);
    text2.setStyle(sf::Text::Bold);
    text1.setPosition({30.f, 30.f});
    text2.setPosition({1400.f, 30.f});


    sf::Vector2u dimensions = window.getSize();
    float width = dimensions.x;
    float height = dimensions.y;

    float vel = 15;
    bool bounce = true;
    float ballVel = 6.0;
    float acclr = 0.02;

    sf::RectangleShape player1;
    player1.setSize({50.f, 250.f});
    player1.setOrigin({25.f, 125.f});
    player1.setPosition({25, 450});
    player1.setFillColor(sf::Color::Green);

    sf::RectangleShape player2;
    player2.setSize({50.f, 250.f});
    player2.setOrigin({25.f, 125.f});
    player2.setPosition({1475, 450});
    player2.setFillColor(sf::Color::Cyan);

    sf::CircleShape ball(20.f);
    ball.setOrigin({ball.getRadius(), ball.getRadius()});
    ball.setFillColor(sf::Color::Red);
    ball.setPosition({width/2, height/2});

    
    while(window.isOpen()){

        while(std::optional event = window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }else if(const auto* key = event->getIf<sf::Event::KeyPressed>()){
                if(key->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }
        }

        sf::FloatRect bounds1 = player1.getGlobalBounds();
        sf::FloatRect bounds2 = player2.getGlobalBounds();
        sf::FloatRect bounds3 = ball.getGlobalBounds();

        sf::Vector2f player1Pos = player1.getPosition();
        sf::Vector2f player2Pos = player2.getPosition();


        sf::Vector2f pos = ball.getPosition();
        float posX = pos.x;
        float posY = pos.y;


        auto collGreen = bounds1.findIntersection(bounds3);
        auto collRed = bounds2.findIntersection(bounds3);

        if(bounce){ 
            int choice = randDir();
            switch(choice){
                case 1:
                    if(player2Pos.y <= 470){
                        ball.move({ballVel, 1.f});
                        player2Score += 2;
                    }
                    else if(player2Pos.y > 470){
                        ball.move({ballVel, 1.f});
                        player2Score += 2;
                    }
                    break;
                case 2:
                    if(player2Pos.y <= 470){
                        ball.move({ballVel, 2.f}); 
                    }else if(player2Pos.y > 470){
                        ball.move({ballVel, -2.f});
                        player2Score += 2;
                    }
                    break;
                case 3:
                    if(player2Pos.y <= 470){
                        ball.move({ballVel, 4.f}); 
                        player2Score += 2;
                    }else if(player2Pos.y > 470){
                        ball.move({ballVel, -4.f});
                        player2Score += 2;
                    }
                    break;
            }
            ballVel += 0.02;
        }
        if (collRed.has_value()){ bounce = false; }

        if(!bounce){
            int choice = randDir();
            switch(choice){
                case 1:
                    if(player1Pos.y <= 470){
                        ball.move({-ballVel, 1.f}); 
                        player1Score += 2;
                    }else if(player1Pos.y > 470){
                        ball.move({-ballVel, -1.f});
                        player1Score += 2;
                    }
                    break;
                case 2:
                    if(player1Pos.y <= 470){
                        ball.move({-ballVel, 2.f}); 
                        player1Score += 2;
                    }else if(player1Pos.y > 470){
                        ball.move({-ballVel, -2.f});
                        player1Score += 2;
                    }
                    break;
                case 3:
                    if(player1Pos.y <= 470){
                        ball.move({-ballVel, 4.f}); 
                        player1Score += 2;
                    }else if(player1Pos.y > 470){
                        ball.move({-ballVel, -4.f});
                        player1Score += 2;
                    }
                    break;
            }
            ballVel += 0.02;  
        }
        if(collGreen.has_value()){
            int choice = randDir();
            switch(choice){
                case 1:
                    if(player2Pos.y <= 470){
                        ball.move({ballVel, 1.f});
                        player2Score += 2;
                    }else if(player2Pos.y > 470){
                        ball.move({ballVel, -1.f});
                        player2Score += 2;
                    }
                    break;
                case 2:
                    if(player2Pos.y <= 470){
                        ball.move({ballVel, 2.f});
                        player2Score += 2;
                    }else if(player2Pos.y > 470){
                        ball.move({ballVel, -2.f});
                        player2Score += 2;
                    }
                    break;
                case 3:
                    if(player2Pos.y <= 470){
                        ball.move({ballVel, 4.f});
                        player2Score += 2;
                    }else if(player2Pos.y > 470){
                        ball.move({ballVel, -4.f});
                        player2Score += 2;
                    }
                    break;
            } 
            bounce = true;
            ballVel += 0.02;
        }

        if(posX < 0){
            std::cout << "CYAN[PLAYER 2] WINS!" << std::endl;
            return -1;
        }
        if(posX > 1500){
            std::cout << "GREEN [PLAYER 1] WINS!" << std::endl;
            return -1;
        }

        

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){ 
            player1.move({0.f, -vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ){
            player1.move({0.f, vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            player2.move({0.f, -vel});
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            player2.move({0.f, vel});
        }

        float player1y = player1Pos.y;
        float player2y = player2Pos.y;
        
        if(player1Pos.y < 120){ player1.move({0.f, vel}); }
        if(player1Pos.y > 780){ player1.move({0.f, -vel}); }

        if(player2Pos.y < 120){ player2.move({0.f, vel}); }
        if(player2Pos.y > 780){ player2.move({0.f, -vel}); }

        window.clear();
        window.draw(player1);
        window.draw(player2);
        window.draw(ball);
        window.draw(text1);
        window.draw(text2);
        window.display();
    }

    return 0;
}