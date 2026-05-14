//SELECTION SORT

#include <iostream>

int main(){

    int array[] = {12, 32, 45, 65, 78, 3, 2, 4, 65, 6, 43 , 33, 21, 15, 17};
    int arrSize = sizeof(array)/sizeof(array[0]);

    //ASCENDING ORDER
    for(int q = 1; q < arrSize; q++){
        while(q > 0 && array[q - 1] > array[q]){
            int temp = array[q - 1];
            array[q - 1] = array[q];
            array[q] = temp;
            q--;
        }
    }
    for(int i = 0; i < arrSize; i++){
        std::cout << array[i] << " ";
    }

    //DESCENDING ORDER
    std::cout << "\n";
    for(int j = 1; j < arrSize; j++){
        while(j > 0 && array[j - 1] < array[j]){
            int temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;
        }
    }
    for(int k = 0; k < arrSize; k++){
        std::cout << array[k] << " ";
    }
    return 0;
}