/*
 * File:   main.cpp
 * Author: mlehr
 * Modifed By: Anthony Morales
 * Created on July 6th, 2023, 10:16 AM
 * Modified on May 6th, 2026, 9:57 AM
 * Purpose:  Homework Assignment 6 - Menu
 */

//System Libraries
#include <iostream>  // I/O Library
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Science/Conversions only
// Problem 1
const int COLS1 = 6;

// Problem 2
const int COLS2 = 6;

//Function Prototypes
void prob1();

// Problem 1 Functions
void fillTb1(int [][COLS1], int);

void prntTb1(const int [][COLS1], int);

void prob2();

// Problem 2 Functions
void fillTb2(int [][COLS2], int);

void prntTb2(const int [][COLS2], int);

void prob3();

// Problem 3 Functions
void init3(int [], int); // Initialize the array
void print3(int [], int, int); // Print the array
void revrse(int [], int);; // Reverse the array

void prob4();

// Problem 4 Functions
void init4(float [], int); // Initialize the array
float avgX(float [], int); // Calculate the Average
float stdX(float [], int); // Calculate the standard deviation

void prob5();

// Problem 5 Functions
void print5(const string &);

void read(string &);

int compare(const string &, const string &, string &);

void prob6();

// Problem 6 Functions
void fillAr6(int [], int);

bool linSrch(int [], int, int, int &);

void prob7();

// Problem 7 Functions
void fillAr7(int [], int);

void prntAr7(int [], int, int);

void selSrt(int [], int);

bool binSrc7(int [], int, int, int &);

void prob8();

// Problem 8 Functions
void fillAr8(int [], int);

void prntAr8(int [], int, int);

void bublSrt(int [], int);

bool binSrc8(int [], int, int, int &);

//Execution Begins Here
int main(int argc, char **argv) {
    //Declare Variables
    int option, //Option to choose from menu
            nOpshun; //Number of options

    //The Process -> Map Inputs to Outputs
    nOpshun = 8; //In this case we have 3 options
    do {
        //Display user choice
        cout << "Choose from the options displayed" << endl;
        cout << "1 -> Dice Table Sum" << endl;
        cout << "2 -> Product Table" << endl;
        cout << "3 -> Reverse Array Contents" << endl;
        cout << "4 -> Standard Deviation" << endl;
        cout << "5 -> Grading like a Scantron" << endl;
        cout << "6 -> Linear Search" << endl;
        cout << "7 -> Binary Search and Selection Sort" << endl;
        cout << "8 -> Binary Search with Bubble Sort" << endl;
        cout << "etc....." << endl;
        cin >> option; //Read in the option
        //Use a switch case to implement
        switch (option) {
            case 1:
                prob1();
                cout << '\n';
                break;
            case 2:
                prob2();
                cout << '\n';
                break;
            case 3:
                prob3();
                cout << '\n';
                break;
            case 4:
                prob4();
                cout << '\n';
                break;
            case 5:
                prob5();
                cout << '\n';
                break;
            case 6:
                prob6();
                cout << '\n';
                break;
            case 7:
                prob7();
                cout << '\n';
                break;
            case 8:
                prob8();
                cout << '\n';
                break;
            default:
                cout << "Exit Program\n";
        }
    } while (option <= nOpshun);

    //Exit the Program
    return 0;
}

void prob1() {
    //Declare Variables
    const int ROWS = 6;
    int tablSum[ROWS][COLS1];

    //Initialize or input i.e. set variable values
    fillTb1(tablSum, ROWS);

    //Display the outputs
    cout << "Think of this as the Sum of Dice Table\n";
    prntTb1(tablSum, ROWS);
}

void fillTb1(int table[][COLS1], int rows) {
    for (int x{0}; x < COLS1; x++) {
        for (int y{0}; y < rows; y++)
            table[y][x] = x + 1 + y + 1;
    }
}

void prntTb1(const int table[][COLS1], int rows) {
    const int lblSize = 4;
    const char ROWSLBL[lblSize] = {'R', 'O', 'W', 'S'};

    cout << string(11, ' ') << "C o l u m n s\n" << setw(6) << '|';
    for (int x{1}; x <= COLS1; x++)
        cout << setw(4) << x;
    cout << '\n' << string(34, '-') << '\n';

    for (int x{0}; x < COLS1; x++) {
        if (x >= 1 && x <= lblSize)
            cout << ROWSLBL[x - 1] << setw(3) << x + 1 << " |";
        else
            cout << setw(4) << x + 1 << " |";

        for (int y{0}; y < rows; y++)
            cout << setw(4) << table[y][x] << flush;
        cout << '\n';
    }
}

