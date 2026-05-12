/*
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Modidfied By: Anthony Morales
 * Created on July 3rd, 1:40 PM
 * Modified on April 7th, 2026, 3:15 PM
 * Purpose: Menu for Homework Assignment 4
 */

// System Libraries
#include <iostream> // Input/Output Library
#include <string>   // String Library
#include <iomanip>  // Output Number Formatting Library
#include <cctype>   // Character Handling Library
#include <cmath>    // Math Library
using namespace std;

// User Libraries

// Global Constants not Variables
// Math/Physics/Science/Conversions/Dimensions

// Function Prototypes
void menu();

void prob1();

void prob2();

void prob3();

void prob4();

void prob5();

void prob6();

float calcMPG(int miTrav, float galCons);

void prob7();

void prob8();

float calcInfRate(float oldPrce, float newPrce);

void prob9();

float calcEstPrce(float itmPrce, float inflRte, int durYear);

void prob10();

float maxNum(float num1, float num2);

float maxNum(float num1, float num2, float num3);

// Code Begins Execution Here with function main
int main(int argc, char **argv) {
    // Set random number seed once here

    // Declare variables here
    int usrOpt;

    // Initialize variables here
    do {
        menu();
        cout << "Enter Option: ";
        cin >> usrOpt;
        cout << '\n';
        // Map inputs to outputs here, i.e. the process
        switch (usrOpt) {
            case 1:
                prob1();
                break;
            case 2:
                prob2();
                break;
            case 3:
                prob3();
                break;
            case 4:
                prob4();
                break;
            case 5:
                prob5();
                break;
            case 6:
                prob6();
                break;
            case 7:
                prob7();
                break;
            case 8:
                prob8();
                break;
            case 9:
                prob9();
                break;
            case 10:
                prob10();
                break;
            default:
                cout << "You choose to exit" << endl;
        }
    } while (usrOpt >= 1 && usrOpt <= 10);

    // Exit the Program
    return 0;
}

void prob1() {
    // Declare Variables
    int usrNum;
    int runTotl{0};

    // Initialize Variables
    do {
        cin >> usrNum;
        if (usrNum < 1)
            cout << "Invalid Number. Enter a new number larger than 0: ";
    } while (usrNum < 1);

    // Map/Process the Inputs -> Outputs
    for (int i{1}; i <= usrNum; i++)
        runTotl += i;

    // Display Inputs/Outputs
    cout << "Sum = " << runTotl << "\n\n";
}

void prob2() {
    // Declare Variables
    short dayWork;
    float totEarn{0.00f};
    float salCtr{0.01f};

    // Initialize Variables
    do
    {
        cin >> dayWork;
        if (dayWork < 1)
            cout << "Cannot enter a number less than 1 for days worked, enter a new numer: ";
    } while (dayWork < 1);

    // Map/Process the Inputs -> Outputs
    for (int dayCtr{1}; dayCtr <= dayWork; dayCtr++, salCtr *= 2)
        totEarn += salCtr;

    // Display Inputs/Outputs
    cout << fixed << setprecision(2) << "Pay = $" << totEarn << '\n';
}

void prob3() {
    // Declare Variables
    int userIn;
    int smNum{1000};
    int lgNum{-1000};

    // Initialize Variables
    do {
        cin >> userIn;
        if (userIn != -99) {
            if (userIn < smNum)
                smNum = userIn;
            if (userIn > lgNum)
                lgNum = userIn;
        }
    } while (userIn != -99);

    // Map/Process the Inputs -> Outputs

    // Display Inputs/Outputs
    cout << "Smallest number in the series is " << smNum << '\n';
    cout << "Largest number in the series is " << lgNum << "\n\n";
}

void prob4() {
    // Declare Variables
    int recSize;
    char recChar;
    string recRow;

    // Initialize Variables
    cin >> recSize >> recChar;
    while (recSize > 15 || recSize < 1) {
        cout << "Invalid Size. Enter a new rectangle size between 1 and 15: ";
        cin >> recSize;
    }
    // Map/Process the Inputs -> Outputs

    // Display Inputs/Outputs
    for (int row{1}; row <= recSize; row++) {
        for (int col{1}; col <= recSize; col++)
            recRow += recChar;
        cout << recRow << '\n';
        recRow = "";
    }
    cout << '\n';
}

void prob5() {
    // Declare Variables
    int ptrnSze;
    string ptrnRow;

    // Initialize Variables
    cin >> ptrnSze;

    // Map/Process the Inputs -> Outputs

    // Display Inputs/Outputs
    for (int size{1}; size <= ptrnSze; size++) {
        ptrnRow = string(size, '+');
        cout << ptrnRow << '\n';
    }
    for (int size{ptrnSze}; size >= 1; size--) {
        ptrnRow = string(size, '+');
        cout << ptrnRow << '\n';
    }
    cout << '\n';
}

void prob6() {
    // Global Constants not Variables
    // Science, Math, Conversions, Dimensions
    const float galPLit{0.264179f};

    // Declare Variables
    char usrChce{};
    float litCons{};
    float galCons{};
    int miTrav{};

    do {
        // Initialize Variables
        cout << "Enter number of liters of gasoline: ";
        cin >> litCons;
        cout << "Enter number of miles traveled: ";
        cin >> miTrav;

        // Map/Process the Inputs -> Outputs
        galCons = litCons * galPLit;

        // Display Inputs/Outputs
        cout << fixed << setprecision(2);
        cout << "Miles per Gallon: ";
        cout << calcMPG(miTrav, galCons) << "\n\n";

        cout << "Again: ";
        cin >> usrChce;
        // Convert input to upper case so the program can take lower and upper case input
        usrChce = static_cast<char>(toupper(usrChce));
        cout << '\n';
    } while (usrChce == 89);
}

