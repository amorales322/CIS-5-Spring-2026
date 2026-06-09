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

int min(const int &a, const int &b);

float min(const float &a, const float &b);

string fmtNum(const int &number);

void genShoe(char shoe[]);

char drawCrd();

string appHand(vector<char> &hand, const char &card);

char popBkHnd(vector<char> &hand);

string outHndT(const char &total1, const char &total2);

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
    bool plrSplt{false}; // Game flag to determine if player can split/chooses to split
    bool plrDbDn{false}; // Game flag to determine if player can double down/chooses to double down

    fstream sveFile{"./blackjackSaveFile.txt", ios::in}; // Save File


    /* Keeps track of game state
     * Index 0: Player Hand 1, Index 1: Player Hand 2
     * States: 0: Default (continue), 1: Push (Player/Dealer Blackjack), 2: Player Blackjack, 3: Dealer Blackjack
     * 4: Double Down, 5: Surrender, 6: Stand, 7: Player Bust, 8: Dealer Bust
     */
    char gameSte[2]{0, 0};

    // Player Variables/Statistics
    unsigned int plrCash{10000}; // Player Cash
    unsigned int plrChps{}; // Player Casino Chips

    unsigned short plrWger[2]{0, 0};

    // Player Statistics
    // 1. Wins
    // 2. Losses
    unsigned short plrStat[2]{0, 0};

    // Player Hands
    vector<char> plrHnd1{0, 0}; // Player Hand 1
    vector<char> plrHnd2{0, 0}; // Player Hand 2

    // Dealer Hand/Cards
    vector<char> delHand{0, 0};

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
                sveFile >> plrCash >> plrStat[0] >> plrStat[1];
                if (plrCash == 0) {
                    cout << "No cash available. Restarting with $10,000.\n";
                    plrCash = 10'000;
                }
            }
            cout << "Player Statistics:\n* Wins: " << plrStat[0] << "\n* Losses: " << plrStat[1] << "\n* Cash: " << plrCash << "\n* Chips: " << plrChps << "\n";
        }
        sveFile.close();
    }
    // Reopens save file for writing
    sveFile.open("./blackjackSaveFile.txt", ios::out | ios::trunc);

    // Purchase Chips
    cout << "How much money would you like to spend to buy chips (Whole $ only) [$5 to $" << fmtNum(min(plrCash, 65'000)) << "]: ";
    cin >> plrInpt;
    plrInpt = floor(plrInpt);

    // Verify purchased chip amount is a valid amount and that the player has enough cash
    while (!inRange(plrInpt, 5.0f, min(static_cast<float>(plrCash), 65'000.0f))) {
        cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $" << fmtNum(min(plrCash, 65'000)) << "]: ";
        cin >> plrInpt;
        plrInpt = floor(plrInpt);
    }
    plrChps = static_cast<unsigned int>(floor(plrInpt));
    plrCash -= plrChps;

    // Game Loop
    do {
        // Get player wager
        cout << "Enter wager amount (Whole $ only) [$5 to $" << fmtNum(min(plrChps, 10'000)) << "]: ";
        cin >> plrInpt;
        plrInpt = floor(plrInpt);

        // Verify player wager is valid amount and that the player has enough chips
        while (!inRange(plrInpt, 5.0f, min(static_cast<float>(plrChps), 10'000.0f))) {
            cout << "Invalid amount. Enter new amount (Whole $ only) [$5 to $" << fmtNum(min(plrChps, 10'000)) << "]: ";
            cin >> plrInpt;
            plrInpt = floor(plrInpt);
        }

        plrWger[0] = static_cast<unsigned short>(floor(plrInpt));
        plrChps -= plrWger[0];

        //
        // Player Card Drawing
        //

        // Draw first player card
        cout << "Your first card is a(n) " << appHand(plrHnd1, drawCrd()) << ".\n";

        // Draw second player card
        cout << "Your second card is a(n) " << appHand(plrHnd1, drawCrd()) << ".\n";

        // Determines if the two drawn cards are pairs, and updates the plrSplt flag accordingly
        plrSplt = (plrHnd1[2] % 13 == 0 || (plrHnd1[2] % 13 >= 10 && plrHnd1[2] % 13 <= 12)) && (plrHnd1[3] % 13 == 0 || (plrHnd1[3] % 13 >= 10 && plrHnd1[3] % 13 <= 12)) ||
                  plrHnd1[2] % 13 == plrHnd1[3] % 13;

        //
        // Dealer Draw Cards
        //

        // Draw first dealer card
        cout << "The dealer's first card is a(n) " << appHand(delHand, drawCrd()) << ".\n";

        // Draw second dealer card
        appHand(delHand, drawCrd());

        // Check if player has a blackjack
        if (plrHnd1[0] == 21)
            gameSte[0] = 2;

        // Check if dealer has a blackjack
        if (delHand[0] == 21) {
            if (gameSte[0] == 2)
                gameSte[0] = 1;
            else
                gameSte[0] = 3;
        }

        if (gameSte[0] == 0) {
            // Player card splitting - Checks if the player was dealt a pair and if the player have enough chips to split
            if (plrSplt && plrChps >= plrWger[0]) {
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
                    appHand(plrHnd2, popBkHnd(plrHnd1));
                    plrWger[1] = plrWger[0];
                    plrChps -= plrWger[1];
                } else
                    plrSplt = false;
            } else
                plrSplt = false;

            // Checks if the player has enough chips to double down and updates the plrDbDn flag accordingly
            plrDbDn = plrChps >= plrWger[0];
            cout << "Enter Option (Player Hand 1: " << outHndT(plrHnd1[0], plrHnd1[1]) << ", Dealer Hand: " << static_cast<int>(delHand[0]) << ")\nS: Stand, H: Hit" << (
                plrDbDn ? ", D: Double Down" : "") << (!plrSplt ? ", X: Surrender" : "") << " -> ";
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
                    gameSte[0] = 5;
                    break;
                case 'S':
                    cout << "You have chosen to stand.\n";
                    gameSte[0] = 6;
                    break;
                case 'D':
                    cout << "You have chosen to double down and double your wager. ";
                    plrChps -= plrWger[0];
                    plrWger[0] *= 2;
                    cout << "Your third card is a(n) " << appHand(plrHnd1, drawCrd()) << ".\n";
                    if (plrHnd1[0] > 21 && plrHnd1[1] > 21)
                        gameSte[0] = 7;
                    else if (plrHnd1[0] == 21 || plrHnd1[1] == 21)
                        gameSte[0] = 2;
                    else
                        gameSte[0] = 4;
                    break;
                default:
                    cout << "Your next card is a(n) " << appHand(plrHnd1, drawCrd()) << ".\n";
                    if (plrHnd1[0] > 21 && plrHnd1[1] > 21)
                        gameSte[0] = 7;
                    else if (plrHnd1[0] == 21 || plrHnd1[1] == 21)
                        gameSte[0] = 2;
            }

            while (gameSte[0] == 0) {
                cout << "Enter Option (Player Hand 1: " << outHndT(plrHnd1[0], plrHnd1[1]) << ", Dealer Hand: " << static_cast<int>(delHand[0]) << ")\nS: Stand, H: Hit -> ";
                cin >> plrChce;
                plrChce = static_cast<char>(toupper(plrChce));

                // Input validation
                while (!isVldOp(plrChce, vector<char>{'S', 'H'})) {
                    cout << "Invalid option. Enter new option (S: Stand, H: Hit): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
                if (plrChce == 83)
                    gameSte[0] = 6;
                else {
                    cout << "Your next card is a(n) " << appHand(plrHnd1, drawCrd()) << ".\n";
                    if (plrHnd1[0] > 21 && plrHnd1[1] > 21)
                        gameSte[0] = 7;
                    else if (plrHnd1[0] == 21 || plrHnd1[1] == 21)
                        gameSte[0] = 2;
                }
            }

            // Player second hand turn if they chose to split their hand
            if (plrSplt) {
                // Checks if the player has enough chips to double down and updates the plrDbDn flag accordingly
                plrDbDn = plrChps >= plrWger[1];

                cout << "Enter Option (Player Hand 2: " << outHndT(plrHnd2[0], plrHnd2[1]) << ", Dealer Hand: " << static_cast<int>(delHand[0]) << ")\nS: Stand, H: Hit" << (
                    plrDbDn ? ", D: Double Down" : "") << " -> ";
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
                        gameSte[1] += 6;
                        break;
                    case 'D':
                        cout << "You have chosen to double down and double your wager. ";
                        plrChps -= plrWger[1];
                        plrWger[1] *= 2;
                        cout << "Your second card is a(n) " << appHand(plrHnd2, drawCrd()) << ".\n";
                        if (plrHnd2[0] > 21 && plrHnd2[1] > 21)
                            gameSte[1] = 7;
                        else if (plrHnd2[0] == 21 || plrHnd2[1] == 21)
                            gameSte[1] = 2;
                        else
                            gameSte[1] = 4;
                        break;
                    default:
                        cout << "Your next card is a(n) " << appHand(plrHnd2, drawCrd()) << ".\n";
                        if (plrHnd2[0] > 21 && plrHnd2[1] > 21)
                            gameSte[1] = 7;
                        else if (plrHnd2[0] == 21 || plrHnd2[1] == 21)
                            gameSte[1] = 2;
                        break;
                }

                while (gameSte[1] == 0) {
                    cout << "Enter Option (Player Hand 2: " << outHndT(plrHnd2[0], plrHnd2[1]) << ", Dealer Hand: " << static_cast<int>(delHand[0]) << ")\nS: Stand, H: Hit -> ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                    while (!isVldOp(plrChce, vector<char>{'S', 'H'})) {
                        cout << "Invalid option. Enter new option (S: Stand, H: Hit): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }

                    if (plrChce == 83)
                        gameSte[1] = 6;
                    else {
                        cout << "Your next card is a(n) " << appHand(plrHnd2, drawCrd()) << ".\n";
                        if (plrHnd2[0] > 21 && plrHnd2[1] > 21)
                            gameSte[1] = 7;
                        else if (plrHnd2[0] == 21 || plrHnd2[1] == 21)
                            gameSte[1] = 2;
                    }
                }
            }

            // Checks if the player's hand(s) have already gone bust or not
            if (gameSte[0] != 5 && ((!plrSplt && gameSte[0] != 7) || (plrSplt && (gameSte[0] != 7 || gameSte[1] != 7)))) {
                // Dealer's Turn
                cout << "The dealer's second card is a(n)" << appHand(delHand, delHand[3]) << ".\n";
                popBkHnd(delHand);
                // Dealer stands on soft 17
                while (delHand[0] < 17)
                    cout << "The dealer's draws another card and it is a(n)" << appHand(delHand, drawCrd()) << ".\n";

                if (delHand[0] > 21)
                    gameSte[0] = 8;
                else if (delHand[0] == 21) {
                    // Updates gameSte variable based on if the player has a blackjack or not
                    gameSte[0] = gameSte[0] == 2 ? 1 : 3;
                    gameSte[1] = gameSte[1] == 2 ? 1 : 3;
                }
            }
        }

        cout << "Player Hand 1: " << outHndT(plrHnd1[0], plrHnd1[1]) << (plrHnd2[0] != 0 ? ", Player Hand 2: " + outHndT(plrHnd2[0], plrHnd2[1]) : "") << ", Dealer Hand: " <<
                static_cast<int>(delHand[0]) << '\n';

        // Game payout/ending
        if (gameSte[0] == 8) {
            cout << "Dealer has gone bust, you win 1x your wager" << (plrSplt ? " for both hands" : "") << "!.\n";
            plrChps += plrWger[0] * 2 + plrWger[1] * 2;
            plrStat[0]++;
        } else if (gameSte[0] == 5) {
            cout << "You have chose to surrender your hand, you receive half your original bet back.\n";
            plrChps += static_cast<unsigned short>(floor(plrWger[0] / 2));
            plrStat[1]++;
        } else {
            if (gameSte[0] == 1) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand and the dealer's hand are both blackjack's." << (plrSplt ? " Your first hand is a push"
                                                                                                                           : " Game ends in a push") << ".\n";
                plrChps += plrWger[0];
            } else if (gameSte[0] == 2) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand is a blackjack!" << (plrSplt ? " You win 1.5x your wager for your first hand" : " You win 1.5x your wager") <<
                        "!\n";
                plrChps += plrWger[0] + static_cast<unsigned short>(ceil(plrWger[0] * 1.5f));
                plrStat[0]++;
            } else if (gameSte[0] == 3) {
                cout << "The dealer's hand is a blackjack and your" << (plrSplt ? " first" : "") << " hand is not." << (plrSplt ? " You lose your first hand" : " You lose") <<
                        ".\n";
                plrStat[1]++;
            } else if (gameSte[0] == 7) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand has gone bust." << (plrSplt ? " You lose your first hand" : " You lose") << ".\n";
                plrStat[1]++;
            } else {
                if ((plrHnd1[0] > delHand[0] && plrHnd1[0] <= 21) || plrHnd1[1] > delHand[0]) {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is larger than the dealer's hand." << (plrSplt ? " You win 1x your wager for your first hand"
                                                                                                                     : " You win 1x your wager") << "!\n";
                    plrChps += plrWger[0] * 2;
                    plrStat[0]++;
                } else if (plrHnd1[0] == delHand[0] || plrHnd1[1] == delHand[0]) {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is equal to the dealer's hand." << (plrSplt ? " Your first hand is a push" : " Game ends in a push") <<
                            ".\n";
                    plrChps += plrWger[0];
                } else {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is smaller than the dealer's hand." << (plrSplt ? " You lose your first hand" : " You lose") << ".\n";
                    plrStat[1]++;
                }
            }

            if (plrSplt) {
                if (gameSte[1] == 1) {
                    cout << "Your second hand and the dealer's hand are both blackjack's. Your second hand ends in a push.\n";
                    plrChps += plrWger[1];
                } else if (gameSte[1] == 2) {
                    cout << "Your second hand is a blackjack! You win 1.5x your wager for your second hand!\n";
                    plrChps += plrWger[1] + static_cast<unsigned short>(ceil(plrWger[1] * 1.5f));
                    plrStat[0]++;
                } else if (gameSte[1] == 3) {
                    cout << "The dealer's hand is a blackjack and your second hand is not. You lose your second hand.\n";
                    plrStat[1]++;
                } else if (gameSte[1] == 7) {
                    cout << "Your second hand has gone bust. You lose your second hand.\n";
                    plrStat[1]++;
                } else {
                    if ((plrHnd2[0] > delHand[0] && plrHnd2[0] <= 21) || plrHnd2[1] > delHand[0]) {
                        cout << "Your second hand is larger than the dealer's hand. You are paid 1x your wager for your second hand!\n";
                        plrChps += plrWger[1] * 2;
                        plrStat[0]++;
                    } else if (plrHnd2[0] == delHand[0] || plrHnd2[1] == delHand[0]) {
                        cout << "Your second hand is equal to the dealer's hand. Your second hand is a push.\n";
                        plrChps += plrWger[1];
                    } else {
                        cout << "Your second hand is smaller than the dealer's hand. You lose your second hand.\n";
                        plrStat[1]++;
                    }
                }
            }
        }
        cout << "Player Statistics:\n* Wins: " << plrStat[0] << "\n* Losses: " << plrStat[1] << "\n* Cash: " << plrCash << "\n* Chips: " << plrChps << "\n";

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
                        cout << "How much money would you like to spend to buy chips (Whole $ only) [$5 to $" << fmtNum(min(plrCash, 65'000)) << "]: ";
                        cin >> plrInpt;
                        plrInpt = floor(plrInpt);

                        // Verify purchased chip amount is a valid amount and that the player has enough cash
                        while (!inRange(plrInpt, 5.0f, min(static_cast<float>(plrCash), 65'000.0f))) {
                            cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $" << fmtNum(min(plrCash, 65'000)) << "]: ";
                            cin >> plrInpt;
                            plrInpt = floor(plrInpt);
                        }
                        plrChps += static_cast<unsigned short>(floor(plrInpt));
                        plrCash -= static_cast<unsigned short>(floor(plrInpt));
                    }
                }

                // Reset Variables
                plrSplt = false;
                plrDbDn = false;
                gameSte[0] = 0;
                gameSte[1] = 0;
                plrWger[0] = 0;
                plrWger[1] = 0;
                plrHnd1 = vector<char>{0, 0};
                plrHnd2 = vector<char>{0, 0};
                delHand = vector<char>{0, 0};
                cout << '\n';
            }
        }
    } while (plrChce != 69);

    // Save to Game File
    plrCash += plrChps;
    sveFile << "ValidSaveFile" << '\n';
    sveFile << plrCash << '\n';
    sveFile << plrStat[0] << '\n';
    sveFile << plrStat[1] << '\n';
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

string fmtNum(const int &number) {
    string strNum{to_string(abs(number))};
    int numLen{static_cast<int>(strNum.length())};
    string output{number < 0 ? "-" : "" + strNum.substr(0, numLen % 3)};
    for (int i{0}; i < numLen / 3; i++) {
        if (i == 0) {
            if (numLen % 3 != 0)
                output += ",";
        } else
            output += ",";
        output += strNum.substr(i * 3 + numLen % 3, 3);
    }
    return output;
}

void genShoe(char shoe[]) {
    char temp;

    for (int i{0}; i < 8; i++) {
        for (int j{0}; j < 52; j++)
            shoe[(i * 52) + j] = j + 1;
    }
    // Iterate over deck 128 times and randomize cards every iteration
    for (int i{0}; i < 128; i++) {
        for (int j{0}; j < 415; j++) {
            if (rand() % 2 == 0) {
                temp = shoe[j];
                shoe[j] = shoe[j + 1];
                shoe[j + 1] = temp;
            }
        }
    }
}

char drawCrd() {
    static unsigned short deckIdx{0};
    static char shoe[416];
    if (deckIdx >= 416)
        deckIdx = 0;
    if (deckIdx == 0)
        genShoe(shoe);
    return shoe[deckIdx++];
}

string appHand(vector<char> &hand, const char &card) {
    string crdOut{};
    hand.push_back(card);
    // If a King Card
    if (hand[hand.size() - 1] % 13 == 0) {
        hand[0] += 10;
        hand[1] += 10;
        switch (hand[hand.size() - 1] / 13) {
            case 1:
                return "King of Spades";
            case 2:
                return "King of Hearts";
            case 3:
                return "King of Diamonds";
            case 4:
                return "King of Clubs";
            default:
                exit(1);
        }
    }
    // All Other Cards
    switch (hand[hand.size() - 1] % 13) {
        case 1:
            if (hand[0] < 11) {
                hand[0] += 11;
                hand[1] += 1;
            } else {
                hand[0] += 1;
                hand[1] += 1;
            }
            crdOut += "Ace";
            break;
        case 11:
            hand[0] += 10;
            hand[1] += 10;
            crdOut += "Jack";
            break;
        case 12:
            hand[0] += 10;
            hand[1] += 10;
            crdOut += "Queen";
            break;
        default:
            hand[0] += hand[hand.size() - 1] % 13;
            hand[1] += hand[hand.size() - 1] % 13;
            crdOut += to_string(hand[hand.size() - 1] % 13);
    }
    switch (hand[hand.size() - 1] / 13) {
        case 0:
            crdOut += " of Spades";
            break;
        case 1:
            crdOut += " of Hearts";
            break;
        case 2:
            crdOut += " of Diamonds";
            break;
        case 3:
            crdOut += " of Clubs";
            break;
        default:
            exit(1);
    }
    return crdOut;
}

char popBkHnd(vector<char> &hand) {
    char card{hand[hand.size() - 1]};

    hand.pop_back();
    // If a King Card
    if (card % 13 == 0) {
        hand[0] -= 10;
        hand[1] -= 10;
    } else {
        // All Other Cards
        switch (card % 13) {
            case 1:
                if (hand[hand.size() - 1] % 13 == 1 && card % 13 == 1) {
                    hand[0] -= 1;
                    hand[1] -= 1;
                } else {
                    hand[0] -= 11;
                    hand[1] -= 1;
                }
                break;
            case 11:
            case 12:
                hand[0] -= 10;
                hand[1] -= 10;
                break;
            default:
                hand[0] -= card % 13;
                hand[1] -= card % 13;
        }
    }

    return card;
}

string outHndT(const char &total1, const char &total2) {
    if (total1 == total2)
        return to_string(static_cast<int>(total1));
    if (total1 <= 21)
        return to_string(static_cast<int>(total1)) + '/' + to_string(static_cast<int>(total2));
    return to_string(static_cast<int>(total2));
}
