#include "truetraffic.h"
#include "testing/SimpleTest.h"
#include "random.h"

TrueTraffic::TrueTraffic()
{
    NorthForward = {};
    NorthLeft = {};
    SouthForward = {};
    SouthLeft = {};
    EastForward = {};
    EastLeft = {};
    WestForward = {};
    WestLeft = {};
}

int TrueTraffic::NumNorthForward(){
    return NorthForward.size();
}

int TrueTraffic::NumNorthLeft(){
    return NorthLeft.size();
}
int TrueTraffic::NumSouthForward(){
    return SouthForward.size();
}
int TrueTraffic::NumSouthLeft(){
    return SouthLeft.size();
}
int TrueTraffic::NumEastForward(){
    return EastForward.size();
}
int TrueTraffic::NumEastLeft(){
    return EastLeft.size();
}
int TrueTraffic::NumWestForward(){
    return WestForward.size();
}
int TrueTraffic::NumWestLeft(){
    return WestLeft.size();
}

void TrueTraffic::Add(Car car){
    if (car.direction < 1 || car.direction > 8){
        error("invalid direction");
    }
    if (car.direction <= 2){
        NorthAdd(car);
    }
    else if (car.direction <= 4){
        EastAdd(car);
    }
    else if (car.direction <= 6){
        SouthAdd(car);
    }
    else if (car.direction <= 8){
        WestAdd(car);
    }
}

