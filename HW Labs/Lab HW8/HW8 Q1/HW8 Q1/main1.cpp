/* Lab HW8 Q1
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: simple practice with structures. Get input of a computer's data, store it, and output it.
 */

// Include libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Declare structure
struct computerType // the generic computer to be used, with the following data
{
    string manufacturer;
    string modelType;
    string processorType;
    int ram;
    int hardDriveSize;
    int yearBuilt;
    double price;
};

// Declare functions
computerType getComputer();
void printComputer(computerType);

void getInput(string&, string, string);
void getInput(int&, string, string);
void getInput(double&, string, string);

// Main program
int main()
{
    // Declare variable for the computer and initialize with input from the console
    computerType computer1 = getComputer();
    
    // Output the computer to the console
    printComputer(computer1);

    return 0;
}

// -------------------------------------------------------------
// Define functions

// Get input of a computer from the console
// Return the computer inputted
computerType getComputer()
{
    computerType compInputted;
    // Get input of each computer variable, using my getInput() function
    getInput(compInputted.manufacturer, "string", "Enter the name of the manufacturer: ");
    getInput(compInputted.modelType, "string", "Enter the model of the computer: ");
    getInput(compInputted.processorType, "int", "Enter the processor type: ");
    getInput(compInputted.ram, "int", "Enter the size of the RAM (in GB): ");
    getInput(compInputted.hardDriveSize, "int", "Enter the size of the hard drive (in GB): ");
    getInput(compInputted.yearBuilt, "int", "Enter the year the computer was built: ");
    getInput(compInputted.price, "double", "Enter the price: ");
    cout << endl;

    return compInputted;
}

// Output the computer to the console
void printComputer(computerType comp)
{
    cout << fixed << setprecision(2);
    // Print each computer variable
    cout << "Manufacturer: " << comp.manufacturer << endl;
    cout << "Model: " << comp.modelType << endl;
    cout << "Processor: " << comp.processorType << endl;
    cout << "RAM: " << comp.ram << " GB \n";
    cout << "Hard Drive Size: " << comp.hardDriveSize << " GB \n";
    cout << "Year Built: " << comp.yearBuilt << endl;
    cout << "Price: $" << comp.price << "\n\n";
}


// -------------------------------------------------------------
// Paste my pre-written functions

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
