MORE ABOUT OBJECT ORIENTED PROGRAMMING

NOTES:

'virtual' tells the compiler to do late binding or runtime polymorphism

'override' ensures we are truly overriding a base virtual method
It tells the compiler: "I intend to override a virtual function in the base class. If I'm wrong (e.g., wrong signature), give me a compile error."


A pure virtual method in C++ is a virtual function declared in a base class with = 0 and no implementation, forcing all non-abstract derived classes to provide their own definition

/*
Rule Of Three Five 
This rule applies when a class explicitly manages dynamic resources (raw pointers)
RULE OF 3
"If a class needs a user-defined Destructor (i.e. manual `delete`), then you MUST also define these two
yourself:"
1. Destructor
2. Copy Constructor
3. Copy Assignment Operator


Shallow Copying
Copies pointer addresses; both objects point to the same memory
High Risk: leads to double-free errors or unintended side effects when one object mutates the shared data.
Fast performance(fixed-time memory copy).


Deep Copying
Duplicates the target data; each object gets a unique pointer.
Safe: modifying or destroying one object does not impact the other.
Slower (requires allocating heap memory and copying data array/buffer).


LVALUES AND RVALUES

The value category of an expression (or subexpression) indicates whether an expression resolves to a value, a function, or an object of some kind.

lvalues means locator values, it is an expression that evaluates to an identifiable object or function (or bit-field).
There are 2 types of lvalues:
        1. a modifiable lvalue - an lvalue whose value can be modified
        2. A non-modifiable lvalue - an lvalue whose value can’t be modified (because the lvalue is const or constexpr).


rvalue means right-value
It is a value that is not an lvalue
Rvalue expressions evaluate to a value
Commonly seen rvalues include literals (except C-style literals), return values of functions and operators that return by value
rvalues are not identifiable, this means that they have to be used immediately and they only exist in the scope in which they are used

For me I like to think about them like this, an rvalue does not have a memory location, like you can not identify them through a pointer
like they do not live in memory hence they cannot be identified.
For rvalue expression, a temporary variable which we can not access is created, like in the case of concatetating 2 strings and storing tyhe result in 
one common string, a temporary variable is created behind the scenes


In cases where an rvalue is expected but an lvalue is provided, the lvalue will undergo an lvalue-to-rvalue conversion so that it can be used in such contexts.
This basically means the lvalue is evaluated to produce its value, which is an rvalue.

NOTE:
        An lvalue will implicitly convert to an rvalue. This means an lvalue can be used anywhere an rvalue is expected.
        An rvalue, on the other hand, will not implicitly convert to an lvalue.

operator++ results in an lvalue or an rvalue depends on whether it is used as a prefix operator (which returns an lvalue)
or a postfix operator (which returns an rvalue)!

You can not get the reference of of an non-const rvalue, if you try to do so you will get this error: 
        initial value of reference to non-const must be an lvalue
And if you have to do so, pass in the parameter as a const reference

modifiable means non-const

C-style string literals (like "hello") are lvalues (specifically, non-modifiable lvalues) because they represent real, persistent objects in memory with a distinct address and static storage duration.
Because :
        1. They Have an Identity