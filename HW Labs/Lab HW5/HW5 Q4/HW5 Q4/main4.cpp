/* Lab HW5 Q4
 By Nikhil Ghosh
 For STCC CSC 101
 
 Description: count the vowels in a given string, and test my program.
 I have little experience with writing functions to test programs, and I'm not sure if this assignment wants a specific way of doing so.
 */

#include <iostream>
using namespace std;

// Declare functions
void vowelsProgram();
int countVowels(string, int&, int&, int&, int&, int&, int&);
void testProgram();
void testVowelsFunction(string, int);

int main()
{
    // Output an introductory description.
    cout << "This program reads a string and outputs the number of lowercase vowels in it. \n\n";
    
    // Loop to run program as many times as user decides.
    do {
        // Input user decision
        string choice;
        cout << "To run this program, enter R. \n"
        << "To run the test on this program, enter T. \n"
        << "To terminate this program, enter any other key. \n";
        cin >> choice;
        
        // Interpret user decision and execute
        if (choice == "R" || choice == "r") {
            vowelsProgram();
        } else if (choice == "T" || choice == "t") {
            testProgram();
        }
        else break;
    } while(true); // Infinite loop, breaks on user input of any key besides R/r or T/t

    return 0;
}

// Function for primary program to input string and output vowel count
void vowelsProgram()
{
    // Declare variables
    string str;
    int countAll, a =0, e =0, i =0, o =0, u =0, y =0; // counts for each vowel
    
    // Get input of string
    cout << "Input string. \n";
    cin.ignore();
    getline(cin, str);
    
    // Process string
    countAll = countVowels(str, a, e, i, o, u, y);
    
    // Output number of each vowel and sum of all vowels
    cout << "The number of a's: " << a << endl;
    cout << "The number of e's: " << e << endl;
    cout << "The number of i's: " << i << endl;
    cout << "The number of o's: " << o << endl;
    cout << "The number of u's: " << u << endl;
    cout << "The number of y's: " << y << endl;
    cout << "Total lowercase vowels: " << countAll << "\n\n";
}

// Function to return the number of lowercase vowels in given string and update the referenced variables that count individual vowels
int countVowels(string str, int& a, int& e, int& i, int& o, int& u, int& y)
{
    // Loop through the string's characters and check if each is a lowercase vowel
    for (int j=0; j < str.length(); j++)
    {
        switch (str.at(j))
        {
            case 'a':
                a++;
                break;
            case 'e':
                e++;
                break;
            case 'i':
                i++;
                break;
            case 'o':
                o++;
                break;
            case 'u':
                u++;
                break;
            case 'y':
                y++;
                break;
        }
    }
    return a + e + i + o + u + y; // return sum of all vowels counted
}


// Function to test primary program. I am heavily improvising and I scanned the chapter on arrays to help.
void testProgram()
{
    // Declare my own strings to test
    string testStrings[] = {"Lorem ipsum dolor sit amet",
    "abcdefghijklmnopqrstuvwxyz\nABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\n`-=[];',./~!@#$%^&*()_+{}|:<>?,",
    "a", "bzAY. @", "e", "i", "o", "u", "y"};
    // Declare the number of vowels for each string above, with matching array indices
    int testsVowels[] = {9, 6, 1, 0, 1, 1, 1, 1, 1};
    
    // Loop through my array of tests and run my supporting test function on each
    for (int i =0; i< 8; i++) {
        cout << "Test " << i+1 << ". String: " << testStrings[i] << endl;
        testVowelsFunction(testStrings[i], testsVowels[i]); // using another function just makes code cleaner
    }
    cout << endl;
}

// Function to support test function for cleaner code. This actually calls the vowel program to run the given string, compares its return value against my expected return value, and outputs the result.
void testVowelsFunction(string str, int v)
{
    int a =0, e =0, i =0, o =0, u =0, y =0; // for the individual vowel counters, unused here but the function requires them as reference parameters
    int ret = countVowels(str, a, e, i, o, u, y); // call the function and store the return value
    if (ret == v) {
        cout << "Passed. Program returned " << ret << " vowels. \n";
    } else {
        cout << "\tFAILED! Program returned " << ret << " vowels, not " << v << "\n\n";
    }
}
