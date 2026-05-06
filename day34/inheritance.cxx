//BASIC INHERITANCE AND POLYMORPHISM
#include <iostream>

class Animal{
    int limbs;
    std::string skin;
    std::string vision;

    public:
    Animal(){
        this->limbs = 4;
        this->skin = "Fur";
        this->vision = "I am neutral, I see Night and Day like a true chad";
    }
    void Limbs(){
        std::cout << "I have " << limbs << " legs" << std::endl;
    }
    void Skin(){
        std::cout << "My body is covered with " << skin << " \n";
    }
    void Vision(){
        std::cout << vision << std::endl;
    }
};

class Dog : public Animal{
    std::string language;
    std::string vision;

    public:
    void Talk(){
        std::cout << "WOOF!" << std::endl;
    }
    void Vision(){
        vision = "Woof! The realest CHAD here, I am made for this sh!t";
        std::cout << vision << std::endl;
    }

    
};

class Cat : public Animal{
    std::string language;
    std::string vision;
    public:
    void Talk(){
        std::cout << "MEOW!" << std::endl;
    }
    void Vision(){
        vision = "Meow! The night is made for me, but during the day, I can barely see!";
        std::cout << vision << std::endl;
    }
};

class Bat : public Animal{
    std::string language;
    std::string vision;
    int limbs;
    public:
    void Talk(){
        std::cout << "SQUEEK!" << std::endl;
    }
    void Vision(){
        vision = "Squeek! I can't see at night twin";
        std::cout << vision << std::endl;
    }
    void Limbs(){
        limbs = 2;
        std::cout << "I have " << limbs << " legs" << std::endl;
    }
};

int main(){
    Dog scooby;
    Cat kitty;
    Bat dracula;

    dracula.Limbs();
    dracula.Skin();
    dracula.Talk();
    dracula.Vision();

    std::cout << std::endl;

    kitty.Limbs();
    kitty.Skin();
    kitty.Talk();
    kitty.Vision();

    std::cout << std::endl;

    scooby.Limbs();
    scooby.Skin();
    scooby.Talk();
    scooby.Vision();

    std::cout << std::endl;

    return 0;
}