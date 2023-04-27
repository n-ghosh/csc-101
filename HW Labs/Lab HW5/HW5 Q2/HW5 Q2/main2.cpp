/* Lab HW5 Q2
 By Nikhil Ghosh
 For STCC CSC 101
 
 Description: fix a program intended to allow the user to perform one of three geometric functions and to run as many times as the user decides.
 In the original program, about 13 statements were in the wrong order and about 8 statements had errors. All of the function calls were both in the wrong order and incorrect. I've only indicated where I've fixed errors in statements.
 I slightly changed the program to reduce inefficiency in repeating code: by moving the input statements and changing the while loop to do..while
 The original program did not use comments. I've added some.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Declare constants and functions
const double PI = 3.14159;
double rectangle(double l, double w);
double circle(double r); // here, error in missing ";"
double cylinder(double bR, double h);

int main()
{
    // Declare variables
    int choice;
    double radius;
    double height;
    double length, width;

    // Output a description of the program
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "This program can calculate the area of a rectangle, "
    << "the area of a circle, or volume of a cylinder." << endl;

    // Loop the program as long as the user decides to
    do {
        // Input user's decision to run program
        cout << "To run the program enter: " << endl;
        cout << "1: To find the area of rectangle." << endl;
        cout << "2: To find the area of a circle." << endl;
        cout << "3: To find the volume of a cylinder." << endl;
        cout << "-1: To terminate the program." << endl;
        cin >> choice;
        cout << endl;

        // Determine which function the user chose and run it
        switch (choice)
        {
        case 1:
            cout << "Enter the length and the width "
                << "of the rectangle: ";
            cin >> length >> width;
            cout << endl;
            cout << "Area = " << rectangle(length, width) << endl; // here, error in function call's parameters (and statement was misplaced)
            break;
        case 2:
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            cout << endl;
            cout << "Area = " << circle(radius) << endl; // here, error in function call's parameters (and statement was misplaced)
            break;
        case 3:
            cout << "Enter the radius of the base and the "
                << "height of the cylinder: ";
            cin >> radius >> height;
            cout << endl;
            cout << "Volume = " << cylinder(radius, height) << endl; // here, error in function call's parameters (and statement was misplaced)
            break;
        // I added a case for -1 because my change to the program made it valid and necessary to prevent the default
        case -1:
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != -1); // here, error in saying "while (choice == -1)" instead of "while (choice != -1)". The first version would mean the loop body would only execute if the user inputted -1

    return 0;
}

// Function to return the area of a rectangle, given length and width
double rectangle(double l, double w)
{
    return l * w; // here, error in saying "* r;" instead of "* w;"
}

// Function to return the area of a circle, given radius
double circle(double r)
{
    return PI * r * r; // here, error in saying "* w;" instead of "* r;"
}

// Function to return the volume of a cylinder, given base radius and height
double cylinder(double bR, double h)
{
    return PI * bR * bR * h; // here, error in saying "* l;" instead of "* h;"
}
