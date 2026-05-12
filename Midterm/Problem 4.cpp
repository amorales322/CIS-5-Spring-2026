/*
* File:   main.cpp
 * Author: Anthony Morales
 * Created on April 23, 2026, 11:57 AM
 * Purpose:  M6 -- Series Calculation. 10pts
 */

// System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

// User Libraries Here

// Global Constants Only, No Global Variables
// Like PI, e, Gravity, or conversions

// Function Prototypes Here

// Program Execution Begins Here
int main(int argc, char **argv) {
    // Declare all Variables Here
    float x, fx;
    int nterms;
    float buf;


    // Input or initialize values Here
    cout << "Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+......." << endl;
    cout << "Input x nd the number of terms, output f(x)" << endl;
    cin >> x >> nterms;

    while (nterms < 0) {
        cout << "Number of terms must positive. Enter a new number of terms >= 0: ";
        cin >> nterms;
    }
    buf = x;
    fx = x;

    // Calculate Sequence sum here
    for (int i{3}; i <= (2 * nterms - 1); i += 2) {
        buf *= (x * x) / (i * (i - 1));
        if (i % 4 == 1)
            fx += buf;
        else
            fx -= buf;
    }

    // Output the result here
    cout << fixed << showpoint << setprecision(6) << fx << endl;

    // Exit
    return 0;
}
