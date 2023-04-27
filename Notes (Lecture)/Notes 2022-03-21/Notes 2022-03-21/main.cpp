//  Notes 2022-03-21
// Intro to Functions
//  main.cpp
//
//  Created by Nikhil Ghosh on 2022-03-21.
//

#include <iostream>
using namespace std;

// Return uppercase of character inputted
char CapChar(char c) {
    return static_cast<char>(toupper(c));
}

int main() {
    char c;
    cout << "Input a character: ";
    cin >> c;
    cout << "toUpper! " << CapChar(c) << endl;
    
    /*
    double a, b, x;
    cout << "Enter 3 numbers: ";
    cin >> a >> b >> x;
    double n = Largest(a, b, x);
    cout << "Largest number is: " << n << endl;
    */
    
    /* int cs = ClassSize();
    cout << cs << endl; */
    
    // Third();
    
    /*
    int x, y;
    cout << "Input x, y: ";
    cin >> x >> y;
    cout << Larger(x, y); // can put function call in a statement
    */
    
    // Hello(); // function call
    
    cout << "\n\n";
    return 0;
}
// Return largest of 3 numbers
double Largest(double x, double y, double z) {
    // return Larger(x, Larger(y, z));
    if (x>y && x>z) return x;
    else if (y>x & y>z) return y;
    else return z;
}

// Function to return class size. No parameters
int ClassSize() {
    int s;
    cout << "Input class size: ";
    cin >> s;
    return s;
}

// Third function. No return and no values
void Third() {
    cout << "We're inside the third function. \n";
}

//
int Larger(int x, int y) {
    if (x > y)
        return x;
    else // line is redundant
        return y;
}


void Hello() {
    cout << "Hello, World! \n";
}