void TrueTraffic::PrintNorthForward(){
    Queue<Car> copy = NorthForward;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintNorthLeft(){
    Queue<Car> copy = NorthLeft;
    while (!copy.isEmpty()){
         copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintEastForward(){
    Queue<Car> copy = EastForward;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintEastLeft(){
    Queue<Car> copy = EastLeft;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintSouthForward(){
    Queue<Car> copy = SouthForward;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintSouthLeft(){
    Queue<Car> copy = SouthLeft;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintWestForward(){
    Queue<Car> copy = WestForward;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}

void TrueTraffic::PrintWestLeft(){
    Queue<Car> copy = WestLeft;
    while (!copy.isEmpty()){
        copy.dequeue().print();
    }
    cout << endl;
}


void TrueTraffic::print(){
    PrintNorthForward();
    PrintNorthLeft();
    PrintEastForward();
    PrintEastLeft();
    PrintSouthForward();
    PrintSouthLeft();
    PrintWestForward();
    PrintWestLeft();
}


//adds car to the right place in north
void TrueTraffic::NorthAdd(Car car){
    int direction = car.direction;
    if (direction == 1){
        NorthForward.enqueue(car);
    }
    else if(direction == 2){
        NorthLeft.enqueue(car);
    }
}

void TrueTraffic::SouthAdd(Car car){
    int direction = car.direction;
    if (direction == 5){
        SouthForward.enqueue(car);
    }
    else if(direction == 6){
        SouthLeft.enqueue(car);
    }
}

void TrueTraffic::EastAdd(Car car){
    int direction = car.direction;
    if (direction == 3){
        EastForward.enqueue(car);
    }
    else if(direction == 4){
        EastLeft.enqueue(car);
    }
}

void TrueTraffic::WestAdd(Car car){
    int direction = car.direction;
    if (direction == 7){
        WestForward.enqueue(car);
    }
    else if(direction == 8){
        WestLeft.enqueue(car);
    }
}
void TrueTraffic::NaiveTrafficLightsGreen(int numRemove){
    Vector<int> numCars(8);
    Vector<Queue<Car>> vector = {};

    //so, look at which one has the most cars out of the 8 options
    numCars[0] = NumSouthForward() + NumSouthLeft();
    numCars[1] = NumEastForward() + NumEastLeft();
    numCars[2] = NumNorthForward() + NumNorthLeft();
    numCars[3] = NumWestForward() + NumWestLeft();
    numCars[4] = NumSouthForward() + NumNorthForward();
    numCars[5] = NumEastForward() + NumWestForward();
    numCars[6] = NumSouthLeft() + NumNorthLeft();
    numCars[7] = NumEastLeft() + NumWestLeft();

    int indexBig = 0;
    int cur = numCars[0];
    for (int i = 0; i < numCars.size(); i++){
        if (numCars[i] > cur){
            cur = numCars[i];
            indexBig = i;
        }
    }
    int numRemoveCopy = numRemove;
    switch(indexBig) {
          case 0 :
            while (!SouthForward.isEmpty() && numRemove > 0){
                SouthForward.dequeue();
                numRemove--;
            }
            while (!SouthLeft.isEmpty() && numRemoveCopy > 0){
                SouthLeft.dequeue();
                numRemoveCopy--;
            }
            break;
          case 1 :
            while (!EastForward.isEmpty() && numRemove > 0){
                EastForward.dequeue();
                numRemove--;
            }

            if (!EastLeft.isEmpty() && numRemoveCopy > 0){
                EastLeft.dequeue();
                numRemoveCopy--;
            }
            break;
          case 2 :
            if (!NorthForward.isEmpty() && numRemove > 0){
                NorthForward.dequeue();
                numRemove--;
            }
            if (!NorthLeft.isEmpty() && numRemoveCopy > 0){
                NorthLeft.dequeue();
                numRemoveCopy--;
            }
            break;
          case 3 :
            if (!WestForward.isEmpty() && numRemove > 0){
                WestForward.dequeue();
                numRemove--;
            }
            if (!WestLeft.isEmpty() && numRemoveCopy > 0){
                WestLeft.dequeue();
                numRemoveCopy--;
            }
            break;
          case 4 :
            if (!SouthForward.isEmpty() && numRemove > 0){
                SouthForward.dequeue();
                numRemove--;
            }
            if (!NorthForward.isEmpty() && numRemoveCopy > 0){
                NorthForward.dequeue();
                numRemoveCopy--;
            }
            break;
          case 5 :
            if (!EastForward.isEmpty() && numRemove > 0){
                EastForward.dequeue();
                numRemove--;
            }
            if (!WestForward.isEmpty() && numRemoveCopy > 0){
                WestForward.dequeue();
                numRemoveCopy--;
            }
            break;
          case 6 :
            if (!SouthLeft.isEmpty() && numRemove > 0){
                SouthLeft.dequeue();
                numRemove--;
            }
            if (!NorthLeft.isEmpty() && numRemoveCopy > 0){
                NorthLeft.dequeue();
                numRemoveCopy--;
            }
            break;
          case 7 :
            if (!EastLeft.isEmpty() && numRemove > 0){
                EastLeft.dequeue();
                numRemove--;
            }
            if (!WestLeft.isEmpty() && numRemoveCopy > 0){
                WestLeft.dequeue();
                numRemoveCopy--;
            }
            break;
          default :
            error("not a valid case");
    }
}

void TrueTraffic::NaiveTrafficLightsGreen(){
    Vector<int> numCars(8);
    Vector<Queue<Car>> vector = {};

    //so, look at which one has the most cars out of the 8 options
    numCars[0] = NumSouthForward() + NumSouthLeft();
    numCars[1] = NumEastForward() + NumEastLeft();
    numCars[2] = NumNorthForward() + NumNorthLeft();
    numCars[3] = NumWestForward() + NumWestLeft();
    numCars[4] = NumSouthForward() + NumNorthForward();
    numCars[5] = NumEastForward() + NumWestForward();
    numCars[6] = NumSouthLeft() + NumNorthLeft();
    numCars[7] = NumEastLeft() + NumWestLeft();

    int indexBig = 0;
    int cur = numCars[0];
    for (int i = 0; i < numCars.size(); i++){
        if (numCars[i] > cur){
            cur = numCars[i];
            indexBig = i;
        }
    }
    switch(indexBig) {
          case 0 :
            SouthForward.clear();
            SouthLeft.clear();
            break;
          case 1 :
            EastForward.clear();
            EastLeft.clear();
            break;
          case 2 :
            NorthForward.clear();
            NorthLeft.clear();
            break;
          case 3 :
            WestForward.clear();
            WestLeft.clear();
            break;
          case 4 :
            SouthForward.clear();
            NorthForward.clear();
            break;
          case 5 :
            EastForward.clear();
            WestForward.clear();
            break;
          case 6 :
            SouthLeft.clear();
            NorthLeft.clear();
            break;
          case 7 :
            EastLeft.clear();
            WestLeft.clear();
            break;
          default :
            error("not a valid case");
    }

}

STUDENT_TEST("testing Add"){
    TrueTraffic traffic;
    for (int i = 0; i < 5; i++){
        Car newCar("NF", i);
        traffic.Add(newCar);
        traffic.print();

    }
}

STUDENT_TEST("more Add testing"){
    TrueTraffic traffic;
    Vector<string> validInputs = {"NF", "NL", "EF" ,"EL" ,"SF", "SL", "WF", "WL"};
    setRandomSeed(9);
    for (int i = 0; i < 20; i++){
        Car newCar(validInputs.get(randomReal(0, validInputs.size())), i);
        traffic.Add(newCar);
        cout << i << endl;
        traffic.print();
    }
}

STUDENT_TEST("testing NaiveTrafficLightsGreen no parameter "){
    TrueTraffic traffic;
    Car newCar("SL", 0);
    traffic.Add(newCar);
    Car newCar1("NL", 1);
    traffic.Add(newCar1);
    Car newCar2("WF", 2);
    traffic.Add(newCar2);
    traffic.NaiveTrafficLightsGreen();
    traffic.print();
}

STUDENT_TEST("random testing NaiveTrafficLightsGreen "){
    TrueTraffic traffic;
    Vector<string> validInputs = {"NF", "NL", "EF" ,"EL" ,"SF", "SL", "WF", "WL"};
    setRandomSeed(9);
    for (int i = 0; i < 20; i++){
        Car newCar(validInputs.get(randomReal(0, validInputs.size())), i);
        traffic.Add(newCar);
        traffic.NaiveTrafficLightsGreen();
        //This test proves that without adding more than one car, the traffic light will always be empty
        cout << i << endl;
        traffic.print();
    }
}

