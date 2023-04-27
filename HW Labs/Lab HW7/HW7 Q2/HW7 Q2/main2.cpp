/* Lab HW7 Q2
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: process student test scores and calculate the number of students
 in each score range
 */

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const char FILE_NAME[] = "Students Scores.txt";

// Declare functions
void ProcessScoresFromFile(int[]);
string strScoreFromRawInput(string);
void outputScoreRanges(int[]);


// Main program
int main()
{
    // Declare variables
    int iNumInRanges[] = {0, 0, 0, 0, 0, 0, 0, 0}; // number of students in each score range

    // Process input of student scores from the file to update iNumInRanges
    ProcessScoresFromFile(iNumInRanges);

    // Output the number of students in each score range
    outputScoreRanges(iNumInRanges);

    cout << "\n\n";
    return 0;
}

// -------------------------------------------------------------

// Function to process input of student scores from the file to update iNumInRanges
void ProcessScoresFromFile(int iNumInRanges[])
{
    ifstream fileScores; // declare input file stream

    fileScores.open(FILE_NAME); // open file
    
    // Loop to repeat for every score in the file
    while (!fileScores.eof())
    {
        // Get each score as a string
        string str; // temporary string to store input
        fileScores >> str;
        str = strScoreFromRawInput(str); // erase comma and any other symbols
        if (str.length() == 0) {
            break; // if it didn't read anything, break
        }
        
        // Determine the student's score range
        int r = int(stof(str)) / 25; // cast the string to a float then to an int
        if (r > 7) r = 7; // if a student scored 200 or higher, put them in the top group

        // Update the array of students in each score range
        iNumInRanges[r]++;
    }
    fileScores.close(); // 2022-05-03 I forgot this when submitting homework. 
}

// Function to remove the comma and other symbols
string strScoreFromRawInput(string sRawScore)
{
    string sScore;
    // Loop to repeat for every character in the input string
    for (int i = 0; i < sRawScore.length(); i++) {
        // Check if the character is a number or decimal point. If so, save it
        if ((sRawScore[i] >= '0' && sRawScore[i] <= '9')
            || sRawScore[i] == '.') {
            sScore += sRawScore[i];
        }
        // If not, stop looping
        else {
            break;
        }
    }
    return sScore;
}

// Function to print the number of students in each score range.
// Much of the code is just for formatting
void outputScoreRanges(int iNumInRanges[])
{
    const int RANGE_LIMIT = 25;
    char linebreak[] = "--------------------------\n";

    cout << linebreak;
    cout << "|   Score   |  Number of | \n";
    cout << "|   Range   |  Students  | \n";
    cout << linebreak;
    
    // Loop to repeat for each score range. Print it and the number of students in it
    // I use two loops and print the last line separately to clean the output and because
    // the last line doesn't follow the same formula for calculating the score range
    for (int i = 0; i < 4; i++) {
        cout << "| " << setw(4) << i*RANGE_LIMIT << "-" << (i*RANGE_LIMIT) + RANGE_LIMIT-1
        << setw(5) << " | " << setw(6) << iNumInRanges[i] << setw(7) << " |\n";
    }
    for (int i = 4; i < 7; i++) {
        cout << "| " << setw(4) << i*RANGE_LIMIT << "-" << (i*RANGE_LIMIT) + RANGE_LIMIT-1
        << setw(4) << " | " << setw(6) << iNumInRanges[i] << setw(7) << " |\n";
    }
    cout << "| " << setw(4) << "175" << "-200" << setw(4) << " | "
    << setw(6) << iNumInRanges[7] << setw(7) << " |\n";
    cout << linebreak;
}
