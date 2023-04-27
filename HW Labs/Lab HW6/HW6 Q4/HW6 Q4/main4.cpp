/* Lab HW6 Q4
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: remove all vowels from a string
 */

#include <iostream>
using namespace std;

// Declare constants 
const char DESCRIPTION[] = "This program removes all vowels from a string. ";
const char VOWELS[] = "AEIOUY"; // all vowels in the uppercase alphabet

// Declare functions
string substr(string);
bool isVowel(char);
void testProgram();

// Main program
int main() {
    // Declare variables
    string str;
    
    // Get input of string
    cout << DESCRIPTION << "\n\nInput string: ";
    getline(cin, str);
    
    // Process string
    str = substr(str);
    
    // Output
    cout << "Without vowels: " << str << "\n\n";
    return 0;
}


// -------------------------------------------------------------

// Function to return a string with all vowels removed from the given string
string substr(string str)
{
    for (int i = 0; i < str.length(); i++) { // for every character in the string
        if (isVowel(str[i])) { // check if it's a vowel
            str.erase(i, 1); // if so, erase it, and
            i--; // decrement the loop counter to continue with the next character, which moved position
        }
    }
    return str;
}

// Function to return boolean for whether the given character is a vowel
bool isVowel(char c)
{
    for (char v : VOWELS) { // for each vowel in the uppercase alphabet
        if (toupper(c) == v) { // compare it to the uppercase of the input character
            return true; // return true if they're equal
        }
    }
    return false; // after looping, if nothing returned true, return false
}

// Function to test my program. I'm just testing one string many times - for some reason, the program gave me different outputs for what I thought was the same input. Those odd output included unfamiliar symbols or duplicated text
void testProgram() {
    char c = 'a';
    int count = 0;
    string str1 = "Hello there, World!", str2 = "Hll thr, Wrld!";
    for (int i = 0; i < 100'000; i++) {
        string s = substr(str1);
        if (s != str2) {
            count++;
            cout << "Failed. Expected " + str2 + " Instead: " + s << endl;
        }
        if (!isVowel(c)) {
            count++;
        }
    }
    cout << "In 100,000 repetitions, " << count << " errors. \n";
}
