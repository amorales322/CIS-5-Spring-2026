/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on May 12, 2026, 1:27 PM
 * Purpose: Project 1 - Blackjack 
 */

// System Libraries
#include <iostream>  // Input Output Library
#include <iomanip>   // Output Number Formatting Library
#include <ctime>     // Time Library
#include <cstdlib>   // General Utilities Library
#include <cmath>     // Math Library
#include <fstream>   // File I/O Library
#include <cctype>    // Character Handling Library
#include <string>    // String Library
#include <algorithm> // Algorithm Library

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
	bool gameOvr{false};
	bool playr21{false};
	bool dealr21{false};
	
	char plrChce{};
	float plrInpt{};

	unsigned int plrCash{9009};
	unsigned short plrChps{};
	unsigned int plyrBet{};
	unsigned short plrWins{};
	unsigned short plrLoss{};

	char plrHnd1{};
	char plrHnd2{};

	char delCrd1{};
	char delCrd2{};

    // Initialize Variables


	// Game Loop
	do {
		cout << "How much money would you like to put to buy chips (Whole $ only) [$5 to $";
		if (plrCash >= 65000)
			cout << "65,000]: ";
		else if (plrCash >= 1000)
			cout << plrCash / 1000 << "," << setfill('0') << setw(3)  << plrCash % 1000 << "]: ";
		else
			cout << plrCash << "]: ";
	
		cin >> plrInpt;
		plrInpt = std::floor(plrInpt);

		while (plrInpt > min(static_cast<float>(plrCash), 65000.0f) || plrInpt < 5.0f) {
			cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $";
			if (plrCash >= 65000)
				cout << "65,000]: ";
			else if (plrCash >= 1000)
				cout << plrCash / 1000 << "," << setfill('0') << setw(3)  << plrCash % 1000 << "]: ";
			else
				cout << plrCash << "]: ";

			cin >> plrInpt; 
		}
		plrChps = static_cast<unsigned short>(floor(plrInpt));


		cout << "Enter Option (N: New Game, E: Exit & Save): ";
		cin >> plrChce;
		plrChce = toupper(plrChce);
		while (plrChce != 78 && plrChce != 69) {
			cout << "Invalid option. Enter New Option (N: New Game, E: Exit): ";				
			cin >> plrChce;
			plrChce = toupper(plrChce);
		}
	} while (plrChce != 69);

    // Exit the Program
    return 0;
}

