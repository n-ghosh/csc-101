/* Lab HW6 Q3
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: arithmetic operations with fractions
 */

#include <iostream>
using namespace std;

const char DESCRIPTION[] = "This program lets the user perform arithmetic with 2 fractions operands.  Fractions are of the form a/b, where a and b are integers and b != 0. Arithmetic is of the form a/b _ c/d = e/f, where _ is an operator + - * / ";

// Declare functions
char menu();
void inputFractions(char, int&, int&, int&, int&);
void callOperation(char, int, int, int, int, int&, int&);
void addFractions(int, int, int, int, int&, int&);
void subtractFractions(int, int, int, int, int&, int&);
void multiplyFractions(int, int, int, int, int&, int&);
void divideFractions(int, int, int, int, int&, int&);
void print(char, int, int, int, int, int, int);
void testProgram();

// Main program
int main()
{
    // Declare variables
    int f1Num, f1Den, f2Num, f2Den, f3Num = 0, f3Den = 1; // Numerators and Denominators of 3 Fractions
    char cOperation; // char for the arithmetic operation to perform

    // Output explanation and get input of chosen operation
    cOperation = menu();
    
    // Get input of 2 operands and store in variables referenced
    inputFractions(cOperation, f1Num, f1Den, f2Num, f2Den);
    
    // Interpret the user's choice and run the corresponding arithmetic operation
    callOperation(cOperation, f1Num, f1Den, f2Num, f2Den, f3Num, f3Den);

    // Print the whole statement
    print(cOperation, f1Num, f1Den, f2Num, f2Den, f3Num, f3Den);
    
    cout << endl;
    return 0;
}

// -------------------------------------------------------------

// Function to output an explanation to the user, get input of their choice, and return it as a char
char menu()
{
    string choice; // using a string in case the user mistypes multiple characters
    cout << DESCRIPTION << "\nTo input the 2 fractions, you will enter 4 integers, "
    << "separated by a space, in the form a b c d, "
    << "where a/b is the first operand and c/d is the second operand. \n\nFirst: ";
    
    do { // indefinite loop, to break on first valid input
        cout << "Enter +, -, *, or / to choose an operation: ";
        cin >> choice;
        if (choice != "+" && choice != "-" && choice != "*" && choice != "/")
            cout << "Error: '" + choice + "' invalid. \n";
        else
            break;
    } while (true);
    return choice[0];
}

// Function to get input of the operands and update the 4 reference parameters
void inputFractions(char Operation, int& f1Num, int& f1Den, int& f2Num, int& f2Den)
{
    do { // indefinite loop, to break on first valid input
        cout << "Enter 4 integers: ";
        cin >> f1Num >> f1Den >> f2Num >> f2Den;
        
        // Validate input
        if (!cin) { // check for input stream failure. Probably caused by failed conversion to integer
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Error: Can only input integers. \n";
        }
        else if (f1Den == 0 || f2Den == 0) // check if denominators are 0
            cout << "Error: Denominator cannot be 0. \n";
        else if (Operation == '/' && f2Num == 0) // check if dividing and second fraction is 0
            cout << "Error: Divisor cannot be 0. \n";
        else // otherwise it's valid, break the loop
            break;
    } while (true);
}

// Function to determine what the user chose and call the cooresponding arithmetic function, passing to it the appropriate reference parameters
void callOperation(char Operation, int f1Num, int f1Den, int f2Num, int f2Den, int& f3Num, int& f3Den)
{ // I found if-else statements to be neater than a switch structure with cases
    if (Operation == '+')
        addFractions(f1Num, f1Den, f2Num, f2Den, f3Num, f3Den);
    else if (Operation == '-')
        subtractFractions(f1Num, f1Den, f2Num, f2Den, f3Num, f3Den);
    else if (Operation == '*')
        multiplyFractions(f1Num, f1Den, f2Num, f2Den, f3Num, f3Den);
    else if (Operation == '/')
        divideFractions(f1Num, f1Den, f2Num, f2Den, f3Num, f3Den);
    else // this should never happen, because the menu() function should only return a char above
        cout << "Error: '" << Operation << "' is invalid choice. \n";
}

// The following 4 functions take 4 value parameters for the 2 fraction operands and update the 2 reference parameters with the appropriate value for each arithmetic operation's answer. The variables use different names for easier reading
// Function to perform addition with fractions
void addFractions(int a, int b, int c, int d, int& numerator, int& denominator)
{ // a/b + c/d = (ad + cb) / bd
    numerator = (a * d) + (c * b);
    denominator = b * d;
}
// Function to perform subtraction with fractions
void subtractFractions(int a, int b, int c, int d, int& numerator, int& denominator)
{ // a/b - c/d = (ad - cb) / bd
    numerator = (a * d) - (c * b);
    denominator = b * d;
}
// Function to perform multiplaction with fractions
void multiplyFractions(int a, int b, int c, int d, int& numerator, int& denominator)
{ // a/b * c/d = ac / bd
    numerator = a * c;
    denominator = b * d;
}
// Function to perform division with fractions
void divideFractions(int a, int b, int c, int d, int& numerator, int& denominator)
{ // (a/b) / (c/d) = ad / bc
    numerator = a * d;
    denominator = b * c;
}
// -- this ends the group of 4 functions for arithmetic operations

// Function to output the calculation
void print(char operation, int a, int b, int c, int d, int e, int f)
{
    cout << a << "/" << b << " " << operation << " "
        << c << "/" << d << " = "
        << e << "/" << f << "\n";
}


// Function to test my program
void testProgram()
{
    const int size = 4; // the number of tests I created
    char testOp[size] = {'+', '*', '-', '/'}; // corresponding operations for my test fractions
    int test[size][6] = { {3, 4, 2, 5, 23, 20}, // writing my own test fractions
        {2, 3, 3, 5, 6, 15},
        {1, 2, 0, 3, 3, 6},
        {0, 1, 2, 3, 0, 2}
    };
    for (int i = 0; i<size; i++) {
        int num, den = 0;
        callOperation(testOp[i], test[i][0], test[i][1], test[i][2], test[i][3], num, den);
        if (num == test[i][4] && den == test[i][5])
            cout << "Test #" <<i+1<< " passed. \n";
        else {
            cout << "Test #" <<i+1<< " FAILED. Expected: " << test[i][4] << "/" << test[i][5]
            << ". Instead:  ";
            print(testOp[i], test[i][0], test[i][1], test[i][2], test[i][3], num, den);
        }
    }
    int count = 0;
    for (int i=4; i<10000; i++) {
        int num, den;
        callOperation(testOp[0], test[0][0], test[0][1], test[0][2], test[0][3], num, den);
        if (num == test[0][4] && den == test[0][5])
            continue;//cout << "Test #" <<i+1<< " passed. ";
        else {
            count++;
            cout << "Test #" <<i+1<< " FAILED. Expected: " << test[0][4] << "/" << test[0][5]
            << ". Instead:  ";
            print(testOp[0], test[0][0], test[0][1], test[0][2], test[0][3], num, den);
        }
    }
    cout << "In 10,000 repetitions, " <<count<< " errors. ";
    cout << endl;
}

