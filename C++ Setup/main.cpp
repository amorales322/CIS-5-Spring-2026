/* 
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on February 26, 2026, 3:02 PM
 * Purpose:  Introduction/Setup Assignment
 */

//System Libraries
#include <iostream>  //Input Output Library
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main
int main(int argc, char** argv) {
    //Set random number seed
    
    //Declare Variables
    int intArray[10] {};
    int buffer{};    

    //Initialize Variables
    
    //Map/Process the Inputs -> Outputs
    
    //Display Inputs/Outputs
    cout << "Hello, World!" << '\n';
    for (int i{0}; i < 10; i++) {
        cout << "Hello, World! #" << i + 1 << '\n';
    }
    
    for (int i{0}; i < 10; i++) {
        cin >>  buffer;
        intArray[i] = buffer;
    }
    for (int i{0}; i < 10; i++) 
        cout << intArray[i] << '\n';   
    

    //Clean up memory and files
    
    //Exit the Program
    return 0;
}
