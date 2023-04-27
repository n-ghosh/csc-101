/* Lab HW8 Q3
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: using array of structures for a list of football players.
 A menu-driven program, with a list of football players, that reads the list from a file and lets the user search for player information, input updated info, output the whole list, and save the updated list to the file.
 
 This program also continues my experimenting with naming conventions.
 Constants use all-caps and underscores: CAPPED_CONST
 Variables and non-void functions use Hungarian notation: int iNum; string sName; int aScores[10];
  
 */

// Include libraries
#include <iostream> // for standard console input-output
#include <fstream> // for files
using namespace std;

// Define constants for this program
const char PROJ_TITLE[] = "Football Roster"; // the title of the program
const char ROSTER_FILE_NAME[] = "Input Roster.txt"; // the name of the file used for data input
const short ROSTER_COUNT = 10; // the number of players in the file
const string MENU[] = { // the menu options for the user
    "1: To print a player's data \n",
    "2: To print the entire roster's data \n",
    "3: To update a player's touchdowns \n",
    "4: To update a player's number of catches \n",
    "5: To update a player's passing yards \n",
    "6: To update a player's receiving yards \n",
    "7: To update a player's rushing yards \n",
    "99: To quit the program \n" };
const short MENU_LENGTH = 8;


// Define data structures
struct FootballPlayer // a generic football player, with the following information
{
    string sName; // the player's name
    string sPosition; // the player's football position
    int iTouchdowns; // the player's number of touchdowns
    int iCatches; // the player's number of catches
    int iPassingYards; // the player's number of passing yards
    int iReceivingYards; // the player's number of receiving yards
    int iRushingYards; // the player's number of rushing yards
};

// Declare functions (define below)
void getRosterData(FootballPlayer[]);
int iGetMenuChoice();
int iGetPlayer(FootballPlayer[]);
FootballPlayer playerGetUpdate(int, FootballPlayer);
void printPlayerData(FootballPlayer);
void printRosterData(FootballPlayer[]);
bool isUserSavingData();
void saveRosterToFile(FootballPlayer Roster[]);

void getInput(string&, string, string);
void getInput(int&, string, string);
string sToUpper(string);

// ------------------------------------------------------------------------------------------------
// Main program
int main()
{
    // Declare variables
    FootballPlayer Roster[ROSTER_COUNT]; // the array of football players
    int iMenuChoice = 0; // for the user's chosen option from the menu

    // Get input of the array of players from the file
    cout << "Welcome to " << PROJ_TITLE;
    getRosterData(Roster);
    
    // Loop to repeat until the user decides to quit
    // Run the menu, let the user to select an option, and execute
    while (iMenuChoice != 99)
    {
        iMenuChoice = iGetMenuChoice();
        if (iMenuChoice == 99) // if they chose to quit, break the loop
            break;
        if (iMenuChoice == 2)
            printRosterData(Roster);
        else
        { // otherwise they chose 1 or 3-7, for a specific player
            int iPlayerIndex = iGetPlayer(Roster); // find out which player
            if (iMenuChoice != 1) // update the player if they chose
                Roster[iPlayerIndex] = playerGetUpdate(iMenuChoice, Roster[iPlayerIndex]);
            printPlayerData(Roster[iPlayerIndex]); // output the player's data
        }
    }
    
    // Let the user save the data if they want
    if (isUserSavingData())
        saveRosterToFile(Roster);
    
    cout << "\nThank you for using " << PROJ_TITLE << "\n\n";
    return 0;
}

// ------------------------------------------------------------------------------------------------
// Define functions

// Get Roster data from the file
// Returns array of FootballPlayer through the reference parameter
void getRosterData(FootballPlayer Roster[])
{
    ifstream fileRosterInput;
    fileRosterInput.open(ROSTER_FILE_NAME);
    
    // Loop to repeat for every player in the file
    for (int i = 0; i < ROSTER_COUNT; i++)
        // Get each statistic and store it in the structure for the player
        // The file is formatted so the statistics match this order: name, position, etc,
        // and every string is one word, so I don't need to use getline().
        fileRosterInput >> Roster[i].sName
                        >> Roster[i].sPosition
                        >> Roster[i].iTouchdowns
                        >> Roster[i].iCatches
                        >> Roster[i].iPassingYards
                        >> Roster[i].iReceivingYards
                        >> Roster[i].iRushingYards;
    // At the end, close the file
    fileRosterInput.close();
}

// Run the menu, let the user to select an option to execute, and validate user selection
// Returns the integer for the user's menu selection
int iGetMenuChoice()
{
    int iMenuChoice; // integer for the uesr's choice
    
    // Print the menu to the console user
    cout << "\nSelect one of the following options: \n";
    for (int i = 0; i < MENU_LENGTH; i++)
        cout << MENU[i];
    cout << endl;
    
    // Loop to repeat until return statement on valid input
    while (true)
    {
        // Get user's menu selection
        getInput(iMenuChoice, "int", "Enter selection: "); // use my input function
        
        // Validate selection
        if (iMenuChoice != 99 && (iMenuChoice < 1 || iMenuChoice > 7))
        {
            cout << iMenuChoice << " is invalid selection. Please try again. ";
            continue;
        }
        cout << endl;
        return iMenuChoice;
    }
}

