/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 7, 2026, 5:45 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #20: How Much Paint
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
    int painCov;
    float fncArea; // Declared as a float so that division results in a float and not an int
    float galNeed;

    // Initialize Variables
    painCov = 340; // Square Feet per Gallon
    fncArea = 6 * 100; // Fence Square Footage

    // Map/Process the Inputs -> Outputs
    galNeed = (fncArea / painCov) * 2;

    // Display Inputs/Outputs
    cout << "You will need approximately " << galNeed << " gallons of paint to cover the wood fence twice.\n";

    // Clean up memory and files

    // Exit the Program
    return 0;
}
