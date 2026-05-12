/*
* File:   main.cpp
 * Author: Anthony Morales
 * Created: May 5, 2026, 11:03 AM
 * Purpose: Assignment 6 - Dice Table Sum
 *
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>   //Format Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...
const int COLS = 6;

//Function Prototypes
void fillTbl(int [][COLS], int);

void prntTbl(const int [][COLS], int);

//Execution Begins Here!
int main(int argc, char **argv) {
    //Declare Variables
    const int ROWS = 6;
    int tablSum[ROWS][COLS];

    //Initialize or input i.e. set variable values
    fillTbl(tablSum, ROWS);

    //Display the outputs
    cout << "Think of this as the Sum of Dice Table\n";
    prntTbl(tablSum, ROWS);

    //Exit stage right or left!
    return 0;
}


void fillTbl(int tablSum[][COLS], int row) {
    for (int x{0}; x < COLS; x++) {
        for (int y{0}; y < row; y++)
            tablSum[y][x] = x + 1 + y + 1;
    }
}

void prntTbl(const int tablSum[][COLS], int row) {
    const int lblSize = 4;
    const char ROWSLBL[lblSize] = {'R', 'O', 'W', 'S'};

    cout << string(11, ' ') << "C o l u m n s\n" << setw(6) << '|';
    for (int x{1}; x <= COLS; x++)
        cout << setw(4) << x;
    cout << '\n' << string(34, '-') << '\n';

    for (int x{0}; x < COLS; x++) {
        if (x >= 1 && x <= lblSize)
            cout << ROWSLBL[x - 1] << setw(3) << x + 1 << " |";
        else
            cout << setw(4) << x + 1 << " |";

        for (int y{0}; y < row; y++)
            cout << setw(4) << tablSum[y][x] << flush;
        cout << '\n';
    }
}
