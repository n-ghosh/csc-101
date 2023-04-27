/* Notes 2022-05-02 class
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description:
 */

#include <iostream>
#include <iomanip>
using namespace std;

const char PROJ_TITLE[] = "Template";
const string INPUT_TYPES[] = {"string", "int", "double", "float", "char"};

// Declare structures
struct Clorox // can name them whatever
{
    char Name[20];
    int Age;
    char Phone[20];
    double Salary;
};

// Declare functions
void getArrInput(Clorox[], int);
void displayEmployees(Clorox[], int);

void getInput(string, string, string&);
void getInput(string, string, int&);
void getInput(string, string, double&);
void getInput(string, string, char[], int);
void getInput(string&);
void getInput(string, string&);


// Main program
int main() {
    cout << "Welcome to " << PROJ_TITLE << "\n\n";
    
    int S;
    getInput("Enter number of employees: ", "int", S);
    cin.ignore();
    
    Clorox employees[S];
    getArrInput(employees, S);

    displayEmployees(employees, S);
    
    
    cout << "Thank you for using " << PROJ_TITLE << "\n\n";
    return 0;
}

// -------------------------------------------------------------
// Add functions here


void getArrInput(Clorox employees[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "For employee number " << (i+1) << ": " << endl;
        getInput("\tName: ", "string",employees[i].Name, 20);
        getInput("\tAge: ", "int", employees[i].Age);
        cin.ignore();
        getInput("\tPhone: ", "string", employees[i].Phone, 20);
        getInput("\tSalary: ", "double", employees[i].Salary);
        cin.ignore();
    }
}

void displayEmployees(Clorox employees[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(20) << left << employees[i].Name
        << setw(7) << right << employees[i].Salary << endl;
    }
}


// -------------------------------------------------------------
// Pre-written functions


// Input function, overloaded, for major types of input
void getInput(string prompt, string type, string& s) {
    while (true) {
        try {
            cout << prompt;
            getline(cin, s);
            
            if (type != "string") {
                // what?
            }
            if (!cin) {
                cin.clear();
                cin.ignore(100);
                cout << "Input stream error. Try again. ";
                continue;
            }
            
            return;
        } catch (error_code) {
            cout << "error! " << endl;
        }
    }
}
void getInput(string prompt, string type, int& i) {
    while (true) {
        try {
            cout << prompt;
            cin >> i;
            
            if (type == "char") {
                i = char(i);
            }
            else if (type == "bool") {
                i = bool(i);
            }
            else if (type != "int") {
                // what?
            }
            
            if (!cin) {
                cin.clear();
                cin.ignore(100);
                cout << "Must input an integer. Try again. ";
                continue;
            }
            
            return;
        } catch (int x) {
            cout << "error! " << endl;
        }
    }
}
void getInput(string prompt, string type, double& d) {
    if (type != "double" && type != "float" && type != "int")
        return;
    while (true) {
        try {
            cout << prompt;
            cin >> d;
            
            if (type == "int")
                d = int(d);
            
            if (!cin) {
                cin.clear();
                cin.ignore(100);
                cout << "Must input a number. Try again. ";
                continue;
            }
            
            return;
        } catch (double x) {
            cout << "error! " << endl;
        }
    }
}
void getInput(string prompt, string type, char cArr[], int size) {
    while (true) {
        try {
            cout << prompt;
            cin.getline(cArr, size);
            
            if (type != "string") {
                // what?
            }
            if (!cin) {
                cin.clear();
                cin.ignore(100);
                cout << "Input stream error. Try again. ";
                continue;
            }
            
            return;
        } catch (error_code) {
            cout << "error! " << endl;
        }
    }
}

void getInput(string& s) {
    getInput("Enter a string: ", "string", s);
}
void getInput(string prompt, string& s) {
    getInput(prompt, "string", s);
}
