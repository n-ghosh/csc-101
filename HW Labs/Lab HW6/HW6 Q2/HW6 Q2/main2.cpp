/* Lab HW6 Q2
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: convert a string's characters to integers and output their sum
 */

#include <iostream>
using namespace std;

const char DESCRIPTION[] = "This program converts a string's characters to integers using ASCII value and returns their sum. ";

// Declare functions
int sumStrChars(string);

// Main program
int main() {
    // Declare variables
    string str;

    // Get input of string
    cout << DESCRIPTION << "\n\n" << "Input string: ";
    getline(cin, str);
    
    // Processs and output
    cout << "'" + str + "' -> " << sumStrChars(str) << "\n\n";
    return 0;
}


// Function to return the sum of all values (ASCII values) of each character in a string
int sumStrChars(string str)
{
    int sum = 0;
    for (char c : str)  // for each character in the string
        sum = sum + int(c);  // add it's ASCII value to the sum
    return sum;
}
