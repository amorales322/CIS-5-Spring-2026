/*
 * File:   main.cpp
 * Author: mlehr - Modified by: Anthony Morales
 * Created on January 6, 2025
 * Modified on March 28, 2026, 3:30 PM
 * Purpose:  Lab - Menu and Truth Table (Truth Table)
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <iomanip>  // Output Formatting Library
using namespace std;

// User Libraries

// Global Constants
// Only use Scientific Values like PI, Speed of Light, etc...
// Conversion between units

// Function Prototypes

int main(int argv, char **argc)
{
    // Random Seeds are set for the random number generator

    // Declare Variables
    bool x, y;

    // Display Heading
    cout << left;
    cout << setw(8) << "x" << setw(8) << "y" << setw(8) << "!x" << setw(8) << "!y" << setw(8) << "x&&y" << setw(8) << "x||y" << setw(8) << "x^y"
         << setw(8) << "x^y^x" << setw(8) << "x^y^y" << setw(8) << "!(x&&y)" << setw(8) << "!x||!y" << setw(8) << "!(x||y)" << setw(8) << "!x&&!y" << endl;
     // This is a way of creating a string that I know how to use, I use it here so that the table looks a bit more formatted and nicer
    cout << string(102, '-') << '\n';

    // Display First Row
    x = true;
    y = true;
    cout << setw(8) << (x ? 'T' : 'F')
         << setw(8) << (y ? 'T' : 'F')
         << setw(8) << (!x ? 'T' : 'F')
         << setw(8) << (!y ? 'T' : 'F')
         << setw(8) << (x && y ? 'T' : 'F')
         << setw(8) << (x || y ? 'T' : 'F')
         << setw(8) << (x ^ y ? 'T' : 'F')
         << setw(8) << (x ^ y ^ x ? 'T' : 'F')
         << setw(8) << (x ^ y ^ y ? 'T' : 'F')
         << setw(8) << (!(x && y) ? 'T' : 'F')
         << setw(8) << (!x || !y ? 'T' : 'F')
         << setw(8) << (!(x || y) ? 'T' : 'F')
         << setw(8) << (!x && !y ? 'T' : 'F') << endl;

    // Display Second Row
    y = false;
    cout << setw(8) << (x ? 'T' : 'F')
         << setw(8) << (y ? 'T' : 'F')
         << setw(8) << (!x ? 'T' : 'F')
         << setw(8) << (!y ? 'T' : 'F')
         << setw(8) << (x && y ? 'T' : 'F')
         << setw(8) << (x || y ? 'T' : 'F')
         << setw(8) << (x ^ y ? 'T' : 'F')
         << setw(8) << (x ^ y ^ x ? 'T' : 'F')
         << setw(8) << (x ^ y ^ y ? 'T' : 'F')
         << setw(8) << (!(x && y) ? 'T' : 'F')
         << setw(8) << (!x || !y ? 'T' : 'F')
         << setw(8) << (!(x || y) ? 'T' : 'F')
         << setw(8) << (!x && !y ? 'T' : 'F') << endl;

    // Display Third Row
    x = false;
    y = true;
    cout << setw(8) << (x ? 'T' : 'F')
         << setw(8) << (y ? 'T' : 'F')
         << setw(8) << (!x ? 'T' : 'F')
         << setw(8) << (!y ? 'T' : 'F')
         << setw(8) << (x && y ? 'T' : 'F')
         << setw(8) << (x || y ? 'T' : 'F')
         << setw(8) << (x ^ y ? 'T' : 'F')
         << setw(8) << (x ^ y ^ x ? 'T' : 'F')
         << setw(8) << (x ^ y ^ y ? 'T' : 'F')
         << setw(8) << (!(x && y) ? 'T' : 'F')
         << setw(8) << (!x || !y ? 'T' : 'F')
         << setw(8) << (!(x || y) ? 'T' : 'F')
         << setw(8) << (!x && !y ? 'T' : 'F') << endl;

    // Display Fourth Row
    y = false;
    cout << setw(8) << (x ? 'T' : 'F')
         << setw(8) << (y ? 'T' : 'F')
         << setw(8) << (!x ? 'T' : 'F')
         << setw(8) << (!y ? 'T' : 'F')
         << setw(8) << (x && y ? 'T' : 'F')
         << setw(8) << (x || y ? 'T' : 'F')
         << setw(8) << (x ^ y ? 'T' : 'F')
         << setw(8) << (x ^ y ^ x ? 'T' : 'F')
         << setw(8) << (x ^ y ^ y ? 'T' : 'F')
         << setw(8) << (!(x && y) ? 'T' : 'F')
         << setw(8) << (!x || !y ? 'T' : 'F')
         << setw(8) << (!(x || y) ? 'T' : 'F')
         << setw(8) << (!x && !y ? 'T' : 'F') << endl;

    // Exit the program
    return 0;
}
