#include <iostream>

int main(){

    int array[] = {12, 32, 45, 65, 78, 3, 2, 4, 65, 6, 43 , 33, 21, 15, 17};
    int arrSize = sizeof(array)/sizeof(array[0]);

    //ASCENDING ORDER
    for(int i = 1; i < arrSize; i++){
        while(i > 0 && array[i] < array[i-1]){
            int temp = array[i - 1];
            array[i - 1] = array[i];
            array[i] = temp;
            i--;
        }
    }
    for(int c = 0; c < arrSize; c++){
        std::cout << array[c] << " ";
    }

    //DESCENDING ORDER
    std::cout << "\n";
    int array2[] = {12, 32, 45, 65, 78, 3, 2, 4, 65, 6, 43 , 33, 21, 15, 17};
    for(int a = 1; a < arrSize; a++){
        while(a > 0 && array[a - 1] < array[a]){
            int temp2 = array[a-1];
            array[a-1] = array[a];
            array[a] = temp2;
            a--;
        }
    }
    for(int b = 0; b < arrSize; b++){
        std::cout << array[b] << " ";
    }
    return 0;
}