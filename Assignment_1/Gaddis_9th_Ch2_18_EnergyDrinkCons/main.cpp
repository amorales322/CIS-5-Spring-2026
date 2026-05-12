/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 7, 2026, 5:59 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #18: Energy Drink Consumption
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
    int survCt;
    float drkPurchase;
    float preferCit;
    int ct1;
    int ct2;

    // Initialize Variables
    survCt = 16500;
    drkPurchase = 0.15f;
    preferCit = 0.58f;

    // Map/Process the Inputs -> Outputs
    ct1 = survCt * drkPurchase;
    ct2 = ct1 * preferCit;

    // Display Inputs/Outputs
    cout << "Out of " << survCt << " survey participants, approximately " << ct1 << " purchase one or more energy drinks per week.\n";
    cout << "Out of these " << ct1 << " participants that purchase energy drinks, " << ct2 << " prefer citrus-flavored energy drinks.\n";

    // Clean up memory and files

    // Exit the Program
    return 0;
}
