/* Lab HW8 Q2
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: perform restaurant functions: get a menu from a file, show it to the user, get user's order, and print user's bill
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Define constants
const char PROJ_TITLE[] = "Zee's Restaurant";
const char MENU_FILE_NAME[] = "Menu.txt";
const short MENU_LENGTH = 8;
const short ORDER_LIMIT = 8;

// Define structures
struct menuItemType
{
    string food;
    double price;
};


// Declare functions
void getData(menuItemType[]);
void printMenu(menuItemType[]);
void getOrder(menuItemType[], int&, menuItemType[]);
void printCheck(menuItemType[], int);

void getInput(string&, string, string);
void getInput(int&, string, string);

// Main program
int main() {
    cout << "Welcome to " << PROJ_TITLE << "\n\n";
    
    // Declare variables
    menuItemType menuList[MENU_LENGTH]; // array for the menu (all items)
    menuItemType menuOrder[ORDER_LIMIT]; // array for the items ordered by the user
    int iOrderSize; // number of items ordered by the user
    
    // Get the menu data from the file and store it in the referenced list
    getData(menuList);
    
    // Print the menu and explain how to select items
    printMenu(menuList);
    
    // Get user order
    getOrder(menuOrder, iOrderSize, menuList);
    
    // Print bill
    printCheck(menuOrder, iOrderSize);
    
    return 0;
}


// -------------------------------------------------------------
// Define functions

// Get the menu data from the file
// Return it through the reference parameter menuList
void getData(menuItemType menuList[])
{
    ifstream fileMenu;
    fileMenu.open(MENU_FILE_NAME);
    
    // Loop to repeat for every item in the file
    for (int i = 0; i < MENU_LENGTH && !fileMenu.eof(); i++)
    {
        // Get the item's food name and price
        getline(fileMenu, menuList[i].food); // use getline() because some items have multiple words
        fileMenu >> menuList[i].price;
        fileMenu.ignore(); // need .ignore() to use getline() after >>, because >> leaves a '\n' key in the stream
    }
    fileMenu.close();
}

// Print the menu and explain how to select items
void printMenu(menuItemType menuList[])
{
    cout << fixed << setprecision(2);
    cout << "------Today's Menu------ \n";
    
    // Print each item and its price
    for (int i = 0; i < MENU_LENGTH; i++)
    {
        cout << i+1 << ": " << setw(15) << left << menuList[i].food
        << " $" << menuList[i].price << endl;
    }
    cout << "------------------------ \n"
    << "Select an item using its item number. You can make up to "
    << ORDER_LIMIT << " single order selections. \n\n";
}

// Get the user's order
// Return it by updating the reference parameters menuOrder and iOrderSize
void getOrder(menuItemType menuOrder[], int& iOrderSize, menuItemType menuList[])
{
    string sIsOrdering;
    int iOrderItem;

    cout << "Do you want to make a selection? ";
    
    // Loop to repeat up to the order limit
    for (iOrderSize = 0; iOrderSize < ORDER_LIMIT; iOrderSize++)
    {
        // Get user's choice to order
        getInput(sIsOrdering, "string", "Enter Y for yes, N for no: ");
        
        // Check the user's choice
        if (sIsOrdering == "N" || sIsOrdering == "n")
            break;
        else if (sIsOrdering == "Y" || sIsOrdering == "y")
        {
            // Get user's menu selection
            getInput(iOrderItem, "int", "Enter item number: ");
            
            // Validate selection
            if (iOrderItem >= 1 && iOrderItem <= 8)
            { // If valid, Add it to their total order
                menuOrder[iOrderSize].food = menuList[iOrderItem-1].food;
                menuOrder[iOrderSize].price = menuList[iOrderItem-1].price;
                
                // Check if the user can order another item
                if (iOrderSize + 1 < ORDER_LIMIT)
                    // If so, invite them to
                    cout << "One " << menuOrder[iOrderSize].food << " coming right up! \n\n"
                    << "Would you like to order another item? ";
                else // If not, thank them for their large purchase
                    cout << "Thank you for ordering " << iOrderSize << " items! We appreciate your business. \n";
            } else
            { // If the selection is not valid, explain and restart the loop
                cout << iOrderItem << " is invalid item number.\nPlease try again: ";
                iOrderSize--;
            }
        } else
        { // If choise is neither Yes nor No, explain and restart the loop
            cout << "Expected Y/y/N/n. Did not accept " << sIsOrdering
            << "\nPlease try again. ";
            iOrderSize--;
        }
    }
    cout << endl;
    
    // Print a cute message based on whether or not they ordered anything
    if (iOrderSize > 0)
        cout << "Enjoy! \n";
    else
        cout << "We hope you come back and try our food! \n";
}

// Print bill
void printCheck(menuItemType menuOrder[], int iOrderSize)
{
    double dOrderTotal = 0, dOrderTax;
    
    cout << setfill('.');
    cout << "-------------------------------------- \n" << PROJ_TITLE
    << "\nCustomer Bill \n\n";
    
    // For each item ordered, print the name and price
    for (int i = 0; i < iOrderSize; i++)
    {
        cout << setw(18) << left << menuOrder[i].food
        << " $" << menuOrder[i].price << endl;
        dOrderTotal = dOrderTotal + menuOrder[i].price;
    }
    // Calculate the tax and the total
    dOrderTax = dOrderTotal * 0.05;
    dOrderTotal = dOrderTotal + dOrderTax;

    // Output to the user
    cout << setw(18) << left << "Tax " << " $" << dOrderTax << endl;
    cout << setw(18) << left << "Amount Due " << " $" << dOrderTotal << endl;
    
    cout << "-------------------------------------- \n"
        << "\nThank you for coming to " << PROJ_TITLE << "\n\n";
}

// -------------------------------------------------------------
// My own pre-defined functions

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
