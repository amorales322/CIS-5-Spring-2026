/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 8, 2026, 12:32 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #14: Rainfall Information
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
    float obsTime;
    float obsRFal;

    float AveRain;
    float exp24HR;

    // Initialize Variables
    obsTime = 6.00f;
    obsRFal = 15.00f - 3.00f;

    // Map/Process the Inputs -> Outputs
    AveRain = obsRFal / obsTime;
    exp24HR = obsRFal * 4;

    // Display Inputs/Outputs
    cout << "Total rainfall during observed period: " << obsRFal << " Liters.\n"
         << "Average Rainfall per Hour (L/h): " << AveRain << " L/h.\n"
         << "Expected 24hr Rainfall: " << exp24HR << " Liters.\n";

    // Clean up memory and files

    // Exit the Program
    return 0;
}
