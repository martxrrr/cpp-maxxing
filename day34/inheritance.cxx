//BASIC INHERITANCE AND POLYMORPHISM
#include <iostream> 


//SINGLE INHERITANCE
class Animal{
public:
    int limbs;
    std::string skin;
    std::string vision;

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
    void printInfo(){
        std::cout << "Limbs: " << limbs << "\n";
        std::cout << "Skin: " << skin << "\n";
        std::cout << "Vision: " << vision << "\n";
    }
};

//Lana del Rey is so sexy and her songs make her even sexier
class Dog : public Animal{
public:
    std::string language;
    std::string vision;

    void Talk(){
        std::cout << "WOOF!" << std::endl;
    }
    void See(){           //members derived privately can not be accessed outside the class but can be accessed
        Animal::Vision(); // inside the derived class using the scope operator
    }
 
};

class Cat : public Animal{
    std::string language;
    std::string vision;
    public:
    void Talk(){
        std::cout << "MEOW!" << std::endl;
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
    void Limbs(){
        limbs = 2;
        std::cout << "I have " << limbs << " legs" << std::endl;
    }
};

class Extra{
protected:
    void extra(){
        std::cout << "I am just an extra class" << "\n";
    }
};

//MULTIPLE INHERITANCE - two or more base classes for one class
//now the fox class has features from class Animal and class Extra
//nesting multiple and multilevel inheritance can cause ambiguity

class Fox : public Animal, public Dog {};


/*MULTILEVEL INHERITANCE - A -> B -> C
    -Jackal inherits from Dog while Dog inherited from Animal
    -You can call public members of Jackal class, Dog class and Animal class as long as they are publicly inherited
    -To call a member outside of a class, it has to be publicy inherited but to access it inside the derived class
     but to access it inside the derived class (publicly or privately inherited), you can just use the scope operator
*/

class Jackal : public Dog {
public:
    void myLore(){
        std::cout << "I am a fucking wild dog" << "\n";
    }
};


int main(){
    Dog scooby;
    Cat kitty;
    Bat dracula;
    Fox muthige;
    Jackal hunter;

    // dracula.Limbs();
    // dracula.Skin();
    // dracula.Talk();
    // dracula.Vision();

    // std::cout << std::endl;

    // kitty.Limbs();
    // kitty.Skin();
    // kitty.Talk();
    // kitty.Vision();

    // std::cout << std::endl;

    // scooby.Limbs();
    // scooby.Skin();
    // scooby.Talk();
    // scooby.See();

    // muthige.printInfo();
    muthige.extra();

    hunter.printInfo();
    hunter.Talk();
    hunter.myLore();

    std::cout << std::endl;

    return 0;
}

/*Protected member functions can be inherited but with some few notes

Private Inheritance (protected base - private derived)
Protected members become private members of the derived class 
They are accessible to the class member functions but they are NOT derived further i.e multilevel inheritance

Public Inheritance (protected base - public derived)
They remain protected in the derived class and any further derived classes but cannot 
be accessed outside the class
They can be inherited again and again (multilevel inheritance) and will remain protected members of the derived class

Protected Inheritance (protected base - protected derived)
They remain protected in the derived class and any firther derived classes 

NOTE: In every case of inheritance, private members remain inaccessible outside the class they belong in

nesting multilevel inheritance and multiple inheritance can cause inheritance example:
in the classes above, if class Fox inherits from class Animal and class Dog while Dog inherits from Animal there is going to be ambiguity
if we call a function in the class Animal, coz the function is also available in class Dog since it inherited from the Animal
The compiler will throw an ambiguity error because there are more than one function with the same name
*/