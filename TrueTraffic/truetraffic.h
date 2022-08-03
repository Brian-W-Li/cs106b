#pragma once

#ifndef TRUETRAFFIC_H
#define TRUETRAFFIC_H

#include "queue.h"
#include "Car.h"
#include "set.h"

//The directions have inherent numbers
//NF NL EF EL SF SL WF WL
//1  2  3  4  5  6  7  8
//in that way we can compare them

class TrueTraffic
{
public:
    TrueTraffic();

    //These are some add functions to add cars to their respective queues.
    //Once the car is taken into the function, the function checks its direction field and adds it to the right queue.
    void Add(Car car);




    //Because there is a lack of functions to use for testing, print would have to do
    void print();

    //returns a set of the queues in which the traffic light is green for
    //does most of the work

    //This version of NaiveTrafficLightsGreen removes a certain amount of cars each time a set of traffic lights come on.
    void NaiveTrafficLightsGreen(int numRemove);

    //This version of NaiveTrafficLights clears the queue whenever a set of traffic lights come on.
    void NaiveTrafficLightsGreen();



    //this function clears the queue for all the queue's passed into the function
    //void DoTheJob(Vector<Queue<Car>*> queue);

    //so, the basic functionality would be a

    //need some form of time tracking
    //need a form of peek/print






private:
    //These are the queues for each of the traffic light components
    Queue<Car> NorthForward;
    Queue<Car> NorthLeft;
    Queue<Car> SouthForward;
    Queue<Car> SouthLeft;
    Queue<Car> EastForward;
    Queue<Car> EastLeft;
    Queue<Car> WestForward;
    Queue<Car> WestLeft;

    //These functions access the size for each of the queues of cars
    int NumNorthForward();
    int NumNorthLeft();
    int NumSouthForward();
    int NumSouthLeft();
    int NumEastForward();
    int NumEastLeft();
    int NumWestForward();
    int NumWestLeft();

    void NorthAdd(Car car);
    void SouthAdd(Car car);
    void EastAdd(Car car);
    void WestAdd(Car car);

    void PrintNorthForward();
    void PrintNorthLeft();
    void PrintEastForward();
    void PrintEastLeft();
    void PrintSouthForward();
    void PrintSouthLeft();
    void PrintWestForward();
    void PrintWestLeft();


    //maybe add isEmpty functions for each of them if needed

};

#endif // TRUETRAFFIC_H