void prob2() {
    //Declare Variables
    const int ROWS = 6;
    int tblProd[ROWS][COLS2];

    //Initialize or input i.e. set variable values
    fillTb2(tblProd, ROWS);

    //Display the outputs
    cout << "Think of this as a Product/Muliplication Table\n";
    prntTb2(tblProd, ROWS);
}

void fillTb2(int table[][COLS2], int rows) {
    for (int x{0}; x < COLS2; x++) {
        for (int y{0}; y < rows; y++)
            table[y][x] = (x + 1) * (y + 1);
    }
}

void prntTb2(const int table[][COLS2], int rows) {
    const int lblSize = 4;
    const char ROWSLBL[lblSize] = {'R', 'O', 'W', 'S'};

    cout << string(11, ' ') << "C o l u m n s\n" << setw(6) << '|';
    for (int x{1}; x <= COLS2; x++)
        cout << setw(4) << x;
    cout << '\n' << string(34, '-') << '\n';

    for (int x{0}; x < COLS2; x++) {
        if (x >= 1 && x <= lblSize)
            cout << ROWSLBL[x - 1] << setw(3) << x + 1 << " |";
        else
            cout << setw(4) << x + 1 << " |";

        for (int y{0}; y < rows; y++)
            cout << setw(4) << table[y][x] << flush;
        cout << '\n';
    }
}

void prob3() {
    //Declare Variables
    const int SIZE = 50;
    const int ITMPROW = 10;
    int test[SIZE];

    //Initialize or input i.e. set variable values
    init3(test, SIZE);

    //Reverse the Values
    revrse(test, SIZE);

    //Display the outputs
    print3(test, SIZE, ITMPROW);
}

void init3(int array[], int size) {
    for (int i{0}; i < size; i++)
        cin >> array[i];
}

// Generalized to work with arrays of any size
void print3(int array[], int size, int itmPRow) {
    int rows{(size % itmPRow == 0 ? size : size + (itmPRow - size % itmPRow)) / itmPRow};
    for (int y{0}; y < rows; y++) {
        if (y < rows - 1 || size % itmPRow == 0) {
            for (int x{0}; x < itmPRow; x++)
                cout << array[y * itmPRow + x] << " ";
        } else
            for (int x{0}; x < size % itmPRow; x++)
                cout << array[y * itmPRow + x] << " ";
        cout << '\n';
    }
}

void revrse(int array[], int size) {
    int temp{};
    for (int i{0}; i < size / 2; i++) {
        temp = array[size - 1 - i];
        array[size - 1 - i] = array[i];
        array[i] = temp;
    }
}

void prob4() {
    //Declare Variables
    const int SIZE = 20;
    float test[SIZE];

    //Initialize or input i.e. set variable values
    init4(test, SIZE);

    //Display the outputs
    cout << fixed << setprecision(7);
    cout << "The average            = " << avgX(test, SIZE) << endl;
    cout << "The standard deviation = " << stdX(test, SIZE) << endl;
}

void init4(float array[], int size) {
    for (int i{0}; i < size; i++)
        cin >> array[i];
}

float avgX(float array[], int size) {
    float avg{0.00f};
    for (int i{0}; i < size; i++)
        avg += array[i];
    return avg / size;
}

float stdX(float array[], int size) {
    float std{0.00f};
    float avg{avgX(array, size)};

    for (int i{0}; i < size; i++)
        std += (array[i] - avg) * (array[i] - avg);

    std /= size - 1;

    return sqrt(std);
}

void prob5() {
    //Declare Variables
    string key, answers, score;
    int pRight;

    //Initialize or input i.e. set variable values
    read(key);
    read(answers);

    //Score the exam
    pRight = compare(key, answers, score);

    //Display the outputs
    cout << "C/W     ";
    print5(score);
    cout << "Percentage Correct = " << (static_cast<float>(pRight) / score.size()) * 100 << "%" << endl;
}

void read(string &key) {
    string temp{};
    cin >> temp;
    if (temp.size() == 1)
        key += temp;
    while (cin >> temp && temp.size() == 1)
        key += temp;
}

void print5(const string &str) {
    for (int i{0}; i < str.size(); i++)
        cout << str[i] << ' ';
    cout << '\n';
}

int compare(const string &key, const string &answers, string &score) {
    int correct{0};
    for (int i{0}; i < answers.size(); i++) {
        if (key[i] == answers[i]) {
            score += 'C';
            correct++;
        } else
            score += 'W';
    }
    return correct;
}

