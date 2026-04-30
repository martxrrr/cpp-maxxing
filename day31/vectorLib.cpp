#include <iostream>
#include <vector>


struct Player{
    std::string loc;
    int health;

    Player(std::string loc, int health) : loc(loc), health(health) {}
};



int main(){

    std::vector<Player> player;
    player.reserve(3);
    player.emplace_back("Kenya", 120);
    player.emplace_back("Germany", 139);
    player.emplace_back("Japan", 167);
    


    return 0;
}