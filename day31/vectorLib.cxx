#include <iostream>
#include <vector>


struct Player{
    std::string loc;
    int health;

    Player(std::string loc, int health) : loc(loc), health(health) {}
};


int main(){

    std::vector<Player> player;
    player.reserve(3); //great if you know the max number your vector should have

    //push_back() - creates an object in memory then copies it to end of the vector
    //emplace_back() - creates the object directly inside the vector
    player.emplace_back("Kenya", 120);
    player.emplace_back("Germany", 139);
    player.emplace_back("Japan", 167);

    std::vector<std::string> studentInfo;

    studentInfo.push_back("Martin"); 
    studentInfo.push_back("Kangethe");
    studentInfo.push_back("Brian");

    studentInfo.pop_back(); //removes the last element in the vector

    std::cout << studentInfo[0] << "\n"; //does not check for bounds
    std::cout << studentInfo[1] << "\n";
    std::cout << studentInfo[2] << "\n"; 

    std::cout << studentInfo.at(1) << "\n"; //checks bounds i.e if the index is out of range or not

    studentInfo.shrink_to_fit(); //used if you remove a large amount of data and you want to free the unused memory

    studentInfo.clear(); //removes all the elements in the vector but the memory allocated remains the same(capacity=same)
    
    //slower because every element after where we are inserting our data must be moved over 
    // in memory to create space for the new element
    studentInfo.insert(studentInfo.begin(), "Louis");

    for(const std::string &student : studentInfo){
        std::cout << student << "\n";
    }

    std::vector<int> data;

    data.reserve(5);
    data.push_back(2);
    data.push_back(1);
    data.push_back(5);
    data.push_back(7);
    data.push_back(8);

    std::cout << data.size() << "\n"; //number of elements in the vector

    data.insert(data.begin(), 3, 9); //fill with identical data i.e three 9s at the beginning
    for(const int& num : data){
        std::cout << num;
    }

    std::cout << std::endl;

    //appending another vector
    std::vector<int> data2;

    data2.insert(data2.begin(), data.begin(), data.end());
    for(const int& data : data2){
        std::cout << data;
    }
    std::cout << std::endl;

    //inserting a list of numbers i.e hardcoded constants
    data2.insert(data2.begin(), {41, 67, 69});
    for(const int& data : data2){
        std::cout << data;
    }

    std::vector<int> data3;

    data3.resize(2); //creates capacity for 2 and fills the vector with 2 elements (0s)
    

    //use indexing to assign values
    data3[0] = 67;
    data3[1] = 41;
    return 0;
}

//==========
// VECTOR //
//==========

/*

- Vector is a dynamic array - shrink or expands it's size depending on the 
number of elements in it
- Automatic memory management
- O(1) time complexity for items access via index since they are stored in contiguous memory locations
- Size refers to the number of elements, capacity refers to the memory occupied by the vector
- When you want to add something in the vector, std::vector allocates new memory for the new 
  object and the current objects in the vector and then copies them into the new vector and adds the new object
- This is computationally expensive but when you know how many elements you want to store in your vector,
  you can use the reserve() method

- Despite it's versatility, there are times where std::vector is not the man for the job
 i.e 1. Frequent instertions at the beginning of the vector, has O(n) since every element must be shifted
     2. If your data involves very large objects like very heavy classes, std::vector might not be ideal
        because of all the copying involved in resizing the vector. std::list may be a better choice
     3. If your vector size is to remain constant throughout the program, just use std::array twin
     4. When a vector changes it's capacity, that mean the memory location of every element has changed too, so 
        the pointers to each element become invalid because they change with changing size, std::list may
        be a better choice if you want constant memory location for every element

NOTE: Whenever you make a change to a vector and it's capacity changes, any pointer or reference to any
      element in the vector becomes invalid because the elements have shifted to another memory location
        
*/