/* Notes 2022-05-09
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: intro to Classes, Abstract Data Types
 */

#include <iostream>
using namespace std;

const char PROJ_TITLE[] = "Template";
const string INPUT_TYPES[] = {"string", "int", "double", "number"};

// Declare Classes
class RectangleType {
private:
    double width;
    double length;
public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const; // not sure how the constant works ??
    double getLength();
    double getArea();
};


// Declare functions
void storeNotes();
void getInput(string&, string, string);
void getInput(int&, string, string);
void getInput(double&, string, string);

// -------------------------------------------------------------
// Main program
int main() {
    cout << "Welcome to " << PROJ_TITLE << "\n\n";

    RectangleType Boxes[10];
    
    Boxes[0].setWidth(5);
    Boxes[0].setLength(2);
    Boxes[1].setLength(15);
    Boxes[1].setWidth(15);
    
    for (int i = 0; i < 2; i++) {
        cout << "Box " << i+1 << " Width: " << Boxes[i].getWidth() << endl;
        cout << "Box " << i+1 << " Length: " << Boxes[i].getLength() << endl;
        cout << "Box " << i+1 << " Area: " << Boxes[i].getArea() << endl;
    }

    storeNotes();
    cout << "Thank you for using " << PROJ_TITLE << "\n\n";
    return 0;
}


// -------------------------------------------------------------
// Add functions here

// Define Rectangle functions
void RectangleType::setWidth(double d) {
    width = d;
}
// Rectangle's setLength
void RectangleType::setLength(double d) {
    length = d;
}
// Rectangle's getWidth
double RectangleType::getWidth() const { // constant means ?? 
    return width;
}
double RectangleType::getLength() {
    return length;
}
double RectangleType::getArea() {
    return length * width;
}


/*
class InsectType {
public:
    double Length;
    double Weight;
    int legs;
};

class MyClassType {
public:
    string sName;
    MyClassType();
};
*/

void storeNotes() {
    RectangleType DDBox; // define an instance of RectangleType
    RectangleType PizzaBox;

    DDBox.setWidth(5);
    DDBox.setLength(2);
    PizzaBox.setLength(15);
    PizzaBox.setWidth(15);
    
    cout << " Width: " << DDBox.getWidth() << endl;
    cout << " Length: " << DDBox.getLength() << endl;
    cout << " Area: " << DDBox.getArea() << endl;
    

    /*
    InsectType Mosquito;
    InsectType Horsefly;

    MyClassType MyObj;
    MyClassType MyArr[10];
    */
}


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

