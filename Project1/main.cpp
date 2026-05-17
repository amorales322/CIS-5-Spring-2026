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

using namespace std;

// User Libraries

// Global Constants not Variables
// Science, Math, Conversions, Dimensions

// Function Prototypes

// Execution begins here at main
int main(int argc, char **argv) {
    // Set random number seed
    srand(time(0));

    /*
     * Declare Variables
     */
    // Game Variables
    char plrChce{};
    float plrInpt{};
    char curDrwC{};
    bool plrSplt{false};
    bool plrDbDn{false};

    // 1s Place: Player Hand 1, 10s Place: Player Hand 2
    // States: 0: Default (continue), 1: Push (Player/Dealer Blackjack), 2: Player Blackjack, 3: Dealer Blackjack
    // 4: Double Down, 5: Surrender, 6: Stand, 7: Player Bust, 8: Dealer Bust
    char gameSte{00};

    // Player Variables/Statistics
    unsigned int plrCash{10000};
    unsigned short plrChps{};

    unsigned short plrBet1{};
    unsigned short plrBet2{};

    unsigned short plrWins{0};
    unsigned short plrLoss{0};

    // Player Hands
    char plrHnd1{};
    char plrHnd2{};

    // Dealer Hand/Cards
    char delCrd1{};
    char delCrd2{};

    /*
     * Initialize Variables
     */
    // Purchase Chips
    cout << "How much money would you like to spend to buy chips (Whole $ only) [$5 to $" << (plrCash >= 65'000
            ? "65,000]: "
            : plrCash >= 1000
                  ? to_string(plrCash / 1000) + "," + string(3 - to_string(plrCash % 1000).length(), '0') +
                    to_string(plrCash % 1000) + "]: "
                  : to_string(plrCash) + "]: ");
    cin >> plrInpt;
    plrInpt = std::floor(plrInpt);

    // Verify purchased chip amount is a valid amount and that the player has enough cash
    while (plrInpt > (static_cast<float>(plrCash) <= 65'000.0f ? static_cast<float>(plrCash) : 65'000.0f) || plrInpt <
           5.0f) {
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
        plrInpt = std::floor(plrInpt);
    }
    plrChps = static_cast<unsigned short>(floor(plrInpt));
    plrCash -= plrChps;

    // Game Loop
    do {
        // Get Player Wager
        cout << "Enter wager amount (Whole $ only) [$5 to $" << (plrChps >= 10000
                                                                     ? "10,000]: "
                                                                     : plrChps >= 1000
                                                                           ? to_string(plrChps / 1000) + "," + string(
                                                                                 3 - to_string(plrChps % 1000).length(),
                                                                                 '0') +
                                                                             to_string(plrChps % 1000) + "]: "
                                                                           : to_string(plrChps) + "]: ");
        cin >> plrInpt;
        plrInpt = std::floor(plrInpt);

        // Verify player wager is valid amount and that the player has enough chips
        while (plrInpt > (static_cast<float>(plrChps) <= 10'000.0f ? static_cast<float>(plrChps) : 10'000.0f) || plrInpt
               < 5.0f) {
            cout << "Invalid Amount. Enter new amount (Whole $ only) [$5 to $" << (plrChps >= 10000
                    ? "10,000]: "
                    : plrChps >= 1000
                          ? to_string(plrChps / 1000) + "," + string(
                                3 - to_string(plrChps % 1000).length(),
                                '0') +
                            to_string(plrChps % 1000) + "]: "
                          : to_string(plrChps) + "]: ");
            cin >> plrInpt;
            plrInpt = std::floor(plrInpt);
        }

        plrBet1 = static_cast<unsigned short>(floor(plrInpt));
        plrChps -= plrBet1;

        //
        // Player Card Drawing
        //

        // Draw First Player Card
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

        // Draw Second Player Card
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
                plrSplt = plrHnd1 == curDrwC;
                plrHnd1 += curDrwC;
                break;
            default:
                cout << "Your second card is a(n) " << static_cast<int>(curDrwC) << " card.\n";
                plrSplt = plrHnd1 == curDrwC;
                plrHnd1 += curDrwC;
        }

        //
        // Dealer Draw Cards
        //

        // Draw First Dealer Card
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

        // Draw Second Dealer Card
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
            if (plrSplt && plrChps >= plrBet1) {
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
                    plrBet2 = plrBet1;
                    plrChps -= plrBet2;
                } else {
                    plrSplt = false;
                }
            } else
                plrSplt = false;

            plrDbDn = plrChps >= plrBet1;
            cout << "Enter Option (Player Hand 1: " << static_cast<int>(plrHnd1) << ", Dealer Hand: " << static_cast
                    <int>(delCrd1) << ")\nS: Stand, H: Hit" << (plrDbDn ? ", D: Double Down" : "") << (
                        !plrSplt ? ", X: Surrender" : "") << " -> ";
            cin >> plrChce;
            plrChce = static_cast<char>(toupper(plrChce));
            if (plrSplt && plrDbDn) {
                while (plrChce != 83 && plrChce != 68 && plrChce != 72) {
                    cout << "Invalid Option. Enter New Option (S: Stand, H: Hit, D: Double Down): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            } else if (plrSplt && !plrDbDn) {
                while (plrChce != 83 && plrChce != 72) {
                    cout << "Invalid Option. Enter New Option (S: Stand, H: Hit): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            } else if (!plrSplt && plrDbDn) {
                while (plrChce != 83 && plrChce != 68 && plrChce != 72 && plrChce != 88) {
                    cout << "Invalid Option. Enter New Option (S: Stand, H: Hit, D: Double Down, X: Surrender): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            } else {
                while (plrChce != 83 && plrChce != 88 && plrChce != 72) {
                    cout << "Invalid Option. Enter New Option (S: Stand, H: Hit, X: Surrender): ";
                    cin >> plrChce;
                    plrChce = static_cast<char>(toupper(plrChce));
                }
            }

            switch (plrChce) {
                case 'X':
                    cout << "You have chosen to surrender your hand.\n";
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
                case 'H':
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
                    while (plrChce != 83 && plrChce != 72) {
                        cout << "Invalid Option. Enter New Option (S: Stand, H: Hit): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }

                    switch (plrChce) {
                        case 'S':
                            gameSte = 6;
                            break;
                        case 'H':
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

            if (plrSplt) {
                plrDbDn = plrChps >= plrBet2;

                cout << "Enter Option (Player Hand 2: " << static_cast<int>(plrHnd2) << ", Dealer Hand: " << static_cast
                        <int>(delCrd1) << ")\nS: Stand, H: Hit" << (plrDbDn ? ", D: Double Down" : "") << " -> ";
                cin >> plrChce;
                plrChce = static_cast<char>(toupper(plrChce));
                if (plrDbDn) {
                    while (plrChce != 83 && plrChce != 68 && plrChce != 72) {
                        cout << "Invalid Option. Enter New Option (S: Stand, H: Hit, D: Double Down): ";
                        cin >> plrChce;
                        plrChce = static_cast<char>(toupper(plrChce));
                    }
                } else {
                    while (plrChce != 83 && plrChce != 72) {
                        cout << "Invalid Option. Enter New Option (S: Stand, H: Hit): ";
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
                    case 'H':
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
                            cout << "Invalid Option. Enter New Option (S: Stand, H: Hit): ";
                            cin >> plrChce;
                            plrChce = static_cast<char>(toupper(plrChce));
                        }

                        switch (plrChce) {
                            case 'S':
                                gameSte += 60;
                                break;
                            case 'H':
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

            if (gameSte != 5 && !((!plrSplt && gameSte % 10 == 7) || (
                                      gameSte % 10 == 7 && plrSplt && gameSte / 10 == 7))) {
                // Dealer Move
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
                if (delCrd1 + delCrd2 == 21) {
                    gameSte = (gameSte % 10 == 2 ? gameSte / 10 + 1 : gameSte / 10 + 3);
                    gameSte = (gameSte / 10 == 2 ? gameSte % 10 + 10 : gameSte % 10 + 30);
                }
            }
        }

        cout << "Player Hand 1: " << static_cast<int>(plrHnd1) << (plrHnd2 != 0
                                                                       ? ", Player Hand 2: " + to_string(plrHnd2)
                                                                       : "") << ", Dealer Hand: " << static_cast<int>(
            delCrd1 + delCrd2) << '\n';
        if (gameSte == 8) {
            cout << "Dealer has gone bust, you win one times your wager" << (plrSplt ? " for both hands" : "") <<
                    "!.\n";
            plrChps += plrBet1 * 2 + plrBet2 * 2;
            plrWins++;
        } else if (gameSte == 5) {
            cout << "You have chose to surrender your hand, you receive half your original bet back.\n";
            plrChps += static_cast<unsigned short>(floor(plrBet1 / 2));
            plrLoss++;
        } else {
            if (gameSte % 10 == 1) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand and the dealers hand are both blackjack's." << (
                    plrSplt ? " Your first hand is a push.\n" : "  Game ends in a push.\n");
                plrChps += plrBet1;
            } else if (gameSte % 10 == 2) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand is a blackjack! " << (
                    plrSplt
                        ? " You are paid 1.5 times your wager for your first hand!\n"
                        : " You win 1.5x your wager!\n");
                plrChps += plrBet1 + static_cast<unsigned short>(ceil(plrBet1 * 1.5f));
                plrWins++;
            } else if (gameSte % 10 == 3) {
                cout << "The dealer's hand is a blackjack and your" << (plrSplt ? " first" : "") << " hand is not." <<
                        (plrSplt ? "You lose your first hand.\n" : " You lose.\n");
                plrLoss++;
            } else if (gameSte % 10 == 7) {
                cout << "Your" << (plrSplt ? " first" : "") << " hand has gone bust." << (
                    plrSplt ? "You lose your first hand.\n" : " You Lose.\n");
                plrLoss++;
            } else {
                if (plrHnd1 > delCrd1 + delCrd2) {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is larger than the dealer's hand." << (plrSplt
                            ? " You are paid 1x your wager for your first hand!\n"
                            : " You win 1x your wager!\n");
                    plrChps += plrBet1 * 2;
                    plrWins++;
                } else if (plrHnd1 == delCrd1 + delCrd2) {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is equal to the dealer's hand." << (plrSplt
                            ? " Your first hand is a push.\n"
                            : " Game ends in a push.\n");
                    plrChps += plrBet1;
                } else {
                    cout << "Your" << (plrSplt ? " first" : "") << " hand is smaller than the dealer's hand." << (
                        plrSplt ? " You lose your first hand.\n" : " You lose.\n");
                    plrLoss++;
                }
            }

            if (plrSplt) {
                if (gameSte / 10 == 1) {
                    cout <<
                            "Your second hand and the dealers hand are both blackjack's. Your second hand ends in a push.\n";
                    plrChps += plrBet2;
                } else if (gameSte % 10 == 2) {
                    cout << "Your second hand is a blackjack! You win 1.5x your wager for your second hand!\n";
                    plrChps += plrBet2 + static_cast<unsigned short>(ceil(plrBet2 * 1.5f));
                    plrWins++;
                } else if (gameSte % 10 == 3) {
                    cout <<
                            "The dealer's hand is a blackjack and your second hand is not. You lose your second hand.\n";
                    plrLoss++;
                } else if (gameSte % 10 == 7) {
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
