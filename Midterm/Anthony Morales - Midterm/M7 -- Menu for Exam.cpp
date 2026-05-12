/*
* File:   main.cpp
 * Author: Anthony Morales
 * Created on April 30, 12:19 PM
 * Purpose:  M7 -- Menu for Exam. 10pts
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <vector>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();

int getN();

void def(int);

void problem1();

void problem2();

void problem3();

void problem4();

void problem5();

void problem6();

// Problem 1
unsigned short to1s(unsigned short num);

// Problem 3
string toNumrl(unsigned short num);

// Problem 4
float clcPckA(unsigned short hours);

float clcPckB(unsigned short hours);

float clcPckC();

//Execution Begins Here!
int main(int argc, char **argv) {
    //Set a Random number seed here.

    //Declare Main variables here.
    int inN;

    //Loop on each problem
    do {
        Menu();
        inN = getN();
        switch (inN) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            default: def(inN);
        }
    } while (inN < 7);

    //Exit Stage Right Here!
    return 0;
}

void Menu() {
    cout << endl;
    cout << "Type 1 to execute Problem 1" << endl;
    cout << "Type 2 to execute Problem 2" << endl;
    cout << "Type 3 to execute Problem 3" << endl;
    cout << "Type 4 to execute Problem 4" << endl;
    cout << "Type 5 to execute Problem 5" << endl;
    cout << "Type 6 to execute Problem 6" << endl;
    cout << "Type anything else to exit." << endl << endl;
}

int getN() {
    int inN;
    cin >> inN;
    return inN;
}

void def(int inN) {
    cout << endl << "Typing " << inN << " exits the program." << endl;
}

void problem1() {
    // Declare all Variables Here
    unsigned short x;
    char shape; // f-> forward b->backward x->cross
    bool isEven{};

    // Input or initialize values Here
    cout << "Create a numbered shape that can be sized.\n";
    cout << "Input an integer number [1,50] and a character [x,b,f].\n";
    cin >> x >> shape;
    shape = static_cast<char>(toupper(shape));
    while (x < 1 || x > 50) {
        cout << "Number must be between 1 and 50. Enter a new number between 1 and 50: ";
        cin >> x;
    }
    while (shape != 66 && shape != 70 && shape != 88) {
        cout << "Shape option must either be [x, b, f]. Enter a new valid shape option: ";
        cin >> shape;
        shape = static_cast<char>(toupper(shape));
    }

    isEven = x % 2 == 0;

    // Draw the shape
    // The string constructor I use here is something I have used in previous assignments. I use it here so I don't have
    // to use a bunch of for loops and if statements; it makes for much cleaner code
    if (shape == 66) {
        if (isEven) {
            for (int i{0}, num{x}; i < x; i++, num--)
                cout << string(i, ' ') << to1s(i + 1) << string(num - 1, ' ') << '\n';
        } else {
            for (int i{0}, num{x}; i < x; i++, num--)
                cout << string(i, ' ') << to1s(num) << string(num - 1, ' ') << '\n';
        }
    } else if (shape == 70) {
        if (isEven) {
            for (int i{0}, num{x}; i < x; i++, num--)
                cout << string(num - 1, ' ') << to1s(num) << string(i, ' ') << '\n';
        } else {
            for (int i{0}, num{x}; i < x; i++, num--)
                cout << string(num - 1, ' ') << to1s(i + 1) << string(i, ' ') << '\n';
        }
    } else if (shape == 88) {
        if (isEven) {
            for (int i{0}, j{x}; j > x / 2; i++, j--)
                cout << string(i, ' ') << to1s(i + 1) << string(j - 2 - i, ' ') << to1s(j) << string(i, ' ') << '\n';
            for (int i{x / 2 + 1}, j{x / 2 - 1}; j >= 0; i++, j--)
                cout << string(j, ' ') << to1s(j + 1) << string(i - 2 - j, ' ') << to1s(i) << string(j, ' ') << '\n';
        } else {
            unsigned short half{static_cast<unsigned short>((x - 1) / 2)};
            for (int i{x}, j{0}; i > half + 1; i--, j++)
                cout << string(j, ' ') << to1s(i) << string(i - 2 - j, ' ') << to1s(j + 1) << string(j, ' ') << '\n';
            cout << string(half, ' ') << to1s(half + 1) << string(half, ' ') << '\n';
            for (int i{half - 1}, j{half + 2}; i >= 0; i--, j++)
                cout << string(i, ' ') << to1s(j) << string(j - 2 - i, ' ') << to1s(i + 1) << string(i, ' ') << '\n';
        }
    }
}

void problem2() {
    // Declare all Variables Here
    string number{};

    // Input or initialize values Here
    cout << "Create a histogram chart." << endl;
    cout << "Input 4 digits as characters." << endl;
    cin >> number;

    // The empty() function is something I have used numerous times in the past
    while (number.empty() || number.size() > 4) {
        cout << "You must input exactly four numbers. Enter a new four number string: ";
        cin >> number;
    }

    // Histogram Here
    // I know that we only need to use concepts from the first five chapters to complete the problems, but I used string
    // indexing here as it made everything so much simpler to write (Mark's Law)
    for (int i{3}; i >= 0; i--)
        cout << number[i] << " " << (number[i] >= 48 && number[i] <= 57 ? string(number[i] - 48, '*') : "?") << '\n';
}

void problem3() {
    //Declare all Variables Here
    unsigned short number;
    unsigned short p1000s{};
    unsigned short p100s{};

    //Input or initialize values Here
    cout << "Input an integer [1-3000] convert to an English Check value." << endl;
    cin >> number;

    while (number < 1 || number > 3000) {
        cout << "Inputted number must be between 1 and 3000. Enter a new number between 1 and 3000: ";
        cin >> number;
    }

    //Calculate the 1000's, 100's, 10's and 1's
    p1000s = static_cast<unsigned short>(number - number % 1000);
    number -= p1000s;
    p100s = static_cast<unsigned short>(number - number % 100);
    number -= p100s;

    //Output the check value
    if (p1000s != 0)
        cout << toNumrl(p1000s / 1000) << " Thousand ";
    if (p100s != 0)
        cout << toNumrl(p100s / 100) << " Hundred ";
    cout << toNumrl(number);
    cout << " and no/100's Dollars" << endl;
}

void problem4() {
    // Declare all Variables Here
    char package;
    unsigned short hours;
    float fnlPrce{0.0f};
    float pack1{0.0f};
    float pack2{0.0f};
    float chpPack{0.0f};

    // Input or initialize values Here
    cout << "ISP charges for service delivered." << endl;
    cout << "Input package A,B,C then hours used for the month" << endl;
    cin >> package >> hours;
    package = static_cast<char>(toupper(package));
    while (package < 65 || package > 67) {
        cout << "Invalid package. Package type must either be A, B, or C. Enter a valid package type: ";
        cin >> package;
        package = static_cast<char>(toupper(package));
    }
    while (hours < 0) {
        cout << "Hours used must be greater than 0. Enter a new amount greater than 0: ";
        cin >> hours;
    }
    // Basic Charges
    switch (package) {
        case 'A':
            fnlPrce = clcPckA(hours);
            pack1 = clcPckB(hours);
            pack2 = clcPckC();
            if (pack1 <= fnlPrce || pack2 <= fnlPrce) {
                if (pack1 < pack2) {
                    chpPack = pack1;
                    package = 'B';
                } else {
                    chpPack = pack2;
                    package = 'C';
                }
            } else {
                chpPack = fnlPrce;
                package = 'A';
            }
            break;
        case 'B':
            fnlPrce = clcPckB(hours);
            pack1 = clcPckA(hours);
            pack2 = clcPckC();
            if (pack1 <= fnlPrce || pack2 <= fnlPrce) {
                if (pack1 < pack2) {
                    chpPack = pack1;
                    package = 'A';
                } else {
                    chpPack = pack2;
                    package = 'C';
                }
            } else {
                chpPack = fnlPrce;
                package = 'B';
            }
            break;
        case 'C':
            fnlPrce = clcPckC();
            pack1 = clcPckA(hours);
            pack2 = clcPckB(hours);
            if (pack1 <= fnlPrce || pack2 <= fnlPrce) {
                if (pack1 < pack2) {
                    chpPack = pack1;
                    package = 'A';
                } else {
                    chpPack = pack2;
                    package = 'B';
                }
            } else {
                chpPack = fnlPrce;
                package = 'C';
            }
            break;
    }

    // Output the Charge
    cout << fixed << setprecision(2);
    cout << '$' << fnlPrce << ' ';

    // Output the cheapest package and the savings
    cout << package << " $" << fnlPrce - chpPack << '\n';
}

void problem5() {
    // Declare all Variables Here
    float payRate;
    unsigned short hrsWrkd;
    float totlPay{0.0f};

    // Input or initialize values Here
    cout << "Paycheck Calculation." << endl;
    cout << "Input payRate in $'s/hour and hours worked" << endl;
    cin >> payRate >> hrsWrkd;
    while (hrsWrkd < 0) {
        cout << "Hours worked cannot be less than 0. Enter a new number greater than 0: ";
        cin >> hrsWrkd;
    }
    while (payRate < 0.0f) {
        cout << "Pay rate cannot be less than 0. Enter a new number greater than 0: ";
        cin >> payRate;
    }

    // Calculate Paycheck
    totlPay += hrsWrkd <= 20 ? hrsWrkd * payRate : 20 * payRate;
    if (hrsWrkd > 20)
        totlPay += hrsWrkd > 20 && hrsWrkd <= 40 ? (hrsWrkd - 20) * (payRate * 1.5f) : 20 * (payRate * 1.5f);
    totlPay += hrsWrkd > 40 ? (hrsWrkd - 40) * (payRate * 2) : 0.0f;

    // Output the check
    cout << fixed << setprecision(2);
    cout << '$' << totlPay << '\n';
}

void problem6() {
    // Declare all Variables Here
    float x, fx;
    int nterms;
    float buf;


    // Input or initialize values Here
    cout << "Calculate a series f(x)=x-x^3/3!+x^5/5!-x^7/7!+......." << endl;
    cout << "Input x and the number of terms, output f(x)" << endl;
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
    cout << fixed << setprecision(6) << fx << endl;
}

// Problem 1
unsigned short to1s(unsigned short num) {
    return num >= 10 ? num % 10 : num;
}

// Problem 3
string toNumrl(unsigned short num) {
    // I have used a vector before so I know how to use one. I also know that we only need concepts from the first five
    // chapters to complete the problems, but I also didn't want to write a switch statement with 27 cases. (Mark's Law)
    vector<string> numrlEN{
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
        "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty", "Thirty", "Forty",
        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
    };
    if (num > 0 && num < 20)
        return numrlEN[num];
    return num % 10 == 0 ? numrlEN[num / 10 + 18] : numrlEN[num / 10 + 18] + " " + numrlEN[num % 10];
}

// Problem 4
float clcPckA(unsigned short hours) {
    float fnlPrce{16.99f};

    if (hours > 10)
        fnlPrce += hours > 10 && hours <= 20 ? (hours - 10) * 0.95f : 10 * 0.95f;
    fnlPrce += hours > 20 ? (hours - 20) * 0.85f : 0.0f;
    return fnlPrce;
}

float clcPckB(unsigned short hours) {
    float fnlPrce{26.99f};

    if (hours > 20)
        fnlPrce += hours > 20 && hours <= 30 ? (hours - 20) * 0.74f : 10 * 0.74f;
    fnlPrce += hours > 30 ? (hours - 30) * 0.64f : 0.0f;
    return fnlPrce;
}

float clcPckC() {
    return 36.99f;
}
