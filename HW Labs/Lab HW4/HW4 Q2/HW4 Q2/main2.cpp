/* Lab HW4 Q2
 By Nikhil Ghosh
 For STCC CSC 101
 
 The task is to use for loops to perform 6 steps.
 This program also expirements with using functions. 
*/

#include <iostream>
using namespace std;

// ------------------- My Functions -------------------

// Step 3: Output sum of even numbers between firstNum and secondNum
void step3(int firstNum, int secondNum) {
    // Declare variables
    int firstIt, sumEven = 0; // firstIt for first odd/even number for iteration
    // Assign firstIt to first even number after firstNum
    firstIt = firstNum + 1; // start from the first number after firstNum
    if (firstIt % 2 == 1) { // if it's odd, the next number must be even.
        firstIt++;
    }
    // Loop from firstIt through every second number (which must also be even) until secondNum, updating the total sum
    for (int i= firstIt; i < secondNum; i= i+2) { // if the firstIt is already > secondNum, the loop won't run
        sumEven = sumEven + i;
    }
    cout << "3: Sum of all even numbers between firstNum and secondNum: " << sumEven << endl;
}

// Step 4: Output all numbers and their squares, from 1 to 10
void step4() {
    cout << "4: All numbers and their squares, from 1 to 10: ";
    // Loop from 1 to 10, outputting each number and its square (n*n)
    for (int i= 1; i<= 10; i++) {
        cout << i << " " << i*i << "    "; // output: 1 1    2 4    3 9...
    }
    cout << endl;
}

// Step 6: Output all uppercase letters
void step6() {
    cout << "6: All uppercase letters: ";
    // Loop from 'A' to 'Z' char values, outputting each char.
    for (char c = 'A'; c <= 'Z'; c++) { // a char variable can be used as a loop counter
        cout << c << " "; // output: A B C...
    }
}


// ------------------- Main Program -------------------
int main() {
    // Declare variables
    int firstNum, secondNum;
    int firstIt, sumOddSquare=0; // firstIt for the first number used for odd/even iteration
    
// Step 1: prompt the user to input two integers, firstNum and secondNum, where firstNum must be smaller than secondNum
    for (; true;) { // Infinite loop, should break on first valid input
        // Get input
        cout << "1: Input two integers, firstNum and secondNum, such that firstNum < secondNum. \n";
        cout << "  firstNum: ";
        cin >> firstNum;
        cout << "  secondNum: ";
        cin >> secondNum;
        cout << endl;

        // Validate input to decide to continue or break the loop
        if (!cin) { // If input stream error, restart loop
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError, input stream failure. Try again. \n";
            continue;
        } else if (firstNum >= secondNum) { // If firstnum < secondNum requirement is failed, continue loop
            cout << "Error, firstNum >= secondNum. Try again. \n";
            continue;
        } else { // Otherwise input is good, break loop
            break;
        }
    }
    
    
// Step 2: Output all odd numbers between firstNum and secondNum.
    // Initialize firstIt to first odd number after firstNum
    firstIt = firstNum + 1; // start with the first number after firstNum
    if (firstIt % 2 == 0) { // if it's even, the next number must be odd
        firstIt++;
    }
    cout << "2: All odd numbers between firstNum and secondNum: ";
    // Loop from firstIt through every second number (which must also be odd) until secondNum, outputting each number
    for (int i= firstIt; i < secondNum; i = i+2) { // if the firstIt is already > secondNum, the loop won't run
        cout << i << " ";
        sumOddSquare = sumOddSquare + (i*i); // This is for Step 5, the sum of squares of odd numbers
    }
    cout << endl;
    
// Step 3: Output sum of even numbers between firstNum and secondNum
    step3(firstNum, secondNum); // I wrote a function above

// Step 4: Output all numbers and their squares, from 1 to 10
    step4(); // I wrote a function above
    
// Step 5: Output sum of squares of odd numbers between firstNum and secondNum.
    // Writing a new loop would be inefficient, because I'm already iterating through the odd numbers in Step 2
    /*for (int i= firstNum+1; i< secondNum; i++) {
        if (i % 2 == 1) {
            sumOddSquare = sumOddSquare + (i*i);
        }
     }*/
    cout << "5: Sum of the squares of the odd numbers between firstNum and secondNum: " << sumOddSquare << endl;
    
// Step 6: Output all uppercase letters
    step6(); // I wrote a function above.
    
    cout << "\n\n";
    return 0;
}
