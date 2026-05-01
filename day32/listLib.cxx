#include <iostream>
#include <list>

int main(){

    std::list<std::string> numbers;

    //constructs in another memory location then copies in our list
    numbers.push_front("Martin");
    numbers.push_front("Louis");
    numbers.push_back("Kangethe");
    numbers.push_back("Alex");

    //constructs directly into our list, no copying
    numbers.emplace_back("Joseph");
    numbers.emplace_back("Sabonge");
    numbers.emplace_back("Ledama");
    numbers.emplace_back("Carson");

    numbers.emplace(numbers.begin(), "Qzel"); //constructs an element in place at a position

    for(const auto& num : numbers){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //returns the reference of the first element
    std::string first = numbers.front(); 
    std::cout << first << "\n";


    //returns the reference of the end element
    std::string back = numbers.back(); 
    std::cout << back << "\n";

    //check whether the list is empty
    bool empty = numbers.empty();
    std::cout << ((empty) ? "It is empty" : "It is not empty") << "\n";


    //the number of elements in the list
    int size = numbers.size();
    std::cout << "The list has " << size << " elements" << "\n";

    //others
    numbers.pop_front(); //remove first element
    numbers.pop_back(); //remove last eleent
    numbers.clear(); //removes all elements

    numbers.erase(numbers.begin());

    std::list<std::string> info;

    info.emplace_front("Darren");
    info.emplace_front("Carlson");
    info.emplace_front("Emmanuel");
    info.emplace_front("Emmanuel");
    info.emplace_front("Mark");

    //remove consucutive duplicates
    info.unique(); //returns that list, but with duplicates removed

    auto rangeB = info.begin(); //returns an iterator from the beginning
    auto rangeE = info.end();
    std::advance(rangeE, 5); //moves the iterator

    info.splice(rangeE, numbers); //takes 2 arguments, the iterator(where to insert) and the source(the list you want to insert)

    info.remove("Mark"); //remove the element specified
    for(const auto& stu : info){
        std::cout << stu << " ";
    }
    std::cout << std::endl;


    std::list<int> data1 = {1, 2, 3, 4, 5};
    std::list<int> data2 = {6, 7, 8, 9, 10};

    auto it = data1.end(); //dest
    // std::advance(it, 0);
    data1.splice(it, data2); //iter_dest, src

    // data1.sort();
    // data2.sort();

    // data1.merge(data2); //merge two sorted lists : creates one merged sorted list
    for(const auto& data : data1){
        std::cout << data << " ";
    }
    std::cout << std::endl;

    return 0;
}

//=======
// LIST //
//========

/*
- Solves some of the problems of std::vector

- Constant time insertion and deletion of element
- No fast random access
- It is implemented as a doubly linked list
- Provides bidirectional iteration capability while being less space efficient.
- Adding, removing and moving the elements within the list or across several 
  lists does not invalidate the iterators or references
- An iterator is invalidated only when the corresponding element is deleted
- Elements are scattered across memory hence cannot use indexing to access elements
- Best to use for frequent insertions and deletions, splicing, moving "heavy" objects
- Searching and Access of element O(n)
- Insertion at the end/front O(1)

- Most of the operations are just a matter of moving pointers and freeing memory
  making lists suitable for reordering of large and expensive objects
*/