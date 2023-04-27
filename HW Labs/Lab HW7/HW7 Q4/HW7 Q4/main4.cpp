/* Lab HW7 Q4
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: based on the Magic Squares puzzle. Generate a random 3x3 square of integers 1-9 placed in random positions, and check if it's a Magic Square. Repeat a large number of times and count how many Magic Squares are generated.
 
 There are 8 Magic Square configurations out of roughly 360,000 possible configurations.
 For a truly random square generator, the ratio should be
    1 Magic Square : 45,000 random Squares
    ~or~
    22 Magic Squares : 1,000,000 random Squares

 */

#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

// Declare constants
const char PROJ_TITLE[] = "Magic Number Squares";
const short int ROW = 3; // number of rows in a Square
const short int COL = 3; // number of columns in a Square
const vector<int> INTS_SQUARE = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // the integers in a Square
const short int MAGIC_NUM = 15; // the Magic Number for a Square of integers 1-9 (sum of the integers, divided by 3)
const int RUNS = 1'000'000; // the number of times to run the main functions. Int can be <= 2.1 billion

// Declare functions
void squareGenerateRandom(int[ROW][COL], int);
bool isMagicSquare(int[ROW][COL]);
string strFormatInt(int);
void printSquare(int[ROW][COL]);
void MagicSquareGenerator(int[ROW][COL]);

// Main program
int main() {
    // Declare variables
    int randSquare[ROW][COL]; // the Square to be used
    int countMagicSquares = 0; // the number of Magic Squares generated
    
    cout << "Welcome to " << PROJ_TITLE << ".\n\n";
    
    // Loop to repeat the large number of times
    cout << "Generating " << strFormatInt(RUNS) << " random Squares. \n";
    for (int i = 1; i <= RUNS; i++)
    {
        // Generate a random Square
        squareGenerateRandom(randSquare, i);
        
        // Check if it's a Magic Square
        if (isMagicSquare(randSquare)) countMagicSquares++;
        
        // Every 25%, print a progress update to remind the user the program is still working
        if (i % (RUNS / 4) == 0) cout << 100*i/RUNS << "% completed. \n";
    }
        
    // Output the number of Runs and the count of Magic Squares
    cout << "\nIn " << strFormatInt(RUNS) << " random Squares generated, "
    << countMagicSquares << " were Magic Squares. \n\n";
    
    return 0;
}

// -------------------------------------------------------------

// Function to initialize the referenced 3x3 array with a Square's integers in random positions
/* I unsuccessfully tried writing my own random placement shuffle algorithm.
 Then I found that the C++ <algorithm> library has its own shuffle() function,
 which I haven't fully understood yet. However it works better than mine did. */
void squareGenerateRandom(int randSquare[ROW][COL], int seed)
{
    // Shuffle the integers 1-9 into random order
    vector<int> iInts = INTS_SQUARE; // make a copy of the integers 1-9
    seed = seed + unsigned(chrono::system_clock::now().time_since_epoch().count()); // supports the random generator
    shuffle(iInts.begin(), iInts.end(), default_random_engine(seed));
    
    
    // Assign the shuffled integer vector to the 3x3 array for the Square
    for (int i = 0, y = 0; y < ROW; y++)
        for (int x = 0; x < COL; x++, i++)
            randSquare[y][x] = iInts[i];
        

    /* My attempt at a shuffling algorithm
     I had also included <cstdlib> library
     
    // Create an array of 9 booleans to flag whether each position in the Square has been filled yet
    bool isPosFilled[9] = {false};
    
    // Seed the random generator
    srand(unsigned(time(0) + seed));
    
    // Loop to repeat for each integer 1-9
    for (int i = 0; i < 9; i++)
    {
        // Generate a random position
        int randPosition = rand() % (9-i);
        
        // If that position is filled, loop to find an unfilled position
        // ----- this is where my algorithm was no longer random
        while (isPosFilled[randPosition])
        {
            if (randPosition < 8) randPosition++;
            else if (randPosition > 0) randPosition--;
        }
        // Convert the position into 2-D Square coordinates
        int y = randPosition / 3;
        int x = randPosition % 3;
        
        // Assign this iteration's integer to that position in the Square
        randSquare[y][x] = i;
        
        // Mark the position as filled
        isPosFilled[randPosition] = true;
    } */
}

// Boolean function for whether the referenced array is a 3x3 Magic Square by analyzing the Square
bool isMagicSquare(int randSquare[ROW][COL])
{
    // Shortcut: if the middle number is not 5, the square can't be a magic square
    if (randSquare[1][1] != 5) return false;
        
    // Check the sum of each row
    for (int y = 0; y < ROW; y++)
        if (randSquare[y][0] + randSquare[y][1] + randSquare[y][2] != MAGIC_NUM) return false;
    
    // Check the sum of each column
    for (int x = 0; x < COL; x++)
        if (randSquare[0][x] + randSquare[1][x] + randSquare[2][x] != MAGIC_NUM) return false;
    
    // Check the sum of each diagonal
    if (randSquare[0][0] + randSquare[1][1] + randSquare[2][2] != MAGIC_NUM) return false;

    if (randSquare[0][2] + randSquare[1][1] + randSquare[2][0] != MAGIC_NUM) return false;

    // If none of the above triggered a "return false", then all the sums == MAGIC_NUM, so return true
    return true;
        
}


// String function to format a large number as a string with commas for place-grouping
string strFormatInt(int num)
{
    string str = to_string(num);
    for (int i = int(str.length())-1, count = 0; i > 0; i--)
        if ((str.length() - i - count) % 3 == 0)
        {
            str.insert(i, ",");
            count++;
        }
    return str;
}

// -------------------------------------------------------------
// Helper functions

// Subroutine to print the magic square
void printSquare(int Square[ROW][COL])
{
    for (int y = 0; y < ROW; y++)
    {
        cout << endl;
        for (int x = 0; x < COL; x++)
            cout << Square[y][x] << " ";
    }
    cout << endl;
}

// Testing Function to manually generate a known Magic Square, for testing Square analysis
void MagicSquareGenerator(int tempMagic[ROW][COL])
{
    tempMagic[0][0] = 4;
    tempMagic[0][1] = 9;
    tempMagic[0][2] = 2;

    tempMagic[1][0] = 3;
    tempMagic[1][1] = 5;
    tempMagic[1][2] = 7;

    tempMagic[2][0] = 8;
    tempMagic[2][1] = 1;
    tempMagic[2][2] = 6;
}
