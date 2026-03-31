//I have been really busy today, but I just has to show up for c++
//writing bullshit code in the most beginner way possible is better than writing none

//===========================
// ROCK - PAPER - SCISSORS //
//===========================

#include <iostream>

std::string getWinner(int userchoice, int computerChoice){
    if (userchoice == computerChoice){
        return "draw";
    }
    else if(userchoice == 1 && computerChoice == 2){
        return "lose";
    }
    else if(userchoice == 2 && computerChoice == 3){
        return "lose";
    }else if(userchoice == 3 && computerChoice == 1){
        return "lose";
    }
    else{
        return "win";
    }
}

int main(){


    int userChoice;
    srand(time(NULL)); int max = 3; int min = 1;
    int computerChoice = (rand() % max) + min;

    while (true){
        std::cout << " ***** ROCK * PAPER * SCISSORS ******" << std::endl;
        std::cout << "Choose one of the options: " << std::endl;
        std::cout << "1. Rock\n2. Paper\n3. Scissors\n";
        std::cout << "Your choice: ";
        std::cin >> userChoice;

        if(userChoice == 1){
            std::cout << "You chose Rock!\n";
        }
        else if(userChoice == 2){
            std::cout << "You chose Paper!\n";
        }
        else if(userChoice == 3){
            std::cout << "You chose Scissors!\n ";
        }

        if(computerChoice == 1){
            std::cout << "Computer chose Rock!\n";
        }
        else if(computerChoice == 2){
            std::cout << "Computer chose Paper!\n";
        }
        else if(computerChoice == 3){
            std::cout << "Computer chose Scissors!\n ";
        }


        std::string winner = getWinner(userChoice, computerChoice);
        if (winner == "draw"){
            std::cout << "It is a DRAW!\n";
        }
        else if(winner == "lose"){
            std::cout << "You LOSE!\n";
        }
        else if(winner == "win"){
            std::cout << "You WIN!\n";
        }
    }

    return 0;
}