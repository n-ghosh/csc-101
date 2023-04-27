/* Lab HW7 Q3
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: process election data to determine the winner and the voting distribution.
 Practice with parallel arrays. This program also experiments with Hungarian notation.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Declare constants
const char PROJ_TITLE[] = "Local Election";
const short SIZE = 5; // number of candidates

// Declare functions
int iGetNames_Votes(string[], int[]);
void outputElection(string[], int[], int);

// Main program
int main() {
    // Declare variables
    string sCandNames[SIZE]; // parallel array of names of candidates
    int iCandVotes[SIZE]; // parallel array of vote-counts per candidate
    int iAllVotes; // number of votes in the whole election

    cout << "Welcome to " << PROJ_TITLE << "\n\n";

    // Get each candidate's info and the total number of votes
    iAllVotes = iGetNames_Votes(sCandNames, iCandVotes);

    // Process and output election results and declare the winner
    outputElection(sCandNames, iCandVotes, iAllVotes);
    
    cout << "\nThank you for using " << PROJ_TITLE << "\n\n";
    return 0;
}

// -------------------------------------------------------------

// Function to get input of each candidate's name and votes received, store them in the referenced arrays, and
// return the total number of votes in this election
int iGetNames_Votes(string sNames[], int iVotes[])
{
    int iSum = 0; // for the total number of votes

    // Loop to repeat for each candidate
    for (int i = 0; i < SIZE; i++)
    {
        // Get input of name
        cout << "Enter the last name of candidate " << i+1 << ": ";
        cin >> sNames[i];
        
        // Get input of votes
        cout << "Enter how many votes " << sNames[i] << " received: ";
        cin >> iVotes[i];
        
        if (!cin) {
            cin.clear();
            cin.ignore();
            cout << "Must input an integer for number of votes. \n";
            i--;
        }
        // Update sum of votes
        iSum = iSum + iVotes[i];
    }
    cout << endl;
    return iSum;
}


// Function to calculate and output the election's results and declare the winner
// Much of the code is just for formatting
void outputElection(string sNames[], int iVotes[], int iSum)
{
    int iMax = iVotes[0]; // for determining the winner
    string sWinner = sNames[0];
    const char linebreak[] = "----------------------------------------\n";
    
    // Print table header
    cout << linebreak;
    cout << "|  Candidates  |   Votes  | % of Total | \n";
    cout << "|              | Received |    Votes   | \n";
    cout << linebreak;
    cout << fixed << setprecision(2);
    
    // Loop to repeat for each candidate
    for (int i = 0; i < SIZE; i++)
    {
        // Print each's name, number of votes, and % of total votes
        double dVotePercent = 100.0 * iVotes[i] / iSum;
        cout << "| " << setw(12) << left << sNames[i] << " | " << setw(8) << right << iVotes[i]
         << " | " << setw(10) << dVotePercent << " | \n";
        
        // Check if they're the winner
        if (iVotes[i] >= iMax) {
            iMax = iVotes[i];
            sWinner = sNames[i];
        }
    }
    
    // Print the total vote count and the winner
    cout << linebreak;
    cout << "| Total Votes: " << setw(10) << iSum << setw(17) << " | \n";
    cout << linebreak;
    cout << "| " << setw(34 + int(sWinner.length())) << " | \n";
    cout << "| The Winner of the Election is " << sWinner << " | \n";
    cout << "| " << setw(34 + int(sWinner.length())) << " | \n";
    cout << setw(2 + 34 + int(sWinner.length())) << setfill('-') << "- \n";
}
