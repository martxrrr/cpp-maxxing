#include <algorithm>
#include <iostream>
#include <vector>

int main(){

    std::vector<int> numbers = {1, 2, 3, 4, 5, 7, 10, 45, 50, 67, 69};

    //checks if a number exists in a sorted iterable
    bool exists = std::binary_search(numbers.begin(),
                                     numbers.end(),
                                     10);
    std::cout << (exists ? "Number found in the vector!\n" : "Number does not exist!\n");

    //look for an element in an iterable
    auto it = std::find(numbers.begin(),
                        numbers.end(),
                        45);
    if(it != numbers.end()){
        std::cout << "Found at index " << std::distance(numbers.begin(), it) << std::endl;
    }

    auto it2 = std::find_if(numbers.begin(),
                           numbers.end(),
                           [](int x){
                            return x > 25;
                           });

    //sorting numbers in an iterable - ascending order by default
    std::vector<int> randNums = {2, 4, 1, 0, 12, 43, 56, 22, 11, 77, 0, 9, 6, 3, 3,34, 55, 91};
    std::sort(randNums.begin(), randNums.end());

    for(const auto &num : randNums){
        std::cout << num << " ";
    }

    //minimum and maximum
    int x = std::max({2, 4, 50, 99});
    printf("\n%d\n", x);

    int y = std::min({-0, 0, 1, 4, 90, 100});
    printf("%d\n", y);


    //maximum and minimum element in an iterable
    auto it3 = std::max_element(randNums.begin(),
                                randNums.end());
    if(it3 != randNums.end()){
        std::cout << "Number found at index " << std::distance(randNums.begin(), it3) << std::endl;
    }

    auto it4 = std::min_element(randNums.begin(),
                                randNums.end());
    if(it4 != randNums.end()){
        std::cout << "Number found at index " << std::distance(randNums.begin(), it4) << std::endl;
    }

    //maximum and minimum at once in the same iterable
    auto[minIt, maxIt] = std::minmax_element(randNums.begin(),
                                             randNums.end());

    //count how many times an item occur in an iterable
    int count = std::count(randNums.begin(),
                           randNums.end(),
                           0);
    std::cout << count << " times\n";

    //count elements satisfying a condition
    int cnt = std::count_if(randNums.begin(),
                            randNums.end(),
                            [](int x){
                                return x > 40;
                            });
    std::cout << "> 40 : " << cnt << " times\n";


    //check if all elements satisfy a condition
    bool result = std::all_of(randNums.begin(),
                              randNums.end(),
                              [](int x){
                                return x >= 0;
                              });
    std::cout << (result ? "Yeah" : "No") << "\n";

    //checking of at least one element satisfy a condition
    bool sat = std::any_of(randNums.begin(),
                           randNums.end(),
                           [](int x){
                            return x > 90;
                           });
    
    std::cout << (sat ? "Yes" : "Naah") << "\n";


    //there is also std::none_of -> returns true if none of the elements in an iterable satisfies a condition

    //modifying elements
    std::for_each(randNums.begin(),
                  randNums.end(),
                  [](int &x){
                    x *= 2 ;
                  });
    for(const auto& num : randNums){
        std::cout << num << " ";
    }

    std::transform();   // -> transforming elements into something else
    std::replace();     //replace every occurence of an element with the specified element
    std::replace_if();  //replaces every occurence of an element if it satisfies the specified condition
    std::reverse();     //reverse the order of elements in a list
    std::shuffle();     //randomly shuffles the elements in the iterable



    //set algorithms
    std::set_union();         // OR
    std::set_intersection();  //AND
    std::set_difference();    //elements in set A that are not in Set B
    



    std::cin.get();


    return 0;
}