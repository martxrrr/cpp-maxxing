#include "salary.hpp"

double Bro::getSalary(int days, bool event){
    if(event){
        return 800 * days;
    }else{
        return 400 * days;
    }
}
int Bro::huzz(int exGfs){
    if(exGfs <= 0){
        return 0;
    }else if(exGfs >= 1){
        return 1;
    }
}