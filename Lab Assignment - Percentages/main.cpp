/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on February 26, 2026, 3:08 PM
 * Purpose:  Lab Assignment - Percentages
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
    float milBdgt, fedBdgt, mlPrcnt;

    // Initialize Variables
    milBdgt = 8.42e11f; // Military Budget = 842 Billion

    fedBdgt = 6.5e12f; // Federal Budget  = 6.5 Trillion

    // Map/Process the Inputs -> Outputs
    mlPrcnt = milBdgt / fedBdgt;

    // Display Inputs/Outputs
    cout << "Military Budget as a Percentage of the Federal Budget: " << mlPrcnt * 100 << "%\n";

    // Clean up memory and files

    // Exit the Program
    return 0;
}
