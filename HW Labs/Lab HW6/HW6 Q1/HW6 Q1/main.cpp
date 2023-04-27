/* Lab HW6 Q1
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: use enumerated types to determine the type of triangle that a 3-sided shape is
 */

#include <iostream>
using namespace std;

const char DESCRIPTION[] = "This program returns the type of a triangle from input of the lengths of 3 sides. ";

// Define enumerated types
enum TriangleType {scalene, isosceles, equilateral, noTriangle};

// Declare functions
TriangleType triangleShape(int, int, int);
void outTriangle(TriangleType);
void testProgram();


// Main program
int main() {
    // Declare variables
    double a, b, c;
    TriangleType tri;
    
    // Get input of side lengths
    cout << DESCRIPTION << "\n\nInput 3 side lengths: ";
    cin >> a >> b >> c;
    
    // Calculate triangle type
    tri = triangleShape(a, b, c);
    
    // Output triangle type
    outTriangle(tri); // outTriangle(triangleShape(a, b, c));

    cout << endl;
    return 0;
}

// -------------------------------------------------------------
// Define Functions

// Function to return the triangle type from input of 3 side lengths
TriangleType triangleShape(int a, int b, int c)
{
    if (a >= b+c || b >= a+c || c >= a+b) // if any 1 side is >= than the sum of the other 2 sides,
        return noTriangle; // it's not a triangle
    if (a == b && b == c) // otherwise, if all 3 sides are equal, it's equilateral
        return equilateral;
    if (a == b || b == c || a == c) // otherwise, if any 2 sides are equal, it's isosceles
        return isosceles;
    return scalene; // otherwise it's scalene
}

// Function to output the triangle type
void outTriangle(TriangleType tri)
{ // I found if-else statements neater than a switch structure with cases
    cout << "This shape is: ";
    if (tri == 0)
        cout << "scalene.";
    else if (tri == 1)
        cout << "isosceles.";
    else if (tri == 2)
        cout << "equilateral.";
    else
        cout << "not a triangle.";
    cout << endl;
}
