//========================================
//  GENERIC PROGRAMMING (USING CLASSES) //
//========================================

#include <iostream>
#include <typeinfo>

template <typename T>

class Numbers{
    private:
    T num1, num2;
    public:
    Numbers(T number1, T number2){
        this->num1 = number1;
        this->num2 = number2;
    }
    T getMax(){ return ((num1 > num2) ? num1 : num2);}
};

//template classes with more than one data types
template <typename A, typename B, typename C> class Test{
    public:
    A val1;
    B val2;
    C val3;

    Test(A x, B y, C z): val1(x), val2(y), val3(z) {};
    void getValues(){
        std::cout << val1 << " " << val2 << " " << val3 << std::endl;
    }
};

//template variables
template <typename T> constexpr T Pi = T(3.14159);


//default arguments
template <typename X, typename Y = int, typename Z = float> class Test2{
    public:
    X value1;
    Y value2;
    Z value3;

    Test2(X j, Y k, Z l) : value1(j), value2(k), value3(l) {};

    void getValues(){
        std::cout << value1 << "\n" << value2 << "\n" << value3 << "\n";
    }
};

int main(){
    
    Numbers<int> nums(10, 20);
    std::cout << nums.getMax() << std::endl;

    Numbers<double> deci(11.000001, 11.0999999);
    std::cout << deci.getMax() << std::endl;

    //template classes with more than one data types
    Test<int, std::string, bool> numbers(12, "Kangethe", false);
    numbers.getValues();
    

    //template variables
    std::cout << "As integer: " << Pi<int> << std::endl;
    std::cout << "As double: " << Pi<double> << std::endl;
    std::cout << "As float: " << Pi<float> << std::endl;

    std::cout << typeid(Pi<int>).name() << std::endl;

    //default arguments using templates - passing of arguments is optional as long as you defined the data types initially
    Test2<int> data(12, 14.6, 10);
    data.getValues();

    //when you pass in an argument, it overrides the one you defined earlier while defining the function or tha class
    Test2<int, double, float> data2(12.1234, 45.346546, 9);
    data2.getValues();
    

    return 0;
}
//shit needs a lot of practice, it gives me the feeling of understanding it when I read the documentation
// but I feel like I need to hop onto a project to make myself feel better about c++