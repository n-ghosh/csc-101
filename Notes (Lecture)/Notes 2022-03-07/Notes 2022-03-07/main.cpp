/*  Notes 2022-03-07
//
//  Created by Nikhil Ghosh on 2022-03-07.
//
 Example program: Girl Scout cookies.
 Input: # volunteers, price,
 Calculate: boxes sold, money total
 
*/

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    // Declare variables
    string name, maxName;
    int volunteers, boxesTotal = 0, boxesEachV, max=0;
    double price, salesTotal;

    // Input variables for all situation
    cout << "Input number of volunteers: ";
    cin >> volunteers;
    cout << "Input price per box: $";
    cin >> price;
    
    // Loop to input variables for each volunteer
    for (int c=1; c <= volunteers; c++) {
        cout << "Input name of volunteer " << c << ": ";
        cin >> name;
        cout << "Input number of boxes for " << name << ": ";
        cin >> boxesEachV;
        // Check for max
        if (boxesEachV > max) {
            max = boxesEachV;
            maxName = name;
        }
        boxesTotal += boxesEachV;
    }
    
    
    // Calc-Output
    cout << fixed << setprecision(2) << endl;
    salesTotal = boxesTotal * price;
    cout << left << setw(25) << setfill('.') << "Total Boxes Sold:" << right << setw(7) << boxesTotal << endl;
    cout << left << setw(25) << "Total Sales: $" << right << setw(7) << salesTotal << endl;
    cout << left << setw(25) << "Avg Sales per V: $" << right << setw(7) << salesTotal / volunteers << endl;
    cout << left << "Congratulations to: " << maxName << " for selling " << max << " boxes!" << endl;
    
    cout << "\n\n";
    return 0;
}
