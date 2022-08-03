#pragma once

#ifndef CAR_H
#define CAR_H

#include <string>
#include "strlib.h"

using namespace std;

//const int index = 0;
struct Car {
    int index;
    int direction;
    Vector<string> validInputss = { "","NF", "NL", "EF" ,"EL" ,"SF", "SL", "WF", "WL"};

    Car(string directionString, int index){
        this->index = index;
        for (int i = 1; i < validInputss.size(); i++){
            if (validInputss[i] == directionString){
                direction = i;
            }
            //The functionality for checking if it is a valid index and if the direction is valid is in main
        }
    }
    //The directions have inherent numbers
    //NF NL EF EL SF SL WF WL
    //1  2  3  4  5  6  7  8
    //in that way we can compare them

    bool operator< (const Car& lhs) const {
        return (direction < lhs.direction);
    }
    bool operator<= (const Car& lhs) const{
        return (direction <= lhs.direction);
    }
    bool operator>= (const Car& lhs) const{
        return (direction >= lhs.direction);
    }
    bool operator> (const Car& lhs) const{
        return (direction > lhs.direction);
    }

    void print(){
        cout << index << ":" << direction << endl;
    }
};

/*bool operator<  (const Car& lhs, const Car& dhs);
bool operator<= (const Car& lhs, const Car& dhs);
bool operator>= (const Car& lhs, const Car& dhs);
bool operator> (const Car& lhs, const Car& dhs);*/




#endif // CAR_H
