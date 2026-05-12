/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 8, 2026, 1:10 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #12: Weight of Freight
 */

// System Libraries
#include <iostream> //Input Output Library
using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions
const int lbInTon = 2240;

// Function Prototypes

// Execution begins here at main
int main(int argc, char **argv)
{
    // Set random number seed

    // Declare Variables
    float wtInLb; // Declared as a float so that division results in a float
    float wtInTon;

    // Initialize Variables
    wtInLb = 10'158.0f;

    // Map/Process the Inputs -> Outputs
    wtInTon = wtInLb / lbInTon;

    // Display Inputs/Outputs
    cout << "Weight of Freight in Tons: " << wtInTon << " Tons.\n";

    // Clean up memory and files

    // Exit the Program
    return 0;
}