// Get the user to input a player's name, and validate the player is in the roster
// Returns the array index of the player named
int iGetPlayer(FootballPlayer Roster[])
{
    // Loop to repeat until return statement on valid input
    while (true)
    {
        // Get input of player name
        string sInput;
        getInput(sInput, "string", "Enter player name: ");
        cout << endl;
        
        // Check the roster for the input name
        sInput = sToUpper(sInput); // convert the strings to uppercase for easier searching
        for (int i = 0; i < ROSTER_COUNT; i++)
            if (sToUpper(Roster[i].sName) == sInput)
                return i;
        // If the name was not in the roster, inform the user and try again
        cout << "Player " << sInput << " not in the Roster. Please try again. ";
    }
}

// Get the updated statistic for the named FootballPlayer based on the user's menu choice
// Returns a FootballPlayer with the updated information
FootballPlayer playerGetUpdate(int iMenuChoice, FootballPlayer fPlayer)
{
    // Use a conditional to determine which statistic the user chose to update
    // Output the player's old statistic, and
    // Get the user's input of the new statistic and save it
    cout << fPlayer.sName << "'s current ";
    switch (iMenuChoice)
    {
        case 3:
            cout << "Touchdowns: " << fPlayer.iTouchdowns << endl;
            getInput(fPlayer.iTouchdowns, "int", "Enter updated data: ");
            break;
        case 4:
            cout << "Catches: " << fPlayer.iCatches << endl;
            getInput(fPlayer.iCatches, "int", "Enter updated data: ");
            break;
        case 5:
            cout << "Passing Yards: " << fPlayer.iPassingYards << endl;
            getInput(fPlayer.iPassingYards, "int", "Enter updated data: ");
            break;
        case 6:
            cout << "Receiving Yards: " << fPlayer.iReceivingYards << endl;
            getInput(fPlayer.iReceivingYards, "int", "Enter updated data: ");
            break;
        case 7:
            cout << "Rushing Yards: " << fPlayer.iRushingYards << endl;
            getInput(fPlayer.iRushingYards, "int", "Enter updated data: ");
            break;
        default:
            cout << "Programmer error. iMenuChoice should be 3-7, instead is "
            << iMenuChoice << "\n";
    }
    cout << endl;
    return fPlayer;
}

// Output a player's data to the console
void printPlayerData(FootballPlayer fPlayer)
{
    cout << "Name: " << fPlayer.sName
        << ";  Position: " << fPlayer.sPosition
        << ";\nTouchdowns: " << fPlayer.iTouchdowns
        << ";  Number of Catches: " << fPlayer.iCatches
        << ";\nPassing Yards: " << fPlayer.iPassingYards
        << ";  Receiving Yards: " << fPlayer.iReceivingYards
        << ";  Rushing Yards: " << fPlayer.iRushingYards << "\n\n";
}

// Output the whole roster's data
void printRosterData(FootballPlayer Roster[])
{
    // Print each player using the printPlayerData() function
    for (int i = 0; i < ROSTER_COUNT; i++)
        printPlayerData(Roster[i]);
}


// Let the user decide whether or not to save the data
// Returns true if they are saving, false if they are not
bool isUserSavingData()
{
    string sChoiceToSave;
    
    cout << "Would you like to save the data? \n";
    while (true)
    {
        getInput(sChoiceToSave, "string", "Enter Y for yes, N for no: ");
        if (sChoiceToSave == "N" || sChoiceToSave == "n")
            return false;
        else if (sChoiceToSave == "Y" || sChoiceToSave == "y")
            return true;
        else
            cout << sChoiceToSave << " is invalid response. Please try again. ";
    }
}

// Output the Roster data to a file chosen by the user
void saveRosterToFile(FootballPlayer Roster[])
{
    string sFileOutputName;
    
    // Let the user choose the output file
    cout << "If you'd like to save in the existing file, enter 'existing' \n";
    getInput(sFileOutputName, "string", "Enter the name of the file: ");
    cout << endl;
    if (sFileOutputName == "existing")
        sFileOutputName = ROSTER_FILE_NAME;
    
    ofstream fileOutput;
    fileOutput.open(sFileOutputName);
    
    for (int i = 0; i < ROSTER_COUNT; i++)
        fileOutput << Roster[i].sName << " "
                    << Roster[i].sPosition << " "
                    << Roster[i].iTouchdowns << " "
                    << Roster[i].iCatches << " "
                    << Roster[i].iPassingYards << " "
                    << Roster[i].iReceivingYards << " "
                    << Roster[i].iRushingYards << endl;
    fileOutput.close();
    
    cout << sFileOutputName << " has been saved. \n";
}


// -------------------------------------------------------------
// Paste my pre-written functions

// Input function, overloaded for major types of input: strings, integers, floating-point numbers
// It returns the input by updating the reference parameter with the value
// It loops until valid input, based on type of input needed
void getInput(string& s, string type, string prompt) {
    while (true) { // loop to repeat until break on valid input
        try { // start error handling
            cout << prompt;
            getline(cin, s);

            if (!cin) {
                cin.clear();
                cin.ignore(100);
                cout << "Input stream error. Try again. ";
                continue;
            }
            
            return;
        } catch (invalid_argument) {
            cout << "Must input <" << type << ">! Please try again. \n";
        }
    }
}
void getInput(int& i, string type, string prompt) {
    while (true) {
        string str;
        try {
            getInput(str, type, prompt);
            if (type == "int")
                i = stoi(str);
            else {
                cout << "Programmer error. Called getInput() with int referenced but type = '"
                << type << "' instead of 'int' \n";
                throw str;
            }
            return;
        } catch (invalid_argument) {
            cout << "Must input <" << type << ">! Please try again. \n";
        }
    }
}

// Function to return a string in all caps
string sToUpper(string str) {
    string sOutput = "";
    for (int i = 0; i < str.length(); i++)
        sOutput = sOutput + char(toupper(str[i]));
    return sOutput;
}
