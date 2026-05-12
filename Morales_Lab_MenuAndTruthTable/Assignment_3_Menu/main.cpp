/*
 * File:   main.cpp
 * Author: mlehr - Modified by: Anthony Morales
 * Created on July 6th, 2023, 10:16 AM
 * Modified on March 24, 2026, 5:36PM
 * Purpose:  Lab - Menu and Truth Table (Menu)
 */

// System Libraries
#include <iostream> // Input Output Library
#include <iomanip>  // Output Number Formatting Library
#include <cctype>   // Character Handling Library
#include <string>   // String Library
using namespace std;

// User Libraries

// Global Constants - Math/Science/Conversions only

// Function Prototypes

// Execution Begins Here
int main(int argc, char **argv)
{
    // Declare Variables
    int option,  // Option to choose from menu
        nOpshun; // Number of options

    // Variables for Problem 1
    string name1;
    string name2;
    string name3;

    // Variables for Problem 2
    int bksPurc;
    int ptsEarn;

    // Variables for Problem 3
    const float mthFee = 10.00f;
    const float lwBalF = 15.00f;
    float fee1;
    float fee2;
    float fee3;
    const float fee4 = 0.04f;

    float usrBal;
    int chkCt;
    float chkFeeT;

    // Variables for Problem 4
    int time1;
    int time2;
    int time3;

    // Variables for Problem 5
    const int access1 = 10;
    const int access2 = 20;
    const int access3 = 744;
    const float addUse1 = 2.00f;
    const float addUse2 = 1.00f;

    char usrPack;
    int accTime;
    float usrBill;

    // Variables for Problem 6
    char p1Chce;
    char p2Chce;

    // Variables for Problem 7
    int usrNum;
    string output;

    int tally;
    int buffer;

    // Variables for Problem 8
    string signOne;
    string signTwo;

    string fire1 = "Aries";
    string fire2 = "Leo";
    string fire3 = "Sagittarius";

    string earth1 = "Taurus";
    string earth2 = "Virgo";
    string earth3 = "Capricorn";

    string air1 = "Gemini";
    string air2 = "Libra";
    string air3 = "Aquarius";

    string water1 = "Cancer";
    string water2 = "Scorpio";
    string water3 = "Pisces";

    // The Process -> Map Inputs to Outputs
    nOpshun = 8;
    do
    {
        // Display user choice
        cout << "Choose from the options displayed" << endl;
        cout << "1 -> Question 1" << endl;
        cout << "2 -> Question 2" << endl;
        cout << "3 -> Question 3" << endl;
        cout << "4 -> Question 4" << endl;
        cout << "5 -> Question 5" << endl;
        cout << "6 -> Question 6" << endl;
        cout << "7 -> Question 7" << endl;
        cout << "8 -> Question 8" << endl;
        cout << "9 -> Exit Program" << endl;
        cin >> option; // Read in the option
        // Use a switch case to implement
        switch (option)
        {
        case 1:
            // Initialize Variables
            cout << "Sorting Names\n"
                 << "Input 3 names\n";
            cin >> name1 >> name2 >> name3;

            // Map/Process the Inputs -> Outputs

            // Display Inputs/Outputs
            if (name1 < name2)
            {
                if (name1 < name3)
                {
                    cout << name1 << '\n';
                    if (name2 < name3)
                        cout << name2 << '\n'
                             << name3 << '\n';
                    else
                        cout << name3 << '\n'
                             << name2 << '\n';
                }
                else
                    cout << name3 << '\n'
                         << name1 << '\n'
                         << name2 << '\n';
            }
            else
            {
                if (name1 < name3)
                    cout << name2 << '\n'
                         << name1 << '\n'
                         << name3 << '\n';
                else
                {
                    if (name2 < name3)
                        cout << name2 << '\n'
                             << name3 << '\n';
                    else
                        cout << name3 << '\n'
                             << name2 << '\n';
                    cout << name1 << '\n';
                }
            }
            break;
        case 2:
            // Initialize Variables
            cout << "Book Worm Points\n"
                 << "Input the number of books purchased this month.\n";
            cin >> bksPurc;

            // Map/Process the Inputs -> Outputs
            if (bksPurc == 0)
                ptsEarn = 0;
            else if (bksPurc == 1)
                ptsEarn = 5;
            else if (bksPurc == 2)
                ptsEarn = 15;
            else if (bksPurc == 3)
                ptsEarn = 30;
            else if (bksPurc >= 4)
                ptsEarn = 60;
            else
            {
                // Input Validation
                cout << "Invalid Entry.\n";
            }

            // Display Inputs/Outputs
            cout << "Books purchased =" << setw(3) << bksPurc << '\n';
            cout << "Points earned   =" << setw(3) << ptsEarn << '\n';
            break;
        case 3:
            fee1 = 0.10f;
            fee2 = 0.08f;
            fee3 = 0.06f;
            // Initialize Variables
            cout << "Monthly Bank Fees\n"
                 << "Input Current Bank Balance and Number of Checks\n";
            cin >> usrBal >> chkCt;

            // Input Validation - Negative Account Balance
            while (usrBal <= 0.00f)
            {
                cout << "No Balance Available.\n";
            }
            // Input Validation - Negative Check Count
            while (chkCt < 0)
            {
                cout << "Invalid Check Count. Check count must be positive.\n"
                     << "Enter Valid Number of Checks: ";
                cin >> chkCt;
            }

            // Map/Process the Inputs -> Outputs
            chkFeeT = (chkCt < 20) ? (fee1 * chkCt) : (chkCt >= 20 && chkCt < 40) ? (fee2 * chkCt)
                                                  : (chkCt >= 40 && chkCt < 60)   ? (fee3 * chkCt)
                                                                                  : (fee4 * chkCt);

            // Display Inputs/Outputs
            cout << fixed << setprecision(2);
            cout << "Balance     $" << setw(9) << usrBal << '\n';
            cout << "Check Fee   $" << setw(9) << chkFeeT << '\n';
            cout << "Monthly Fee $" << setw(9) << mthFee << '\n';
            cout << "Low Balance $" << setw(9) << (usrBal < 400.00f ? lwBalF : 0.00f) << '\n';
            cout << "New Balance $" << setw(9) << usrBal - chkFeeT - mthFee - (usrBal < 400.00f ? lwBalF : 0.00f) << '\n';
            break;
        case 4:
            // Initialize Variables
            cout << "Race Ranking Program\n"
                 << "Input 3 Runners\n"
                 << "Their names, then their times\n";
            cin >> name1 >> time1 >> name2 >> time2 >> name3 >> time3;

            // Input Validation - Positive Race Time
            while (time1 < 0)
            {
                cout << "Time for runner one cannot be negative. Enter a positive race time: ";
                cin >> time1;
            }
            while (time2 < 0)
            {
                cout << "Time for runner two cannot be negative. Enter a positive race time: ";
                cin >> time2;
            }
            while (time3 < 0)
            {
                cout << "Time for runner three cannot be negative. Enter a positive race time: ";
                cin >> time3;
            }

            // Map/Process the Inputs -> Outputs

            // Display Inputs/Outputs
            if (time1 < time2)
            {
                if (time1 < time3)
                {
                    cout << name1 << '\t' << setw(3) << time1 << '\n';
                    if (time2 < time3)
                        cout << name2 << '\t' << setw(3) << time2 << '\n'
                             << name3 << '\t' << setw(3) << '\n';
                    else
                        cout << name3 << '\t' << setw(3) << time3 << '\n'
                             << name2 << '\t' << setw(3) << time2 << '\n';
                }
                else
                    cout << name3 << '\t' << setw(3) << time3 << '\n'
                         << name1 << '\t' << setw(3) << time1 << '\n'
                         << name2 << '\t' << setw(3) << time2 << '\n';
            }
            else
            {
                if (time1 < time3)
                    cout << name2 << '\t' << setw(3) << time2 << '\n'
                         << name1 << '\t' << setw(3) << time1 << '\n'
                         << name3 << '\t' << setw(3) << time3 << '\n';
                else
                {
                    if (time2 < time3)
                        cout << name2 << '\t' << setw(3) << time2 << '\n'
                             << name3 << '\t' << setw(3) << time3 << '\n';
                    else
                        cout << name3 << '\t' << setw(3) << time3 << '\n'
                             << name2 << '\t' << setw(3) << time2 << '\n';
                    cout << name1 << '\t' << setw(3) << time1 << '\n';
                }
            }
            break;
        case 5:
            fee1 = 9.95f;
            fee2 = 14.95f;
            fee3 = 19.95f;

            // Initialize Variables
            cout << "ISP Bill\n"
                 << "Input Package and Hours\n";
            cin >> usrPack >> accTime;

            // Input Validation - Valid Package
            while (usrPack < 65 || usrPack > 67)
            {
                cout << "Invalid package. Package options are A, B or C. Enter a valid package: ";
                cin >> usrPack;
            }
            // Input Validation - Hours Used in a Month
            while (accTime < 0 || accTime > 744)
            {
                cout << "Invalid access time amount. Enter new access time: ";
                cin >> accTime;
            }

            // Map/Process the Inputs -> Outputs
            if (usrPack == 'A')
                usrBill = (accTime > access1 ? (accTime - access1) * addUse1 : 0.00f) + fee1;
            else if (usrPack == 'B')
                usrBill = (accTime > access2 ? (accTime - access2) * addUse2 : 0.00f) + fee2;
            else if (usrPack == 'C')
                usrBill = fee3;

            // Display Inputs/Outputs
            cout << fixed << setprecision(2);
            cout << "Bill = $" << setw(6) << usrBill << '\n';
            break;
        case 6:
            // Initialize Variables
            cout << "Rock Paper Scissors Game\n"
                 << "Input Player 1 and Player 2 Choices";
            cin >> p1Chce >> p2Chce;

            // I know that we haven't learned about the cctype library in class, but since I have experience coding with C++, this is one of the functions I know how to use
            // I use it here so that the program can take lowercase and uppercase letters.
            p1Chce = static_cast<char>(toupper(static_cast<unsigned char>(p1Chce)));
            p2Chce = static_cast<char>(toupper(static_cast<unsigned char>(p2Chce)));

            // Input Validation - Valid Option
            while (p1Chce != 80 && p1Chce != 82 && p1Chce != 83)
            {
                cout << "Player one has entered an invalid option. Valid options are P, R, or S. Enter a valid option: ";
                cin >> p1Chce;
                p1Chce = static_cast<char>(toupper(static_cast<unsigned char>(p1Chce)));
            }
            while (p2Chce != 80 && p2Chce != 82 && p2Chce != 83)
            {
                cout << "Player two has entered an invalid option. Valid options are P, R, or S. Enter a valid option: ";
                cin >> p2Chce;
                p2Chce = static_cast<char>(toupper(static_cast<unsigned char>(p2Chce)));
            }

            // Map/Process the Inputs -> Outputs

            // Display Inputs/Outputs
            if ((p1Chce == 'P' && p2Chce == 'R') || (p2Chce == 'P' && p1Chce == 'R'))
                cout << "\nPaper covers rock.\n";
            else if ((p1Chce == 'R' && p2Chce == 'S') || (p2Chce == 'R' && p1Chce == 'S'))
                cout << "\nRock breaks scissors.\n";
            else if ((p1Chce == 'S' && p2Chce == 'P') || (p2Chce == 'S' && p1Chce == 'P'))
                cout << "\nScissors cuts paper.\n";
            else
                cout << "Nobody Wins.\n";
            break;
        case 7:
            // Initialize Variables
            cout << "Arabic to Roman numeral conversion.\n"
                 << "Input the integer to convert.\n";
            cin >> usrNum;

            // Map/Process the Inputs -> Outputs

            // Display Inputs/Outputs
            if (usrNum >= 1000 && usrNum <= 3000)
            {
                buffer = usrNum;

                for (int j = 0; j < (buffer / 1000); j++)
                    output += 'M';
                buffer %= 1000;
                for (int j = 0; j < (buffer / 500); j++)
                    output += 'D';
                buffer %= 500;
                if (buffer / 100 < 4)
                {
                    for (int j = 0; j < (buffer / 100); j++)
                        output += 'C';
                }
                else
                    output += "CD";
                buffer %= 100;
                for (int j = 0; j < (buffer / 50); j++)
                    output += 'L';
                buffer %= 50;
                if (buffer / 10 < 4)
                {
                    for (int j = 0; j < (buffer / 10); j++)
                        output += 'X';
                }
                else
                    output += "XL";
                buffer %= 10;
                for (int j = 0; j < (buffer / 5); j++)
                    output += 'V';
                buffer %= 5;
                if (buffer < 4)
                {
                    for (int j = 0; j < buffer; j++)
                        output += 'I';
                }
                else
                    output += "IV";

                cout << usrNum << " is equal to " << output << '\n';
            }
            else
                cout << usrNum << " is Out of Range!\n";
            break;
        case 8:
            // Initialize Variables
            cout << "Horoscope Program which examines compatible signs.\n"
                 << "Input 2 signs.\n";
            cin >> signOne >> signTwo;

            // Map/Process the Inputs -> Outputs

            // Display Inputs/Outputs
            if (signOne == fire1 || signOne == fire2 || signOne == fire3)
            {
                if (signTwo == fire1 || signTwo == fire2 || signTwo == fire3)
                    cout << signOne << " and " << signTwo << " are compatible Fire signs.\n";
                else
                    cout << signOne << " and " << signTwo << " are not compatible signs.\n";
            }
            else if (signOne == earth1 || signOne == earth2 || signOne == earth3)
            {
                if (signTwo == earth1 || signTwo == earth2 || signTwo == earth3)
                    cout << signOne << " and " << signTwo << " are compatible Earth signs.\n";
                else
                    cout << signOne << " and " << signTwo << " are not compatible signs.\n";
            }
            else if (signOne == air1 || signOne == air2 || signOne == air3)
            {
                if (signTwo == air1 || signTwo == air2 || signTwo == air3)
                    cout << signOne << " and " << signTwo << " are compatible Air signs.\n";
                else
                    cout << signOne << " and " << signTwo << " are not compatible signs.\n";
            }
            else
            {
                if (signTwo == water1 || signTwo == water2 || signTwo == water3)
                    cout << signOne << " and " << signTwo << " are compatible Water signs.\n";
                else
                    cout << signOne << " and " << signTwo << " are not compatible signs.\n";
            }
            break;
        default:
            cout << endl
                 << "Exit Program" << endl
                 << endl;
        }
    } while (option <= nOpshun);

    // Exit the Program
    return 0;
}
