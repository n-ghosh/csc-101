/* Lab HW4 Q3
 By Nikhil Ghosh
 For STCC CSC 101
 
 The task is to input Jason's online purchase and output the total cost.
 */

#include <iostream>
#include <iomanip>
using namespace std;
const string projTitle = "Jason's online shopping";

// My function to input a nonnegative number, confirm input is valid, and return the inputted number
double inputPosNum() {
    double d;
    do { // infinite loop, should break when an input is valid
        cin >> d;
        if (!cin) { // Input stream failure causes loop to continue
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nInput invalid. Restarting. \nInput again: ";
            continue;
        } else if (d < 0) { // Negative number causes loop to continue
            cout << "Input invalid: negative number. \nInput again: ";
            continue;
        } else { // Otherwise input is valid
            break;
        }
    } while (true);
    return d;
}

// Main program executed
int main() {
    // Declare variables
    int itemCount;
    double costItem, costShip, costTotal= 0;
    
    // Input number of items purchased
    cout << "Enter the number of items ordered: ";
    itemCount = inputPosNum(); // function to input a non-negative number and return it
    
    // Loop to input costs of each item and update total cost
    for (int i = 1; i <= itemCount; i++) {
        cout << "Enter the cost of item no. " << i << ": $";
        costItem = inputPosNum(); // function to input a non-negative number and return it
        costTotal = costTotal + costItem;
    }

    // Calculate shipping cost based on total cost and item count
    if (costTotal >= 200) {
        costShip = 0;
    } else {
        costShip = itemCount*10.0;
    }

    costTotal = costTotal + costShip; // Add shipping to total cost

    // Output
    cout << endl << fixed << setprecision(2);
    cout << "The shipping and handling fee is: $" << costShip << endl;
    cout << "The billing amount is: $" << costTotal << "\n\n";
    return 0;
}
