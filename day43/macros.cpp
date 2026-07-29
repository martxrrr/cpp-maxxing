#include <iostream> //this is an include directive


//object like macros with substitution text
#define MY_NAME "Martin"

//object-like macros with no substitution text
#define MACRO_NO_SUB

#define PRINT_NAME
//#define PRINT_ANOTHER


#define FOO 9

void myFunction(){
#define MACRO_INSIDE_A_SCOPE
}

int main(){
    
    std::cout << "My name is " << MY_NAME << "\n";
 

//conditional compilation
#ifdef PRINT_NAME
    std::cout << "Code block executed successfully! " << "\n";
#endif

#ifdef PRINT_ANOTHER
    std::cout << "Code block has been executed !\n";
#endif
#ifndef PRINT_ANOTHER
    std::cout << "Macro not defined\n";
#endif

//more C++ style syntax:

#if defined (PRINT_NAME)
    std::cout << "Alternative Macro syntax!\n";
#endif

#if !defined(PRINT_ANOTHER)
    std::cout << "Shii is not defined twin!\n";
#endif


//using if 0, I guess 0 is translated to the boolean false and 1 is translated to boolen true

#if 0
    std::cout << "This block of code will not be compiled\n";
#endif

#if 1
      std::cout << "This block of code will be compiled!\n";
#endif

#ifdef FOO
      std::cout << "Foo is defined ! \n";
#endif

//something cool here about macros (macros inside a scope)
#ifdef MACRO_INSIDE_A_SCOPE
      std::cout << "Macro is still called even though myFunction was no called!\n";
#endif  
    return 0;
}
