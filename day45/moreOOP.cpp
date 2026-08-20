#include <iostream>
#include <utility> //offers functionalities primarily focusing on pairs, swapping, and move semantics. 
#include <cstring> //provides a collection of functions for working with C-style strings

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


//a class demostrating rule of 3
class StringBox{
  private:
      size_t length;
      char *data;
  public:
      StringBox(const char* text){
          length = std::strlen(text);

          data = new char[length + 1];
          std::strcpy(data, text);
      }

      //RULE OF 3 BEGINS
      //1. DESTRUCTOR
      ~StringBox (){
          std::cout << "[DELETING] " << data << std::endl;
          delete[] data;
      }

      //2. COPY CONSTRUCTOR
      StringBox(const StringBox& other){
          length = other.length;
          std::cout << "[DEEP COPYING] " << other.data << "...\n";
          
          //never do data = other.data because that is going to be a shallow copy
          //always allocate new memory
          data = new char[length + 1]; //the +1 is for the null terminator
          std::strcpy(data, other.data);
      }

      //2. COPY ASSIGNMENT OPERATOR - use when an object is intantiated an assigned
      //   to another object : like a = b
      //   so b is already constructed and it's items are already in memory, so we have to
      //   free that memory before reassigning the values
      StringBox& operator=(const StringBox& other){
          if(this == &other){ //prevent self-assignment
              return *this;
          }

          std::cout << "Overwriting data with " << other.data << std::endl;

          delete[] data;

          length = other.length;
          data = new char[length + 1];
          std::strcpy(data, other.data);

          return *this;
      }

      void Print(){
          std::cout << "Box content : " << data << std::endl;
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