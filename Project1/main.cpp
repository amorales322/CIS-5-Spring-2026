/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on May 12, 2026, 1:27 PM
 * Purpose: Project 1 - Blackjack
 */

// System Libraries
#include <iostream>	 // Input Output Library
#include <iomanip>	 // Output Number Formatting Library
#include <ctime>	 // Time Library
#include <cstdlib>	 // General Utilities Library
#include <cmath>	 // Math Library
#include <fstream>	 // File I/O Library
#include <cctype>	 // Character Handling Library
#include <string>	 // String Library
#include <algorithm> // Algorithm Library

using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions

// Function Prototypes

// Execution begins here at main
int main(int argc, char **argv) {
    // Set random number seed
    srand(time(0));

    // Declare Variables
    bool gameOvr{false};
    bool playr21{false};
    bool dealr21{false};

    bool plrSplt{false};

    char plrChce{};
    float plrInpt{};

    unsigned int plrCash{10000};
    unsigned short plrChps{};
    unsigned short plyrBet{};
    unsigned short plrWins{};
    unsigned short plrLoss{};

    char plrHnd1{};
    char plrHnd2{};

    char delCrd1{};
    char delCrd2{};

    char curDrwC{};

    // Initialize Variables

    // Purchase Chips
    cout << "How much money would you like to put to buy chips (Whole $ only) [$5 to $";
    if (plrCash >= 65000)
        cout << "65,000]: ";
    else if (plrCash >= 1000)
        cout << plrCash / 1000 << "," << setfill('0') << setw(3) << plrCash % 1000 << "]: ";
    else
        cout << plrCash << "]: ";
    cin >> plrInpt;
    plrInpt = std::floor(plrInpt);

    // Verify purchased chip amount is a valid amount and that the player has enough cash
    while (plrInpt > min(static_cast<float>(plrCash), 65000.0f) || plrInpt < 5.0f) {
        cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $";
        if (plrCash >= 65000)
            cout << "65,000]: ";
        else if (plrCash >= 1000)
            cout << plrCash / 1000 << "," << setfill('0') << setw(3) << plrCash % 1000 << "]: ";
        else
            cout << plrCash << "]: ";

        cin >> plrInpt;
        plrInpt = std::floor(plrInpt);
    }

    plrChps = static_cast<unsigned short>(floor(plrInpt));
    plrCash -= plrChps;

    // Game Loop
    do {
        // Get Player Wager
        cout << "Enter wager amount (Whole $ only) [$5 to $";
        if (plrChps >= 10000)
            cout << "10,000]: ";
        else if (plrChps >= 1000)
            cout << plrChps / 1000 << "," << setfill('0') << setw(3) << plrChps % 1000 << "]: ";
        else
            cout << plrChps << "]: ";
        cin >> plrInpt;
        plrInpt = std::floor(plrInpt);

        // Verify player wager is valid amount and that the player has enough chips
        while (plrInpt > min(static_cast<float>(plrChps), 10000.0f) || plrInpt < 5.0f) {
            cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $";
            if (plrChps >= 10000)
                cout << "10,000]: ";
            else if (plrChps >= 1000)
                cout << plrChps / 1000 << "," << setfill('0') << setw(3) << plrChps % 1000 << "]: ";
            else
                cout << plrChps << "]: ";
            cin >> plrInpt;
            plrInpt = std::floor(plrInpt);
        }

        plyrBet = static_cast<unsigned short>(floor(plrInpt));
        plrChps -= plyrBet;

        //
        // Player Card Drawing
        //

        // Draw First Player Card
        plrHnd1 = max(rand() % 12, 1);
        switch (plrHnd1) {
            case 11:
                cout << "Your first card is an ace.\n";
                break;
            case 10:
                cout << "Your first card is a 10/face card.\n";
                break;
            default:
                cout << "Your first card is a " << static_cast<int>(plrHnd1) << " card.\n";
        }

        // Draw Second Player Card
        curDrwC = max(rand() % 12, 1);
        switch (curDrwC) {
            case 11:
                if (plrHnd1 == 11) {
                    cout << "Your second card is an ace, counted with a value of 1.\n";
                    plrHnd1++;
                } else {
                    cout << "Your second card is an ace.\n";
                    plrHnd1 += curDrwC;
                }
                break;
            case 10:
                cout << "Your second card is a 10/face card.\n";
                plrSplt = plrHnd1 == curDrwC;
                plrHnd1 += curDrwC;
                break;
            default:
                cout << "Your second card is a " << static_cast<int>(curDrwC) << " card.\n";
                plrSplt = plrHnd1 == curDrwC;
                plrHnd1 += curDrwC;
        }

        //
        // Dealer Draw Cards
        //

        // Draw First Dealer Card
        delCrd1 = max(rand() % 12, 1);
        switch (delCrd1) {
            case 11:
                cout << "The dealer's first card is an ace.\n";
                break;
            case 10:
                cout << "The dealer's first card is a 10/face card.\n";
                break;
            default:
                cout << "The dealer's first card is a " << static_cast<int>(delCrd1) << " card.\n";
        }

        // Draw Second Dealer Card
        delCrd2 = max(rand() % 12, 1);
        // Check if first card is an ace, if it is, count the second card with a value of 1
        delCrd2 = delCrd1 == 11 ? 1 : curDrwC;

        // Check if player has a blackjack
        if (plrHnd1 == 21)
            playr21 = true;

        // Check if dealer has a blackjack
        if (delCrd1 + delCrd2 == 21)
            dealr21 = true;

        // Check if either the player or dealer have a blackjack
        if (playr21 && dealr21) {
            gameOvr = true;
            cout << "You and the dealer have a blackjack, game ends in a push.\n";
        } else if (playr21 && !dealr21) {
            gameOvr = true;
            cout << "You have a blackjack, you win and are paid out 3-to-2.\n";
        } else if (!playr21 && dealr21) {
            gameOvr = true;
            cout << "The dealer has a blackjack and you do not, you lose.\n";
        }

        if (!gameOvr) {
            if (plrSplt && plrChps >= plyrBet) {
                cout << "You have been dealt a pair, would you like to split your cards? (Y or N): ";
                cin >> plrChce;
                plrChce = static_cast<char>(toupper(plrChce));

                while (plrChce != 89 && plrChce != 78) {
                    cout << "Invalid option. Enter New Option (Y or N): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }

                if (plrChce == 89) {
                    plrHnd2 = plrHnd1 / 2;
                    plrHnd1 /= 2;
                } else
                    plrSplt = false;
            }
        }

        // Game End
        cout << "Enter Option (N: New Game, E: Exit & Save): ";
        cin >> plrChce;
        plrChce = static_cast<char>(toupper(plrChce));
        while (plrChce != 78 && plrChce != 69) {
            cout << "Invalid option. Enter New Option (N: New Game, E: Exit): ";
            cin >> plrChce;
            plrChce = static_cast<char>(toupper(plrChce));
        }
    } while (plrChce != 69);

    // Exit the Program
    return 0;
}
