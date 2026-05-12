/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 8, 2026, 1:01 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #13: Surface Area & Volume of Sphere
 */

// System Libraries
#include <iostream> //Input Output Library
using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions
const float PI = 3.1415926535;

// Function Prototypes

// Execution begins here at main
int main(int argc, char **argv)
{
    // Set random number seed

    // Declare Variables
    int sphRad;
    float sphSA;
    float sphVol;

    // Initialize Variables
    sphRad = 8;

    // Map/Process the Inputs -> Outputs
    sphSA = 4 * PI * (sphRad * sphRad);
    sphVol = (4.0f/3) * PI * (sphRad * sphRad * sphRad);

    // Display Inputs/Outputs
    cout << "Surface Area of Sphere w/ Radius " << sphRad << " cm: " << sphSA << " cm^2.\n";
    cout << "Volume of Sphere w/ Radius " << sphRad << " cm: " << sphVol << " cm^3.\n";

    // Clean up memory and files

    // Exit the Program
    return 0;
}
