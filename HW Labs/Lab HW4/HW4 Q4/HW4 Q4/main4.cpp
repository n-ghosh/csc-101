/* Lab HW4 Q4
 By Nikhil Ghosh
 For STCC CSC 101
 
 The task is to take input of a telephone number with letters, convert it to a telephone number in digits, and repeat as many times as the user wants.

 */

#include <iostream>
using namespace std;


// Function to return a string of numbers converted from input string of lettered telephone number
string strToTeleNumber(string phoneNum) {
    // Loop through the first 7 valid characters in the string. The counter will decrement for invalid characters
    for (int j=0; j<phoneNum.length() && j<7; j++) {
        // If the character is already a number 0-9, we can accept it and continue without conversion.
        if (phoneNum[j] >= '0' && phoneNum[j] <= '9') { // Chars can be compared like integers
            continue;
        }
        // If the character is a letter from A-R, we can use ASCII values to directly convert from the input letter to the output number. We only need to check if it's uppercase or lowercase.
        // This is because we know that until the letter S, there is a consistent "encryption" pattern of 3 letters to 1 number. This limits search inefficiency.
        else if (phoneNum[j] >= 'A' && phoneNum[j] <= 'R') {
            phoneNum[j] = ( (phoneNum[j]+1) /3) + 28; // Example, 'A': ( (65+1) /3) + 28 = 50 =>'2'. So the program switches "A" to "2" in the string
            continue;
        } else if (phoneNum[j] >= 'a' && phoneNum[j] <= 'r') {
            phoneNum[j] = ( (phoneNum[j]+2) /3) + 17; // Example, 'r': ( (114+2) /3) + 17 = 55 => '7'. So the program switches "r" to "7" in the string
            continue;
        }
        // Otherwise, we can use a linear search for letters S-Z and manual conversion.
        else switch (phoneNum[j]) {
            case 'S': case 's':
                phoneNum[j] = '7';
                break;
            case 'T': case 't': case 'U': case 'u': case 'V': case 'v':
                phoneNum[j] = '8';
                break;
            case 'W': case 'w': case 'X': case 'x': case 'Y': case 'y': case 'Z': case 'z':
                phoneNum[j] = '9';
                break;
            // If it's not a letter from S-Z, then it's a ' ', '-', or other symbol, and the program should erase it.
            default:
                phoneNum.erase(j, 1);
                // If the string has less than 7 characters after erasing 1, then it's too short and the process should end.
                if (phoneNum.length() < j+1) {
                    return phoneNum;
                }
                j--; // prevent the counter from skipping the next letter, which moved position because of .erase()
        }
    }
    return phoneNum;
}

int main() {
    // Declare data
    string phoneNum;
    char runBool; // input for continuing or ending program
    bool first = true; // flag for first iteration through loop
    
    while (cin) { // infinite loop, should break at user decision point
        // Input user's decision to run the program or not
        if (first) { // if this is the first iteration through loop, give a description
            cout << "This program converts telephone numbers in letters to telephone numbers in digits. \n\n" << "Input Y/y to convert your first telephone number. \n";
            first = false; // switch the flag to prevent this from executing again
        } else { // otherwise, be more concise
            cout << "Input Y/y to process another telephone number. \n";
        }
        cout << "Input any other key to terminate program. \n";
        cin >> runBool;
        if (runBool != 'Y' && runBool != 'y') { // if any other key, break the program loop
            break;
        }
        cin.ignore(100, '\n'); // ignores any extra characters the user inputted (ie "yes" instead of 'y'). Also fixes a minor error that using "getline()" after ">>" can cause

        // Input Lettered phone number
        cout << "\nInput telephone number with letters: ";
        getline(cin, phoneNum); // store it in variable phoneNum

        // Convert input letters to digits, and delete extra symbols
        phoneNum = strToTeleNumber(phoneNum); // see function above
        
        if (phoneNum.length() < 7) { // If the string is too short, restart program
            cout << "Error: not enough letters or numbers to finish 7 digits. \nProcessed: '"
            <<phoneNum<< "'. \n\n";
            continue;
        }
        phoneNum.erase(7); // Erase any extra characters past the 7 numbers
        phoneNum.insert(3, "-"); // Insert hyphen after 3rd number
            
        // Output
        cout << "\nThe corresponding telephone number is: " << phoneNum << "\n\n";
    }
    cout << "\nThank you for using this program. \n\n";
    return 0;
}
