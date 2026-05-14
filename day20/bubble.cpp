#include <iostream>

int main(){

    int array[] = {12, 32, 45, 65, 78, 3, 2, 4, 65, 6, 43 , 33, 21, 15, 17};
    int arrSize = sizeof(array) / sizeof(array[0]);
    std::cout << arrSize << std::endl;
    int temp;

    for(int i = 1; i < arrSize; i++){
        for(int j = 0; j < arrSize - 1; j++){
            if(array[j] > array[j+1]){
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
    for(int i = 0; i < arrSize; i++){
        std::cout << array[i] << " ";
    }

}