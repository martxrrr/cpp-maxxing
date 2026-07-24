#include <iostream>
#include <functional>

//passing a lambda function as a parameter to a function

void myFunction(std::function<void()> func){
  func();
}

int main(){

  auto message = [] () {
    std::cout << " Hello from a lambda function\n";
  };

  message();

  //lambdas with parameters
  auto add = [] (int a, int b){
    return a + b;
  };
  
  std::cout << "A + B is : " << add(4, 5) << "\n";

  //passing and calling the lambda function as an argument
  auto text = [](){
    std::cout << "Hello Nigga Martin" << "\n" ;
  }; 
  myFunction(text);

  //lambda functions in loops
  for(int i { 1 }; i < 5 ; i++){
    auto show = [i](){
      std::cout << "Number " << i << "\n";
    };

    show();
  }
//The capture clause
  int x = 10;
  auto display = [x](){
    std::cout << "Num : " << x << "\n";
  };  

  display();

  //capture by reference
  std::string nigga = "Wainaina";
  auto shout = [&nigga](){
    std::cout << "Hello nigga " << nigga << "\n";
  };

  shout();

  return 0;
}

/*
 *A lambda function is a small anonymous function that you can write directly inside your code
 It is useful when you need a quick function without naming it or declaring it directly
 syntax [capture] (parameters) {code}
 The capture clause enables the lambda function access variables outside its scope
 
Lambda functions are very useful when you need a quick short function that you probably won't need to reuse
When you have a long and complex logic, you probably won't need to use a lambda function but instead use the norma function
Also very useful when you want to pass a function as a parameter to another function

 * */
