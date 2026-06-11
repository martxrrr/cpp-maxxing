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


class Temperature {
private:
    double celsius;

public:
    Temperature(double c) : celsius(c) {}
    friend void printFahrenheit(Temperature t); 
};

void printFahrenheit(Temperature t) {
    double fahrenheit = (t.celsius * 9.0 / 5.0) + 32.0;
    std::cout << "Temperature: " << fahrenheit << "F" << std::endl;
}

//member function of another class as a friend

class Account; 

class Auditor {
public:
    void auditAccount(const Account& acct);
};

class Account {
private:
    double balance;

public:
    Account(double b) : balance(b) {}
    friend void Auditor::auditAccount(const Account& acct);
};

void Auditor::auditAccount(const Account& acct) {
    std::cout << "Auditing Balance: $" << acct.balance << std::endl;
}

//friend classes
class Engine {
private:
    int horsepower;
    bool isRunning;

public:
    Engine(int hp) : horsepower(hp), isRunning(false) {}

    friend class Dashboard; 
};

class Dashboard {
public:
    void ignite(Engine& e) {
        e.isRunning = true; 
        std::cout << "Engine ignited." << std::endl;
    }

    void showStatus(const Engine& e) {
        std::cout << "Engine HP: " << e.horsepower 
                  << " | Status: " << (e.isRunning ? "ON" : "OFF") << std::endl;
    }
};


int main(){

	Teacher t1;
	getInfo(t1);

	Temperature temp(25.0);
    printFahrenheit(temp); 

    Account myAcc(5000.50);
    Auditor externalAuditor;
    externalAuditor.auditAccount(myAcc);

    Engine v8(450);
    Dashboard dash;
    
    dash.showStatus(v8);
    dash.ignite(v8);
    dash.showStatus(v8);


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

Friendship is not mutual
Friednship is not transitive
Frienship is not inherited

It is not a member of the class, meaning it cannot be called using the object dot (.) or arrow (->) operators.
Member friend functions:
	Instead of making an entire class a friend, you can point to a specific function of that class to be a friend
Friend classes:
	You can also declare a class to be a friend of another class, 
	all the member function of the friend class will be able to access the
	data of that class

*/