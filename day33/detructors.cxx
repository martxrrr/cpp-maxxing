#include <iostream>


class Teacher{
private:
	std::string name = "Wafula";
	int age = 21;

	void printInfo(){
		std::cout << "Name: " << name << "\n";
		std::cout << "Age: " << age << "\n";
	}

	friend void getInfo(Teacher teacher);
};

void getInfo(Teacher teacher){
	std::cout << "Name: " << teacher.name << "\n";
	std::cout << "Age: " << teacher.age << "\n";
}

int main(){

	Teacher t1;
	getInfo(t1);


	return 0;
}

/*
Destructors
-a special member function of a class that gets executed when an object of that class
 gets out of scope or gets explicitly deleted
-main aim is to release the resources acquired by the object during its lifetime
-every class can have exactly one destructor:
	1. have the same name as the class
	2. preceeded by a tilde (~)
	3. no overloading,because it takes no parameters
	4. no return type, not even void
	5. It is not called manually, the compiler handles it automatically

-detruction order is the reverse of construction order i.e
	1. Members - constructed first to last; destroyed last to first
	2. Inheritance - Base class constructed before Derived class; Derived class destroyed before Base class

A friend function is a mechanism that grants non-member functions or other classes full access privileges to the private and protected sectors of a class.
can be declared in the private, public or protected sections

*/