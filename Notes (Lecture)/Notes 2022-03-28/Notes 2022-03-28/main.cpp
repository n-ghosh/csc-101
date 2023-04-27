/* Notes 2022-03-28
 Local and global variables
 Example: paycheck
 
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Global variables
const double BasePay = 20;

// Function reference declarators
double paycheck(double); // can just say "double", don't need to invent a variable name
double taxes(double);

enum Select {A, B, C, D};
Select func();

int main() {
    double Hours, PayGross, Tax, PayTotal;
    
    // Get number of hours
    cout << "Enter hours worked this week: ";
    cin >> Hours;
    /* Get base pay
    cout << "Enter base pay rate: ";
    cin >> BasePay; */

    // Calculate pay
    PayGross = paycheck(Hours);
    
    // Incl taxes
    Tax = taxes(PayGross);
    
    PayTotal = PayGross - Tax;
    
    // Output
    cout << fixed << setprecision(2);
    cout << "Gross Pay is: $" << PayGross << endl;
    cout << "Total Pay is: $" << PayTotal << endl;
    
    
    /* My playing with enumerated types
    Select mySelect = A;
    mySelect = static_cast<Select>(1);
    mySelect = (Select)(2);
    int i = static_cast<int>(D);
    i = (int)(C);
    
    if (i == mySelect)
        cout << mySelect << " Hello, World!\n" << i << endl;
    
    for (int j = 0; j < 4; j++) {
        mySelect = (Select)(j);
        cout << mySelect << endl;
    }
    cout << endl;
    
    for (Select s = A; s <= D; s = (Select)((int)(s)+1)) {
        // code
        cout << s << endl;
    }
    cout << endl;
    
    mySelect = func();
    */
    
    cout << "\n\n";
    return 0;
}

// Function to return pay amount
double paycheck(double h)
{
    double p;
    p = h * BasePay;
    if (h>40)
        p += (h-40)*BasePay*1.5;
    return p;
}

double taxes(double p) {
    return p * (0.2 + 0.0625);
}

Select func(){
    Select second = A;
    cout << second << endl;
    return second;
}
