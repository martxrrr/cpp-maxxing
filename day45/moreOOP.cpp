#include <iostream>

class Animal{
    private:
        int legs;
        std::string skin;
        bool nightVision;
    public:
        Animal(){
            std::cout << "[ANIMAL] Created! ...\n";
        }

        virtual ~Animal(){
          std::cout << "[ANIMAL] Destroyed! ...\n";
        }

        virtual void speak() const {
            std::cout << "(Silence) ...\n"; 
        }
};


class Dog : public Animal {
    public:
        Dog(){
            std::cout << "[DOG] Created! ...\n";
        }

        ~Dog() override {
            std::cout << "[DOG] Destroyed! ...\n";
        }
        void speak() const override {
            std::cout << "Dog says woof!!! \n";
        }
};

//marking a class final ensures that no subclass will be derived from it 
//you can also mark a method final meaning no class inheriting from that class can override that
//method
class Cat : public Animal {
    public:
        Cat(){
            std::cout << "[CAT] Created! ...\n";
        }

        ~Cat() override {
            std::cout << "[CAT] Destroyed! ...\n";
        }
        void speak() const override {
            std::cout << "Cat says meeoow!!! \n";
        }
};

class Lion : public Cat { 
    public:
        Lion(){
            std::cout << "[LION] Created! ...\n";
        }

        ~Lion() override {
            std::cout << "[LION] Destroyed! ...\n";
        }

        void speak() const override {
            std::cout << " Lion says Roar!!!\n";
        }

};

class Shape {
public:
    virtual double area() const { return 0.0; }
    
    virtual ~Shape() = default;

};

class Circle : public Shape {
protected:
    double radius_;
public:
    explicit Circle(double r) : radius_(r) {}

    double area() const override {
        return 3.1415926535 * radius_ * radius_ ;
    }
};

class FixedCircle final : public Circle {
public:
    explicit FixedCircle(double r) : Circle(r) {}

    double area() const final {
        return 3.1415926535 * radius_ * radius_ ;
    }

};

int main(){

    Cat Sora;
    Sora.speak();

    Dog scooby;
    scooby.speak();

    Lion danger;
    danger.speak();
  
    //Polymorphism through base pointer — correct area() called each time
    {
        Shape baseShape;
        Circle wheel(17.5);
        FixedCircle hubcap(7.0);

        Shape* shapes[] = { &baseShape, &wheel, &hubcap };
        const char* names[] = { "Base Shape", "Wheel (17.5 radius )", "Hubcap (radius = 7.0)" };

        for(int i = 0; i < 3; i++){
            std::cout << names[i] << " Area = " << shapes[i]->area() << std::endl;
        }
    }

    return 0;
}
/*
virtual tells the compiler to do late binding or runtime polymorphism

'override' ensures we are truly overriding a base virtual method
It tells the compiler: "I intend to override a virtual function in the base class. If I'm wrong (e.g., wrong signature), give me a compile error."


A pure virtual method in C++ is a virtual function declared in a base class with = 0 and no implementation, forcing all non-abstract derived classes to provide their own definition
*/
