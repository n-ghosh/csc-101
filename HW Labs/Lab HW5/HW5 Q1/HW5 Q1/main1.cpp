/* Lab HW5 Q1
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: use some cmath functions. Output the square root of pi, take input of a sphere's radius, and output the sphere's surface area and volume.
 */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Declare functions
void outputSphere(double, double, double);
bool runProgramAgain();


// Main program
int main()
{
    // Declare variables
    const double PI = 3.14159;
    double r, surfaceArea, volume;
    
    // Loop to run program as many times as user decides
    do {
        // Output square root of pi
        cout << fixed << setprecision(2);
        cout << "Square root of pi: " << sqrt(PI) << endl;
        
        // Get input of sphere's radius
        cout << "Input the radius of the sphere: ";
        cin >> r;
        
        // Calculate sphere's surface area and volume
        surfaceArea = 4.0 * PI * pow(r, 2.0); // SA = 4 pi r^2
        volume = (4.0/3.0) * PI * pow(r, 3.0); // V = 4/3 pi r^3
        
        // Output sphere's surface area and volume
        outputSphere(r, surfaceArea, volume); // using a function just to keep main() clean
    } while (runProgramAgain()); // simple bool function to let user decide to run program again
    
    return 0;
}

// Function to output the sphere's surface area and volume, correctly formatted
void outputSphere(double radius, double surfaceArea, double volume)
{
    cout << "Surface area of the sphere: 4 * PI * "<< radius <<" ^ 2 = "<< surfaceArea << endl;
    cout << "Volume of the sphere: 4 / 3 * PI * "<< radius <<" ^ 3 = "<< volume << endl;
    cout << "\n\n";
}

// Function to let user decide to run program again or not
bool runProgramAgain()
{
    cout << "Do you want to run this program again? "
    << "Input Y to continue or any other key to end: ";
    char c;
    cin >> c;
    cout << endl;
    return (c == 'Y' || c == 'y');
}
