//Tough weekend, so tired and busy but game is game, I have to write c++ everyday
//not gonna learn anything new today, but I will just write a simple program to recap what I learnt last time

#include <iostream>
#include "salary.hpp"

int main(){
    
    Bro martin;
    double salary = martin.getSalary(4, false);
    std::cout << "Martin made Ksh." << salary << std::endl;

    int gfs;
    std::cout << "Enter the number bros exGfs: ";
    std::cin >> gfs;
    int gf = martin.huzz(gfs);

    if(gf == 1){
        std::cout << "Bro got huzz 😍" << std::endl;
    }else{
        std::cout << "Bro got no huzz 🤕" << std::endl;
    }

    return 0;
}