#include <iostream>

namespace Student{
        std::string name { "Martin" };
        int age { 19 };

        void getInfo(){
                std::cout << "Name : " << name << "\n";
                std::cout << "Age : " << age << "\n";
        }
};

namespace Teacher{
        std::string name { "Sylvia" };
        int age { 25 };

        void getInfo(){
                std::cout << "Name : " << name << "\n";
                std::cout << "Age : " << age << "\n";
        }
};

void readCensor(){
        static int count = 0;
        ++count;
        std::cout << "Meter read : " << count << "\n";
}


int fact(int n){
        if(n <= 1){
                return 1;
        }
        return n * fact(n - 1);
}

int main(){

        Student::getInfo();
        Teacher::getInfo();

        fact(6);


        return 0;
}