float calcMPG(int miTrav, float galCons) {
    return static_cast<float>(miTrav) / galCons;
}

void prob7() {
    // Global Constants not Variables
    // Science, Math, Conversions, Dimensions
    const float galPLit{0.264179f};

    // Declare Variables
    char usrChce{};
    float Lcons1{};
    float Lcons2{};
    float galCon1{};
    float galCon2{};
    int disTrv1{};
    int disTrv2{};

    float MPGCar1{};
    float MPGCar2{};

    cout << fixed << setprecision(2);
    do {
        // Initialize Variables & Map/Process the Inputs -> Outputs
        cout << "Car 1" << '\n';
        cout << "Enter number of liters of gasoline: ";
        cin >> Lcons1;
        cout << "Enter number of miles traveled: ";
        cin >> disTrv1;

        galCon1 = Lcons1 * galPLit;
        MPGCar1 = calcMPG(disTrv1, galCon1);
        cout << "Miles per Gallon: ";
        cout << MPGCar1 << "\n\n";

        cout << "Car 2" << '\n';
        cout << "Enter number of liters of gasoline: ";
        cin >> Lcons2;
        cout << "Enter number of miles traveled: ";
        cin >> disTrv2;

        galCon2 = Lcons2 * galPLit;
        MPGCar2 = calcMPG(disTrv2, galCon2);
        cout << "Miles per Gallon: ";
        cout << MPGCar2 << "\n\n";

        // Display Inputs/Outputs
        if (MPGCar1 > MPGCar2)
            cout << "Car 1 is more fuel efficient\n\n";
        else if (MPGCar1 < MPGCar2)
            cout << "Car 2 is more fuel efficient\n\n";
        else
            cout << "Both cars have an equal fuel efficiency\n\n";

        cout << "Again: ";
        cin >> usrChce;
        // Convert input to upper case so the program can take lower and upper case input
        usrChce = static_cast<char>(toupper(usrChce));
        cout << '\n';
    } while (usrChce == 89);
}

void prob8() {
    // Declare Variables
    char usrChce{};
    float oldPrce{};
    float newPrce{};
    float inflRte{};

    do {
        // Initialize Variables
        cout << "Enter current price: ";
        cin >> newPrce;
        cout << "Enter year-ago price: ";
        cin >> oldPrce;

        // Map/Process the Inputs -> Outputs
        inflRte = calcInfRate(oldPrce, newPrce);

        // Display Inputs/Outputs
        cout << fixed << setprecision(2) << "Inflation rate: " << inflRte << "%\n\n";

        cout << "Again: ";
        cin >> usrChce;
        usrChce = static_cast<char>(toupper(usrChce));
        cout << '\n';
    } while (usrChce == 89);
}

float calcInfRate(float oldPrce, float newPrce) {
    return ((newPrce - oldPrce) / oldPrce) * 100;
}

void prob9() {
    // Declare Variables
    char usrChce{};
    float oldPrce{};
    float newPrce{};
    float inflRte{};

    do {
        // Initialize Variables
        cout << "Enter current price: ";
        cin >> newPrce;
        cout << "Enter year-ago price: ";
        cin >> oldPrce;
        cout << '\n';

        // Map/Process the Inputs -> Outputs
        inflRte = calcInfRate(oldPrce, newPrce);

        // Display Inputs/Outputs
        cout << fixed << setprecision(2);
        cout << "Inflation rate: " << inflRte << "%\n";
        cout << "Price in one year: $" << calcEstPrce(newPrce, inflRte, 1) << '\n';
        cout << "Price in two year: $" << calcEstPrce(newPrce, inflRte, 2) << "\n\n";

        cout << "Again: ";
        cin >> usrChce;
        usrChce = static_cast<char>(toupper(usrChce));
        cout << '\n';
    } while (usrChce == 89);
}

float calcEstPrce(float itmPrce, float inflRte, int durYear) {
    // https://www.fe.training/free-resources/project-finance/modelling-inflation/
    return itmPrce *= pow(1 + (inflRte / 100), durYear);
}

void prob10() {
    // Declare Variables
    float num1{};
    float num2{};
    float num3{};

    // Initialize Variables
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter Second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;
    cout << '\n';

    // Map/Process the Inputs -> Outputs

    // Display Inputs/Outputs
    cout << setprecision(0);
    cout << "Largest number from two parameter function: "
            << maxNum(num1, num2) << "\n";
    cout << "Largest number from three parameter function: "
            << maxNum(num1, num2, num3) << "\n\n";
}

float maxNum(float num1, float num2) {
    if (num1 > num2)
        return num1;
    else
        return num2;
}

float maxNum(float num1, float num2, float num3) {
    if (num1 > num2) {
        if (num3 > num1)
            return num3;
        else
            return num1;
    } else {
        if (num3 > num2)
            return num3;
        else
            return num2;
    }
}

void menu() {
    cout << "1 -> Problem 1" << endl;
    cout << "2 -> Problem 2" << endl;
    cout << "3 -> Problem 3" << endl;
    cout << "4 -> Problem 4" << endl;
    cout << "5 -> Problem 5" << endl;
    cout << "6 -> Problem 6" << endl;
    cout << "7 -> Problem 7" << endl;
    cout << "8 -> Problem 8" << endl;
    cout << "9 -> Problem 9" << endl;
    cout << "10 -> Problem 10" << endl;
    cout << "11 -> Exit Program" << endl;
}
