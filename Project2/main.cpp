/*
 * File:   main.cpp
 * Author: Anthony Morales
 * Created on June 6, 2026, 3:36 PM 
 * Purpose: Project 2 - Blackjack
 */

// System Libraries
#include <iostream>	 // Input Output Library
#include <ctime>	 // Time Library
#include <cstdlib>	 // General Utilities Library
#include <cmath>	 // Math Library
#include <fstream>	 // File I/O Library
#include <cctype>	 // Character Handling Library
#include <string>	 // String Library
#include <vector>    // Vector Library
using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions

// Function Prototypes
bool isVldOp(const char &input, vector<char> vldOpts);

bool inRange(const float &input, const float &min, const float &max);

int max(const int &a, const int &b);

float max(const float &a, const float &b);

int min(const int &a, const int &b);

float min(const float &a, const float &b);

// Execution begins here at main
int main(int argc, char **argv) {
    // Set random number seed
    srand(time(0));

    /*
     * Declare Variables
     */

    char plrChce{}; // Player Input - Character Input
    float plrInpt{}; // Player Input - Numeric Input
    string plrStr{}; // Used for determining if the save file is valid and not corrupted
    char curDrwC{}; // Current card drawn
    bool plrSplt{false}; // Game flag to determine if player can split/chooses to split
    bool plrDbDn{false}; // Game flag to determine if player can double down/chooses to double down

    fstream sveFile{"./blackjackSaveFile.txt", ios::in}; // Save File


    /* Keeps track of game state
     * 1s Place: Player Hand 1, 10s Place: Player Hand 2
     * States: 0: Default (continue), 1: Push (Player/Dealer Blackjack), 2: Player Blackjack, 3: Dealer Blackjack
     * 4: Double Down, 5: Surrender, 6: Stand, 7: Player Bust, 8: Dealer Bust
     */
    char gameSte{00};

    // Player Variables/Statistics
    unsigned int plrCash{10000}; // Player Cash
    unsigned short plrChps{}; // Player Casino Chips

    unsigned short plrBet1{}; // Wager for first player hand
    unsigned short plrBet2{}; // Wager for second player hand

    unsigned short plrWins{0}; // Player Statistics - Wins
    unsigned short plrLoss{0}; // Player Statistics - Losses

    // Player Hands
    char plrHnd1{}; // Player Hand 1
    char plrHnd2{}; // Player Hand 2

    // Dealer Hand/Cards
    char delCrd1{}; // Dealer Hand/Card 1
    char delCrd2{}; // Dealer Card 2

    /*
     * Initialize Variables
     */

    // Check if default save file exists
    if (sveFile.is_open()) {
        cout << "Save file has been detected, would you like to load your game save? (Y or N): ";
        cin >> plrChce;
        plrChce = static_cast<char>(toupper(plrChce));

        // Input validation
        while (!isVldOp(plrChce, vector<char>{'Y', 'N'})) {
            cout << "Invalid option. Enter new option (Y or N): ";
            cin >> plrChce;
            plrChce = static_cast<char>(toupper(plrChce));
        }
        if (plrChce == 89) {
            sveFile >> plrStr;
            // Checks if string marker is inside the save file, which determines if the save file is valid or corrupted
            if (plrStr != "ValidSaveFile")
                cout << "Save file has been corrupted. Starting new save file.\n";
            else {
                sveFile >> plrCash >> plrWins >> plrLoss;
                if (plrCash == 0) {
                    cout << "No cash available. Restarting with $10,000.\n";
                    plrCash = 10'000;
                }
            }
            cout << "Player Statistics:\n* Wins: " << plrWins << "\n* Losses: " << plrLoss << "\n* Cash: " <<
                    plrCash << "\n* Chips: " << plrChps << "\n";
        }
        sveFile.close();
    }
    // Reopens save file for writing
    sveFile.open("./blackjackSaveFile.txt", ios::out | ios::trunc);

    // Purchase Chips
    cout << "How much money would you like to spend to buy chips (Whole $ only) [$5 to $" << (plrCash >= 65'000
            ? "65,000]: "
            : plrCash >= 1000
                  ? to_string(plrCash / 1000) + "," + string(3 - to_string(plrCash % 1000).length(), '0') + to_string(
                        plrCash % 1000) + "]: "
                  : to_string(plrCash) + "]: ");
    cin >> plrInpt;
    plrInpt = floor(plrInpt);

    // Verify purchased chip amount is a valid amount and that the player has enough cash
    while (!inRange(plrInpt, 5.0f, min(static_cast<float>(plrCash), 65'000.0f))) {
        cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $" << (plrCash >= 65'000
                                                                                   ? "65,000]: "
                                                                                   : plrCash >= 1000
                                                                                           ? to_string(plrCash / 1000) +
                                                                                               "," + string(
                                                                                                   3 - to_string(
                                                                                                       plrCash % 1000).
                                                                                                   length(), '0') +
                                                                                               to_string(plrCash % 1000)
                                                                                               + "]: "
                                                                                           : to_string(
                                                                                                   plrCash) + "]: ");
        cin >> plrInpt;
        plrInpt = floor(plrInpt);
    }
    plrChps = static_cast<unsigned short>(floor(plrInpt));
    plrCash -= plrChps;

    // Game Loop
    do {
        // Get player wager
        cout << "Enter wager amount (Whole $ only) [$5 to $" << (plrChps >= 10000
                                                                     ? "10,000]: "
                                                                     : plrChps >= 1000
                                                                           ? to_string(plrChps / 1000) + "," + string(
                                                                                 3 - to_string(plrChps % 1000).length(),
                                                                                 '0') + to_string(plrChps % 1000) +
                                                                             "]: "
                                                                           : to_string(plrChps) + "]: ");
        cin >> plrInpt;
        plrInpt = floor(plrInpt);

        // Verify player wager is valid amount and that the player has enough chips
        while (!inRange(plrInpt, 5.0f, min(static_cast<float>(plrChps), 10'000.0f))) {
            cout << "Invalid amount. Enter new amount (Whole $ only) [$5 to $" << (plrChps >= 10000
                    ? "10,000]: "
                    : plrChps >= 1000
                          ? to_string(plrChps / 1000) + "," + string(3 - to_string(plrChps % 1000).length(), '0') +
                            to_string(plrChps % 1000) + "]: "
                          : to_string(plrChps) + "]: ");
            cin >> plrInpt;
            plrInpt = floor(plrInpt);
        }

        plrBet1 = static_cast<unsigned short>(floor(plrInpt));
        plrChps -= plrBet1;

        //
        // Player Card Drawing
        //

        // Draw first player card
        plrHnd1 = (rand() % 11) + 1;
        switch (plrHnd1) {
            case 11:
                cout << "Your first card is an ace.\n";
                break;
            case 10:
                cout << "Your first card is a 10/face card.\n";
                break;
            default:
                cout << "Your first card is a(n) " << static_cast<int>(plrHnd1) << " card.\n";
        }

        // Draw second player card
        curDrwC = (rand() % 11) + 1;
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
                // Determines if the two drawn cards are pairs, and updates the plrSplt flag accordingly
                plrSplt = plrHnd1 == curDrwC;
                plrHnd1 += curDrwC;
                break;
            default:
                cout << "Your second card is a(n) " << static_cast<int>(curDrwC) << " card.\n";
                // Determines if the two drawn cards are pairs, and updates the plrSplt flag accordingly
                plrSplt = plrHnd1 == curDrwC;
                plrHnd1 += curDrwC;
        }

        //
        // Dealer Draw Cards
        //

        // Draw first dealer card
        delCrd1 = (rand() % 11) + 1;
        switch (delCrd1) {
            case 11:
                cout << "The dealer's first card is an ace.\n";
                break;
            case 10:
                cout << "The dealer's first card is a 10/face card.\n";
                break;
            default:
                cout << "The dealer's first card is a(n) " << static_cast<int>(delCrd1) << " card.\n";
        }

        // Draw second dealer card
        delCrd2 = (rand() % 11) + 1;
        // Check if first card is an ace, if it is, count the second card with a value of 1
        delCrd2 = delCrd1 == 11 ? 1 : delCrd2;

        // Check if player has a blackjack
        if (plrHnd1 == 21)
            gameSte = 2;

        // Check if dealer has a blackjack
        if (delCrd1 + delCrd2 == 21) {
            if (gameSte == 2)
                gameSte = 1;
            else
                gameSte = 3;
        }

        if (gameSte == 0) {
            // Player card splitting - Checks if the player was dealt a pair and if the player have enough chips to split
            if (plrSplt && plrChps >= plrBet1) {
                cout << "You have been dealt a pair, would you like to split your cards? (Y or N): ";
                cin >> plrChce;
                plrChce = static_cast<char>(toupper(plrChce));

                // Input validation
                while (!isVldOp(plrChce, vector<char>{'Y', 'N'})) {
                    cout << "Invalid option. Enter new option (Y or N): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }

                if (plrChce == 89) {
                    plrHnd2 = plrHnd1 / 2;
                    plrHnd1 /= 2;
                    plrBet2 = plrBet1;
                    plrChps -= plrBet2;
                } else {
                    plrSplt = false;
                }
            } else
                plrSplt = false;

            // Checks if the player has enough chips to double down and updates the plrDbDn flag accordingly
            plrDbDn = plrChps >= plrBet1;

            cout << "Enter Option (Player Hand 1: " << static_cast<int>(plrHnd1) << ", Dealer Hand: " << static_cast<
                        int>(delCrd1) << ")\nS: Stand, H: Hit"
                    << (plrDbDn ? ", D: Double Down" : "") << (!plrSplt ? ", X: Surrender" : "") << " -> ";
            cin >> plrChce;
            plrChce = static_cast<char>(toupper(plrChce));

            // Input validation based on game flags and whether the player split their cards and can double down
            if (plrSplt && plrDbDn) {
                while (!isVldOp(plrChce, vector<char>{'S', 'D', 'H'})) {
                    cout << "Invalid option. Enter new option (S: Stand, H: Hit, D: Double Down): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            } else if (plrSplt && !plrDbDn) {
                while (!isVldOp(plrChce, vector<char>{'S', 'H'})) {
                    cout << "Invalid option. Enter new option (S: Stand, H: Hit): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            } else if (!plrSplt && plrDbDn) {
                while (!isVldOp(plrChce, vector<char>{'S', 'H', 'D', 'X'})) {
                    cout << "Invalid option. Enter new option (S: Stand, H: Hit, D: Double Down, X: Surrender): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            } else {
                while (!isVldOp(plrChce, vector<char>{'S', 'H', 'X'})) {
                    cout << "Invalid option. Enter new option (S: Stand, H: Hit, X: Surrender): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            }

            switch (plrChce) {
                case 'X':
                    gameSte = 5;
                    break;
                case 'S':
                    cout << "You have chosen to stand.\n";
                    gameSte = 6;
                    break;
                case 'D':
                    cout << "You have chosen to double down and double your wager. ";
                    plrChps -= plrBet1;
                    plrBet1 *= 2;
                    curDrwC = (rand() % 11) + 1;
                    switch (curDrwC) {
                        case 11:
                            if (plrHnd1 > 10) {
                                cout << "Your third card is an ace, counted with a value of 1.\n";
                                plrHnd1++;
                            } else {
                                cout << "Your third card is an ace.\n";
                                plrHnd1 += curDrwC;
                            }
                            break;
                        case 10:
                            cout << "Your third card is a 10/face card.\n";
                            plrHnd1 += curDrwC;
                            break;
                        default:
                            cout << "Your third card is a(n) " << static_cast<int>(curDrwC) << " card.\n";
                            plrHnd1 += curDrwC;
                    }
                    if (plrHnd1 > 21)
                        gameSte = 7;
                    else if (plrHnd1 == 21)
                        gameSte = 2;
                    else
                        gameSte = 4;
                    break;
                default:
                    curDrwC = (rand() % 11) + 1;
                    switch (curDrwC) {
                        case 11:
                            if (plrHnd1 > 10) {
                                cout << "You have drawn an ace, counted with a value of 1.\n";
                                plrHnd1++;
                            } else {
                                cout << "You have drawn an ace.\n";
                                plrHnd1 += curDrwC;
                            }
                            break;
                        case 10:
                            cout << "You have drawn a 10/face card.\n";
                            plrHnd1 += curDrwC;
                            break;
                        default:
                            cout << "Your have drawn a(n) " << static_cast<int>(curDrwC) << " card.\n";
                            plrHnd1 += curDrwC;
                    }
                    if (plrHnd1 > 21)
                        gameSte = 7;
                    else if (plrHnd1 == 21)
                        gameSte = 2;
                    break;
            }

            if (gameSte == 0) {
                do {
                    cout << "Enter Option (Player Hand 1: " << static_cast<int>(plrHnd1) << ", Dealer Hand: " <<
                            static_cast<int>(delCrd1) << ")\nS: Stand, H: Hit -> ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));

                    // Input validation
                    while (!isVldOp(plrChce, vector<char>{'S', 'H'})) {
                        cout << "Invalid option. Enter new option (S: Stand, H: Hit): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }

                    switch (plrChce) {
                        case 'S':
                            gameSte = 6;
                            break;
                        default:
                            curDrwC = (rand() % 11) + 1;
                            switch (curDrwC) {
                                case 11:
                                    if (plrHnd1 > 10) {
                                        cout << "You have drawn an ace, counted with a value of 1.\n";
                                        plrHnd1++;
                                    } else {
                                        cout << "You have drawn an ace.\n";
                                        plrHnd1 += curDrwC;
                                    }
                                    break;
                                case 10:
                                    cout << "You have drawn a 10/face card.\n";
                                    plrHnd1 += curDrwC;
                                    break;
                                default:
                                    cout << "Your have drawn a(n) " << static_cast<int>(curDrwC) << " card.\n";
                                    plrHnd1 += curDrwC;
                            }
                            if (plrHnd1 > 21)
                                gameSte = 7;
                            else if (plrHnd1 == 21)
                                gameSte = 2;
                            break;
                    }
                } while (gameSte == 0);
            }

            // Player second hand turn if they chose to split their hand
            if (plrSplt) {
                // Checks if the player has enough chips to double down and updates the plrDbDn flag accordingly
                plrDbDn = plrChps >= plrBet2;

                cout << "Enter Option (Player Hand 2: " << static_cast<int>(plrHnd2) << ", Dealer Hand: " << static_cast
                        <int>(delCrd1)
                        << ")\nS: Stand, H: Hit" << (plrDbDn ? ", D: Double Down" : "") << " -> ";
                cin >> plrChce;
                plrChce = static_cast<char>(toupper(plrChce));

                // Input validation based on if the player can double down or not
                if (plrDbDn) {
                    while (!isVldOp(plrChce, vector<char>{'S', 'H', 'D'})) {
                        cout << "Invalid option. Enter new option (S: Stand, H: Hit, D: Double Down): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }
                } else {
                    while (!isVldOp(plrChce, vector<char>{'S', 'H'})) {
                        cout << "Invalid option. Enter new option (S: Stand, H: Hit): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }
                }

                switch (plrChce) {
                    case 'S':
                        cout << "You have chosen to stand.\n";
                        gameSte += 60;
                        break;
                    case 'D':
                        cout << "You have chosen to double down and double your wager. ";
                        plrChps -= plrBet2;
                        plrBet2 *= 2;
                        curDrwC = (rand() % 11) + 1;
                        switch (curDrwC) {
                            case 11:
                                if (plrHnd2 > 10) {
                                    cout << "Your third card is an ace, counted with a value of 1.\n";
                                    plrHnd2++;
                                } else {
                                    cout << "Your third card is an ace.\n";
                                    plrHnd2 += curDrwC;
                                }
                                break;
                            case 10:
                                cout << "Your third card is a 10/face card.\n";
                                plrHnd2 += curDrwC;
                                break;
                            default:
                                cout << "Your third card is a(n) " << static_cast<int>(curDrwC) << " card.\n";
                                plrHnd2 += curDrwC;
                        }
                        if (plrHnd2 > 21)
                            gameSte += 70;
                        else if (plrHnd2 == 21)
                            gameSte += 20;
                        else
                            gameSte += 40;
                        break;
                    default:
                        curDrwC = (rand() % 11) + 1;
                        switch (curDrwC) {
                            case 11:
                                if (plrHnd2 > 10) {
                                    cout << "You have drawn an ace, counted with a value of 1.\n";
                                    plrHnd2++;
                                } else {
                                    cout << "You have drawn an ace.\n";
                                    plrHnd2 += curDrwC;
                                }
                                break;
                            case 10:
                                cout << "You have drawn a 10/face card.\n";
                                plrHnd2 += curDrwC;
                                break;
                            default:
                                cout << "Your have drawn a(n) " << static_cast<int>(curDrwC) << " card.\n";
                                plrHnd2 += curDrwC;
                        }
                        if (plrHnd2 > 21)
                            gameSte += 70;
                        else if (plrHnd2 == 21)
                            gameSte += 20;
                        break;
                }

                if (gameSte / 10 == 0) {
                    do {
                        cout << "Enter Option (Player Hand 2: " << static_cast<int>(plrHnd2) << ", Dealer Hand: " <<
                                static_cast<int>(delCrd1) << ")\nS: Stand, H: Hit -> ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                        while (plrChce != 83 && plrChce != 72) {
                            cout << "Invalid option. Enter new option (S: Stand, H: Hit): ";
                            cin >> plrChce;
                            plrChce = static_cast<char>(toupper(plrChce));
                        }

                        switch (plrChce) {
                            case 'S':
                                gameSte += 60;
                                break;
                            default:
                                curDrwC = (rand() % 11) + 1;
                                switch (curDrwC) {
                                    case 11:
                                        if (plrHnd2 > 10) {
                                            cout << "You have drawn an ace, counted with a value of 1.\n";
                                            plrHnd2++;
                                        } else {
                                            cout << "You have drawn an ace.\n";
                                            plrHnd2 += curDrwC;
                                        }
                                        break;
                                    case 10:
                                        cout << "You have drawn a 10/face card.\n";
                                        plrHnd2 += curDrwC;
                                        break;
                                    default:
                                        cout << "Your have drawn a(n) " << static_cast<int>(curDrwC) << " card.\n";
                                        plrHnd2 += curDrwC;
                                }
                                if (plrHnd2 > 21)
                                    gameSte += 70;
                                else if (plrHnd2 == 21)
                                    gameSte += 20;
                                break;
                        }
                    } while (gameSte / 10 == 0);
                }
            }

            // Checks if the player's hand(s) have already gone bust or not
            if (gameSte != 5 && !((!plrSplt && gameSte % 10 == 7) || (
                                      gameSte % 10 == 7 && plrSplt && gameSte / 10 == 7))) {
                /*
                 * Dealer's turn
                 */
                switch (delCrd2) {
                    case 11:
                        cout << "The dealer's second card is an ace.\n";
                        break;
                    case 10:
                        cout << "The dealer's second card is a 10/face card.\n";
                        break;
                    default:
                        cout << "The dealer's second card is a(n) " << static_cast<int>(delCrd2) << " card.\n";
                }

                // Dealer stands on soft 17
                while (delCrd1 + delCrd2 < 17) {
                    delCrd1 += delCrd2;
                    delCrd2 = (rand() % 11) + 1;
                    switch (delCrd2) {
                        case 11:
                            cout << "The dealer draws another card and it is an ace.\n";
                            break;
                        case 10:
                            cout << "The dealer draws another card and it is a 10/face card.\n";
                            break;
                        default:
                            cout << "The dealer draws another card and it is a(n) " << static_cast<int>(delCrd2) <<
                                    " card.\n";
                    }
                }

                if (delCrd1 + delCrd2 > 21)
                    gameSte = 8;
                else if (delCrd1 + delCrd2 == 21) {
                    // Updates gameSte variable based on if the player has a blackjack or not
                    gameSte = (gameSte % 10 == 2 ? gameSte / 10 + 1 : gameSte / 10 + 3);
                    gameSte = (gameSte / 10 == 2 ? gameSte % 10 + 10 : gameSte % 10 + 30);
                }
            }
        }

        cout << "Player Hand 1: " << static_cast<int>(plrHnd1) << (plrHnd2 != 0
                                                                       ? ", Player Hand 2: " + to_string(plrHnd2)
                                                                       : "") << ", Dealer Hand: " << static_cast<int>(
            delCrd1 + delCrd2) << '\n';

        // Game payout/ending
        if (gameSte == 8) {
            cout << "Dealer has gone bust, you win 1x your wager" << (plrSplt ? " for both hands" : "") <<
                    "!.\n";
            plrChps += plrBet1 * 2 + plrBet2 * 2;
            plrWins++;
        } else if (gameSte == 5) {
            cout << "You have chose to surrender your hand, you receive half your original bet back.\n";
            plrChps += static_cast<unsigned short>(floor(plrBet1 / 2));
            plrLoss++;
        } else {
            if (gameSte % 10 == 1) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand and the dealer's hand are both blackjack's." << (
                    plrSplt
                        ? " Your first hand is a push"
                        : " Game ends in a push") << ".\n";
                plrChps += plrBet1;
            } else if (gameSte % 10 == 2) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand is a blackjack!" << (plrSplt
                        ? " You win 1.5x your wager for your first hand"
                        : " You win 1.5x your wager") << "!\n";
                plrChps += plrBet1 + static_cast<unsigned short>(ceil(plrBet1 * 1.5f));
                plrWins++;
            } else if (gameSte % 10 == 3) {
                cout << "The dealer's hand is a blackjack and your" << (plrSplt ? " first" : "") << " hand is not." <<
                        (plrSplt ? " You lose your first hand" : " You lose") << ".\n";
                plrLoss++;
            } else if (gameSte % 10 == 7) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand has gone bust." << (
                    plrSplt ? " You lose your first hand" : " You lose") << ".\n";
                plrLoss++;
            } else {
                if (plrHnd1 > delCrd1 + delCrd2) {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is larger than the dealer's hand." << (plrSplt
                            ? " You win 1x your wager for your first hand"
                            : " You win 1x your wager") << "!\n";
                    plrChps += plrBet1 * 2;
                    plrWins++;
                } else if (plrHnd1 == delCrd1 + delCrd2) {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is equal to the dealer's hand." << (plrSplt
                            ? " Your first hand is a push"
                            : " Game ends in a push") << ".\n";
                    plrChps += plrBet1;
                } else {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is smaller than the dealer's hand." << (
                        plrSplt ? " You lose your first hand" : " You lose") << ".\n";
                    plrLoss++;
                }
            }

            if (plrSplt) {
                if (gameSte / 10 == 1) {
                    cout <<
                            "Your second hand and the dealer's hand are both blackjack's. Your second hand ends in a push.\n";
                    plrChps += plrBet2;
                } else if (gameSte / 10 == 2) {
                    cout << "Your second hand is a blackjack! You win 1.5x your wager for your second hand!\n";
                    plrChps += plrBet2 + static_cast<unsigned short>(ceil(plrBet2 * 1.5f));
                    plrWins++;
                } else if (gameSte / 10 == 3) {
                    cout <<
                            "The dealer's hand is a blackjack and your second hand is not. You lose your second hand.\n";
                    plrLoss++;
                } else if (gameSte / 10 == 7) {
                    cout << "Your second hand has gone bust. You lose your second hand.\n";
                    plrLoss++;
                } else {
                    if (plrHnd2 > delCrd1 + delCrd2) {
                        cout <<
                                "Your first hand is larger than the dealer's hand. You are paid 1x your wager for your second hand!\n";
                        plrChps += plrBet2 * 2;
                        plrWins++;
                    } else if (plrHnd2 == delCrd1 + delCrd2) {
                        cout << "Your second hand is equal to the dealer's hand. Your second hand is a push.\n";
                        plrChps += plrBet2;
                    } else {
                        cout << "Your second hand is smaller than the dealer's hand. You lose your second hand.\n";
                        plrLoss++;
                    }
                }
            }
        }
        cout << "Player Statistics:\n* Wins: " << plrWins << "\n* Losses: " << plrLoss << "\n* Cash: " <<
                plrCash << "\n* Chips: " << plrChps << "\n";

        // Checks if the player has enough chips and cash to continue playing
        if (plrChps < 5 && plrCash < 5) {
            cout << "You do not have enough cash or chips to continue playing. Game over.\n";
            plrChce = 69;
        } else {
            // Game End
            cout << "Enter Option (N: New Game, E: Exit & Save): ";
            cin >> plrChce;
            plrChce = static_cast<char>(toupper(plrChce));

            // Input validation
            while (!isVldOp(plrChce, vector<char>{'N', 'E'})) {
                cout << "Invalid option. Enter new option (N: New Game, E: Exit): ";
                cin >> plrChce;
                plrChce = static_cast<char>(toupper(plrChce));
            }

            if (plrChce == 78) {
                if (plrCash >= 5) {
                    cout << "Would you like to purchase more chips? (Y or N) (Current Amount: " << plrChps << "): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));

                    // Input validation
                    while (!isVldOp(plrChce, vector<char>{'Y', 'N'})) {
                        cout << "Invalid option. Enter new option (Y or N): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }
                    if (plrChce == 89) {
                        cout << "How much money would you like to spend to buy chips (Whole $ only) [$5 to $" << (
                            plrCash >= 65'000
                                ? "65,000]: "
                                : plrCash >= 1000
                                      ? to_string(plrCash / 1000) + "," + string(
                                            3 - to_string(plrCash % 1000).length(),
                                            '0') + to_string(plrCash % 1000) + "]: "
                                      : to_string(plrCash) + "]: ");
                        cin >> plrInpt;
                        plrInpt = floor(plrInpt);

                        // Verify purchased chip amount is a valid amount and that the player has enough cash
                        while (!inRange(plrInpt, 5.0f, min(static_cast<float>(plrCash), 65'000.0f))) {
                            cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $" << (plrCash >= 65'000
                                    ? "65,000]: "
                                    : plrCash >= 1000
                                          ? to_string(plrCash / 1000) + "," + string(
                                                3 - to_string(plrCash % 1000).length(),
                                                '0') + to_string(plrCash % 1000) + "]: "
                                          : to_string(plrCash) + "]: ");
                            cin >> plrInpt;
                            plrInpt = floor(plrInpt);
                        }
                        plrChps += static_cast<unsigned short>(floor(plrInpt));
                        plrCash -= static_cast<unsigned short>(floor(plrInpt));
                    }
                }

                // Reset Variables
                curDrwC = 0;
                plrSplt = false;
                plrDbDn = false;
                gameSte = 0;
                plrBet1 = 0;
                plrBet2 = 0;
                plrHnd1 = 0;
                plrHnd2 = 0;
                delCrd1 = 0;
                delCrd2 = 0;
                cout << '\n';
            }
        }
    } while (plrChce != 69);

    // Save to Game File
    plrCash += plrChps;
    sveFile << "ValidSaveFile" << '\n';
    sveFile << plrCash << '\n';
    sveFile << plrWins << '\n';
    sveFile << plrLoss << '\n';
    sveFile.close();

    // Exit the Program
    return 0;
}

// Functions

bool isVldOp(const char &input, vector<char> vldOpts) {
    // Bubble Sort
    bool isChng{false};
    char temp{};
    do {
        isChng = false;
        for (int i{0}; i < vldOpts.size() - 1; i++) {
            if (vldOpts[i] > vldOpts[i + 1]) {
                temp = vldOpts[i];
                vldOpts[i] = vldOpts[i + 1];
                vldOpts[i + 1] = temp;
                isChng = true;
            }
        }
    } while (isChng);

    // Binary Search
    int left{0};
    int middle{};
    int right{static_cast<int>(vldOpts.size() - 1)};

    while (left <= right) {
        middle = left + (right - left) / 2;

        if (input == vldOpts[middle])
            return true;
        if (input < vldOpts[middle])
            right = middle - 1;
        if (input > vldOpts[middle])
            left = middle + 1;
    }
    return false;
}

bool inRange(const float &input, const float &min, const float &max) {
    return input <= max && input >= min;
}

int max(const int &a, const int &b) {
    if (a >= b)
        return a;
    return b;
}

float max(const float &a, const float &b) {
    if (a >= b)
        return a;
    return b;
}

int min(const int &a, const int &b) {
    if (a <= b)
        return a;
    return b;
}

float min(const float &a, const float &b) {
    if (a <= b)
        return a;
    return b;
}