void prob6() {
    //Declare Variables
    const int SIZE = 100;
    int array[SIZE];
    int indx, val;

    //Initialize or input i.e. set variable values
    val = 50;
    fillAr6(array, SIZE);

    //Display the outputs
    if (linSrch(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
}

void fillAr6(int array[], int size) {
    for (int i{0}; i < size; i++)
        cin >> array[i];
}

bool linSrch(int array[], int size, int valFind, int &indx) {
    for (int i{0}; i < size; i++) {
        if (array[i] == valFind) {
            indx = i;
            return true;
        }
    }
    indx = -1;
    return false;
}

void prob7() {
    //Declare Variables
    const int SIZE = 100;
    int array[SIZE];
    int indx, val;

    //Initialize or input i.e. set variable values
    fillAr7(array, SIZE);

    //Sorted List
    selSrt(array, SIZE);

    //Display the outputs
    prntAr7(array, SIZE, 10);
    cout << '\n';
    cout << "Input the value to find in the array" << endl;
    cin >> val;
    if (binSrc7(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
}

void fillAr7(int array[], int size) {
    for (int i{0}; i < size; i++)
        cin >> array[i];
}

// Pulled from problem 3 - Generalized to work with arrays of any size
void prntAr7(int array[], int size, int itmPRow) {
    int rows{(size % itmPRow == 0 ? size : size + (itmPRow - size % itmPRow)) / itmPRow};
    for (int y{0}; y < rows; y++) {
        if (y < rows - 1 || size % itmPRow == 0) {
            for (int x{0}; x < itmPRow; x++)
                cout << array[y * itmPRow + x] << " ";
        } else
            for (int x{0}; x < size % itmPRow; x++)
                cout << array[y * itmPRow + x] << " ";
        cout << '\n';
    }
}


void selSrt(int array[], int size) {
    int temp{};
    int smlElm{};
    int idxSmEl{};

    for (int i{0}; i < size - 1; i++) {
        idxSmEl = i;
        smlElm = array[i];
        for (int j{i + 1}; j < size; j++) {
            if (array[j] < smlElm) {
                smlElm = array[j];
                idxSmEl = j;
            }
        }
        if (i != idxSmEl) {
            temp = array[i];
            array[i] = array[idxSmEl];
            array[idxSmEl] = temp;
        }
    }
}

bool binSrc7(int array[], int size, int valFind, int &indx) {
    int left{0};
    int right{size - 1};
    int middle{};
    while (left <= right) {
        middle = left + (right - left) / 2;

        if (valFind == array[middle]) {
            indx = middle;
            return true;
        }
        if (valFind < array[middle])
            right = middle - 1;
        if (valFind > array[middle])
            left = middle + 1;
    }
    indx = -1;
    return false;
}

void prob8() {
    //Declare Variables
    const int SIZE = 100;
    int array[SIZE];
    int indx, val;

    //Initialize or input i.e. set variable values
    fillAr8(array, SIZE);

    //Sorted List
    bublSrt(array, SIZE);

    //Display the outputs
    prntAr8(array, SIZE, 10);
    cout << '\n';
    cout << "Input the value to find in the array" << endl;
    cin >> val;
    if (binSrc8(array, SIZE, val, indx))
        cout << val << " was found at indx = " << indx << endl;
}

void fillAr8(int array[], int size) {
    for (int i{0}; i < size; i++)
        cin >> array[i];
}

// Pulled from problem 3 - Generalized to work with arrays of any size
void prntAr8(int array[], int size, int itmPRow) {
    int rows{(size % itmPRow == 0 ? size : size + (itmPRow - size % itmPRow)) / itmPRow};
    for (int y{0}; y < rows; y++) {
        if (y < rows - 1 || size % itmPRow == 0) {
            for (int x{0}; x < itmPRow; x++)
                cout << array[y * itmPRow + x] << " ";
        } else
            for (int x{0}; x < size % itmPRow; x++)
                cout << array[y * itmPRow + x] << " ";
        cout << '\n';
    }
}

void bublSrt(int array[], int size) {
    bool changed{};
    int temp{};

    do {
        changed = false;
        for (int i{0}; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                changed = true;
            }
        }
    } while (changed);
}

bool binSrc8(int array[], int size, int valFind, int &indx) {
    int left{0};
    int right{size - 1};
    int middle{};
    while (left <= right) {
        middle = left + (right - left) / 2;

        if (valFind == array[middle]) {
            indx = middle;
            return true;
        }
        if (valFind < array[middle])
            right = middle - 1;
        if (valFind > array[middle])
            left = middle + 1;
    }
    indx = -1;
    return false;
}
