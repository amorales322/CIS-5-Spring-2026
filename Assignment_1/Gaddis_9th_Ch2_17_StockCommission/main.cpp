/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on March 8, 2026, 12:22 PM
 * Purpose:  Gaddis 9th Ed. Chapter 2 Problem #17: Stock Commission
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
    int shrect;
    float shrPrce;
    float commRte;

    float shrTot;
    float commTot;
    float totPaid;

    // Initialize Variables
    shrect = 750;
    shrPrce = 35.00f;
    commRte = 0.02f;

    // Map/Process the Inputs -> Outputs
    shrTot = shrect * shrPrce;
    commTot = shrTot * 0.02f;
    totPaid = shrTot + commTot;

    // Display Inputs/Outputs
    cout << "Amount paid for stock: $" << shrTot << '\n';
    cout << "Commission Charge: $" << commTot << '\n';
    cout << "Total Amount Paid (Including commission): $" << totPaid << '\n';

    // Clean up memory and files

    // Exit the Program
    return 0;
}
