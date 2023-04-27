/* Notes 2022-04-04
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: strings
 */

#include <iostream>
#include <string>
using namespace std;

const string projTitle = "Notes 2022-04-04";

// Add functions as desired


// Write main code here
void program() {
    string s = "Hello World!";
    string str1, str2, str3, str4;
    str1 = "Hello";
    str2 = "World";
    str3 = str2 + ", " + str1 + "!";
    cout << s << endl;
    
    
    cout << "\n\n";
}

// Function to test my program
void testProgram() {
    
    
}

// -------------------------------------------------------------

// Boolean to let user decide to run program again
bool runProgramAgain() {
    cout << "Do you want to run this program again? \n" <<
        "Input Y to continue or any other key to end program: ";
    char c;
    cin >> c;
    cout << endl;
    return (c == 'Y' || c == 'y');
}

// Main program
int main() {
    cout << "Welcome to " << projTitle << "\n\n";
    do {
        program(); // testProgram();
    } while (runProgramAgain());
    cout << "\nThank you for using " << projTitle << "\n\n";
    return 0;
}
