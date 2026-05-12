/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 8, 2026, 1:19 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #11: Distance per Tank of Gas
 */

// System Libraries
#include <iostream> //Input Output Library
using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions

// Function Prototypes

// Execution begins here at main
int main(int argc, char **argv)
{
    // Set random number seed

    // Declare Variables
    int gasTkSz;
    float cityMPG;
    float hwyMPG;

    float cityRge;
    float hwyRge;

    // Initialize Variables
    gasTkSz = 20;
    cityMPG = 23.5f;
    hwyMPG = 28.9f;

    // Map/Process the Inputs -> Outputs
    cityRge = cityMPG * gasTkSz;
    hwyRge = hwyMPG * gasTkSz;

    // Display Inputs/Outputs
    cout << "Distance the car can travel on one tank of gas in the city: " << cityRge << " Miles.\n";
    cout << "Distance the car can travel on one tank of gas on the highway: " << hwyRge << " Miles.\n"; 

    // Clean up memory and files

    // Exit the Program
    return 0;
}
