/* Project Name
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description:
 */

#include <iostream>
using namespace std;

// Define constants
const char PROJ_TITLE[] = "Template";
const string INPUT_TYPES[] = {"string", "int", "double", "number"};

// Declare structures


// Declare functions
void getInput(string&, string, string);
void getInput(int&, string, string);
void getInput(double&, string, string);
void getInput(string&, string);
void getInput(string&);
string sToUpper(string);
bool runProgramAgain();

void testInput(int&, string, string);

// -------------------------------------------------------------
// Main program
int main() {
    cout << "Welcome to " << PROJ_TITLE << "\n\n";

    // Main code here
    string s;
    getInput(s, "string", "Enter a string with lowercase: ");
    s = sToUpper(s);
    cout << "In main() after toUpper, s = " << s << endl;
    
    
    cout << "Thank you for using " << PROJ_TITLE << "\n\n";
    return 0;
}


// -------------------------------------------------------------
// Add functions here



// -------------------------------------------------------------
// Pre-written functions

// Input function, overloaded for major types of input: strings, integers, floating-point numbers
// Returns the input by updating the reference parameter 
// It validates input based on the type parameter, looping until valid
void getInput(string& s, string type, string prompt) {
    while (true) {
        try {
            cout << prompt;
            getline(cin, s);

            if (!cin) {
                cin.clear();
                cin.ignore(100);
                cout << "Input stream error. Please try again. ";
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
void getInput(double& d, string type, string prompt) {
    while (true) {
        string str;
        try {
            getInput(str, type, prompt);
            if (type == "double" || type == "number")
                d = stod(str);
            else if (type == "float")
                d = stof(str);
            else if (type == "int")
                d = stoi(str);
            return;
        } catch (invalid_argument) {
            cout << "Must input <" << type << ">! Please try again. \n";
        }
    }
}
void getInput(string& s, string prompt) {
    getInput(s, "string", prompt);
}
void getInput(string& s) {
    getInput(s, "string", "Enter a string: ");
}
void testInput(int& i, string type, string prompt) {
    while (true) {
        string str;
        try {
            getInput(str, type, prompt);
            if (type == "int") {
                i = stoi(str);
            }
            /*
            else if (type == "char") {
                if (str.length() != 1) {
                    cout << "Expected one character. " << str << " too long. Please try again. \n";
                    continue;
                }
                char c = str[0];
                i = c;
            }
            else if (type == "bool") {
                for (char& c : str) {
                    c = toupper(c);
                }
                if (str == "TRUE")
                    i = true;
                else if (str == "FALSE")
                    i = false;
                
            } */
            return;
        } catch (std::invalid_argument) {
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

// Function to return boolean for user decision to run program again
bool runProgramAgain() {
    cout << "Do you want to run this program again? \n";
    string s;
    getInput(s, "string", "Enter Y to continue or any other key to end program: ");
    cout << endl;
    if (s != "Y" && s != "y") {
        cout << "You said: " << s << "\nEnding program. \n";
        return false;
    }
    return true;
}

