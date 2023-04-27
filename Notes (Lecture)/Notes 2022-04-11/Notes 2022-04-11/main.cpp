/* Notes 2022-04-11 && 04-12*
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: intro to arrays
 
 *Zee missed class on 04-11, rescheduled for 04-12
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Declare constants and functions
const string PROJ_TITLE = "Notes 2022-04-11";
void program();
void outputArray(double[], int);
bool runProgramAgain();
void testProgram();

// Main program
int main() {
    cout << "Welcome to " << PROJ_TITLE << "\n\n";
    do {
        program(); // testProgram();
    } while (runProgramAgain()); // boolean for user decision to run program again
    cout << "\nThank you for using " << PROJ_TITLE << "\n\n";
    return 0;
}

// -------------------------------------------------------------

// Write main code here
void program() {
    ifstream inFile;
    int size, c;
    
    // Get array size
    inFile.open("InputClassData.txt"); // I made a file. First number is the size
    inFile >> size;
    /*
    cout << "Enter class size: ";
    cin >> size; */
    
    // Must declare arrays after knowing size
    double hwAVG[size], testAVG[size], finalAvg[size];
    
    // Loop to assign input for each (cell) in array
    cout << "---- Avg before adjust ---- \n";
    for (c = 0; c < size; c++) {
        inFile >> hwAVG[c] >> testAVG[c];
        finalAvg[c] = hwAVG[c]*0.4 + testAVG[c]*0.6;
        cout << "Average for #" <<c << ": " << finalAvg[c] << endl;
    }
    inFile.close();
    
    /*
    for (c = 0; c < size; c++) {
        cout << "Enter HW avg and test avg for student " << c+1 << ": ";
        cin >> hwAVG[c] >> testAVG[c];
        finalAvg[c] = hwAVG[c]*0.4 + testAVG[c]*0.6;
    } */
    
    // Loop to output each (cell) in array
    outputArray(finalAvg, size);
    
    cout << "Hello World!\n\n";
}


// Loop to output each (cell) in array
void outputArray(double arr[], int size) {
    cout << fixed << setprecision(1);
    for (int c = 0; c < size; c++) {
        cout << "Student " << c+1 << " average: " << arr[c] << endl;
    }
}
// Add functions as desired


// Function to test my program
void testProgram() {
}

// -------------------------------------------------------------

// Function to return boolean for user decision to run program again
bool runProgramAgain() {
    cout << "Do you want to run this program again? \n" <<
        "Input Y to continue or any other key to end program: ";
    char c;
    cin >> c;
    cout << endl;
    return (c == 'Y' || c == 'y');
}
