/*
 * File: main.cpp
 * --------------
 * Sample QT project
 */

#include <iostream>
#include "console.h"
#include "strlib.h"
#include "simpio.h"
#include "set.h"
#include "testing/SimpleTest.h"
#include "Car.h"
#include "truetraffic.h"
using namespace std;

/*
 * This sample main brings up testing menu.
 */
int main() {
    if (runSimpleTests(SELECTED_TESTS)) {
        return 0;
    }
    string input = "";
    TrueTraffic traffic;
    Set<string> validInputs = {"NF", "NL", "EF" ,"EL" ,"SF", "SL", "WF", "WL", "quit"};
    Set<int> inputsEntered = {};
    bool continueBreak = false;
    bool continueContinue = false;
    while (toLowerCase(input) != "quit"){
        bool runLight = true;
        bool clearLight;
        input = getLine("This is the interface for TrueTraffic. Enter symbols such as \"NF\" for adding a car on the north side and going forward or \"EL\" for adding a car on the east side going left. If you want to enter no cars, press \"Enter\". If you want more than one car, seperate them with spaces. Enter \"quit\" to quit:");
        clearLight = getYesOrNo("Do you want the light to clear the queue? (y/n)");
        int numRemove;
        if (!clearLight){
            numRemove = getReal("How many should be removed each time?");
        }
        Vector<string> words = stringSplit(input, " ");
        for (string word : words){
            if (toLowerCase(word) == "quit"){
                continueBreak = true;
                break;
            }
            if (!validInputs.contains(word)){
                cout << "Not a valid input. Try again!" << endl;
                continueContinue = true;
                break;
            }
        }
        if (continueBreak){
            break;
        }
        if (continueContinue){
            continue;
        }
        if (!words.isEmpty()){
            for (int i = 0; i < words.size(); i++){
                //if it is a valid input, then we will add the car in, then reconsider which to clear, then clear
                int uniqueIndex = getReal("Please Enter an unique index that you have not entered before:");
                if (inputsEntered.contains(uniqueIndex)){
                    cout << "not valid index. Try again!" << endl;
                    runLight = false;
                    break;
                }
                inputsEntered.add(uniqueIndex);
                Car newCar(words[i], uniqueIndex);
                traffic.Add(newCar);

                //call the constructor for the Car and add it to the respective queue.
                //Make sure to add functionality so that the user can add more than 1 user.
                //Maybe have the user enter how many
            }
        }
        if (runLight && clearLight){
            traffic.NaiveTrafficLightsGreen();
        }
        if (runLight && !clearLight){
            traffic.NaiveTrafficLightsGreen(numRemove);
        }
        cout << "1     2     3     4     5     6     7     8" << endl;
        cout << "NF    NL    EF    EL    SF    SL    WF    WL" << endl;

        traffic.print();

    }
    cout << "Thank you!" << endl;
    return 0;
}


PROVIDED_TEST("Sample use of SimpleTest")
{
    EXPECT_EQUAL(1 + 1, 2);
}
