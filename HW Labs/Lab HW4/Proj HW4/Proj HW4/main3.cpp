//
//  main.cpp
//  Proj HW4
//
//  Created by Nikhil Ghosh on 2022-03-12.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    /* -------------------------------
                    Q3
     --------------------------------- */
    double totalCost = 0;
    int itemCount;
    
    // Input itemCount
    // Input function: input(var, var limits, string) {}
    cout << "Jason, input number of items purchased: ";
    cin >> itemCount;
    while (itemCount<0 || itemCount>5) {
        cout << "Input invalid. Input an int between 0 and 5: ";
        cin >> itemCount;
    }
    
    // For each item, input itemPrice
    for (int i=1; i <= itemCount; i++) {
        double itemPrice;
        cout << "Jason, input cost of item #" << i << ": $";
        cin >> itemPrice;
        while (itemPrice < 0) {
            cout << "Input invalid. Input a non-negative double: $";
            cin >> itemPrice;
        }
        totalCost = totalCost + itemPrice;
    }
    
    //
    cout << endl << fixed << setprecision(2);
    if (totalCost > 200)
        cout << "Shipping is free. \n";
    else {
        cout << "Shipping costs: $" << itemCount*10.0 << "\n";
        totalCost += itemCount*10.0;
    }
    cout << "Total is: $" << totalCost << "\n\n";

    cout << "Hello, World!\n";
    return 0;
}
