/* Lab HW7 Q1
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: basic practice with arrays
 */

#include <iostream>
using namespace std;

// Declare functions
void arrInitialize(double[], int);
void outputArray(double[], int);

// Main program
int main() {
    // Declare variables
    const int SIZE = 50;
    double alpha[SIZE];

    // Initialize array
    arrInitialize(alpha, SIZE);

    // Output array
    outputArray(alpha, SIZE);
    
    cout << "\n\n";
    return 0;
}

// -------------------------------------------------------------

// Function to initialize referenced array according to HW instructions
void arrInitialize(double alpha[], int SIZE)
{
    int index = 0;
    
    // Loop to repeat for the first half of the array
    for (index = 0; index < SIZE/2; index++) {
        // Assign the value of the array to the square of the index
        alpha[index] = index * index;
    }
    // Loop to repeat for the second half of the array
    for (; index < SIZE; index++) {
        // Assign the value to 3 times the index
        alpha[index] = index * 3;
    }
}

// Function to output array on 5 lines
void outputArray(double alpha[], int SIZE)
{
    int i = 0;

    // Loop to repeat 5 times for 5 lines
    for (int j = 1; j <= 5; j++)
    {
        cout << endl;

        // Loop to repeat for 1/5 of the array
        for (; i < SIZE*j/5; i++) {
            cout << alpha[i] << " "; // output it on one line
        }
    }
    cout << endl;
}
