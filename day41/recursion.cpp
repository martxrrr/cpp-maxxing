#include <iostream>

int factorial(int n){
        if (n == 1){
                return 1;
        }else{
                return n * factorial(n - 1);
        }
        
};

//gets the fibonacci number at a certain index
int fibonacci(int n){
        if(n <= 0){
                return 0;
        }
        if(n == 1){
                return 1;
        }
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){

        int ans = factorial(5);
        std::cout << ans << "\n";


        std::cout << fibonacci(10) << "\n";
        //0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55s

        return 0;
}