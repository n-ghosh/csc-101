/* Lab HW5 Q3
 By Nikhil Ghosh
 For STCC CSC 101
 
 Description: practice creating functions. Part of the program is for processing paycheck data, and the other part is for playing with simple variables.
 Some of the assignment's instructions seem to conflict with its example of output. For example, one line says to update two variables x and y inside a function "funcOne()", and the example of output shows that the two variables are updated before funcOne() is called.  I am choosing to follow the instructions and have a different output.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Declare functions
void initialize(int&, int&, char&);
void getHoursRate(double&, double&);
double paycheck(double, double);
void printCheck(double, double, double);
void funcOne(int&, int&);
void nextChar(char&);

// Main program
int main()
{
    // Declare variables
    int x, y;
    char z;
    double rate, hours;
    double amount;
    
    // Initialize some of the variables using a function
    initialize(x, y, z);
    cout << "After initialization: x = " << x << ", y = " << y << ", z = " << z << "\n\n";
    
    // Process a paycheck using functions
    getHoursRate(hours, rate); // get input of hours worked and wage rate
    amount = paycheck(hours, rate); // calculate gross income
    printCheck(hours, rate, amount); // output paycheck data
    
    // Playing with simple variables using functions with reference parameters
    // x = 35; y = 20; The assignment is unclear if this line should be here or in funcOne(). I'm choosing funcOne() based on the instructions.
    cout << "Before calling funcOne: x = " << x << ", y = " << y << endl;
    funcOne(x, y);
    cout << "After funcOne: x = " << x << endl;
    
    z = 'B'; // I wasn't certain what the assignment wanted with this variable.
    cout << endl << "z = " << z << endl;
    nextChar(z);
    cout << "After nextChar: z = " << z << endl;
    
    cout << endl;
    return 0;
}

// Define Functions

// Function to initialize three referenced variables from main()
void initialize(int& num1, int& num2, char& ch)
{
    num1 = num2 = 0;
    ch = ' ';
}

// The next three functions are all for the paycheck story

// Function to prompt input of hours worked and pay rate and store them in the referenced variables from main()
void getHoursRate(double& hours, double& rate)
{
    cout << "Enter hours worked: ";
    cin >> hours;
    cout << "Enter pay rate: ";
    cin >> rate;

}
// Function to return the total paycheck income from hours worked and payrate, considering overtime
double paycheck(double hours, double rate)
{
    double income;
    if (hours > 40) { // check for overtime
        income = rate * (1.5 * hours - 20); // = (rate * 40) + (rate * 1.5(hours - 40))
    } else {
        income = hours * rate;
    }
    return income;
}
// Function to print the paycheck's information.
void printCheck(double hours, double rate, double salary)
{
    cout << fixed << setprecision(2);
    cout << "\nHours Worked: " << hours << endl;
    cout << setw(18) << left << "Pay Rate: $" << setw(8) << right << rate << endl;
    cout << setw(18) << left << "Week's Salary: $" << setw(8) << right << salary << "\n\n";
}


// Function to input a number, and use it to re-update one of the variables referenced from main()
// The assignment is unclear if this function is also supposed to update the variables from main() or if main() is supposed to update them before calling this function. I am choosing to update them here.
void funcOne(int& x, int& y)
{
    int num;
    x = 35;
    y = 20;
    cout << "In funcOne, before user input: x = " << x << ", y = " << y << endl;
    cout << "Enter an integer: ";
    cin >> num;
    x = 2*x + y - num;
}

// Function to update the referenced char variable from main() to the next character by ASCII value.
void nextChar(char& ch)
{
    ch++;
}
