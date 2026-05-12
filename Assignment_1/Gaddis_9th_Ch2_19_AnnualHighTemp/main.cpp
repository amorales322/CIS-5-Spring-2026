/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 7, 2026, 5:52 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #19: Annual High Temperatures
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
    float NYCHigh;
    float DenHigh;
    float PhxHigh;

    // Initialize Variables
    NYCHigh = 85;
    DenHigh = 88;
    PhxHigh = 106;

    // Map/Process the Inputs -> Outputs
    NYCHigh += NYCHigh * 0.02f;
    DenHigh += DenHigh * 0.02f;
    PhxHigh += PhxHigh * 0.02f;

    // Display Inputs/Outputs
    cout << "If the average July high temperature rises by 2\% in NYC, Denver, and Phoenix, the new July high temperatures will be: \n";
    cout << "New York City: " << NYCHigh << '\n';
    cout << "Denver: " << DenHigh << '\n';
    cout << "Phoenix: " << PhxHigh << '\n';

    // Clean up memory and files

    // Exit the Program
    return 0;
}
