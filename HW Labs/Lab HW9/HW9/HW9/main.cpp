/* Lab HW9
 By Nikhil Ghosh
 For STCC CSC-101
 
 Description: practice with classes. Define a class for books and test its operations,
 especially to search for a book and update its info.
 */

#include <iostream>
#include <iomanip>
using namespace std;

// Declare class
class BookType
{ // Declare class member variables
private:
    string sTitle;
    string sAuthors[4];
    int iNumAuthors;
    string sPublisher;
    string sISBN;
    double dPrice;
    int iNumCopies;

// Declare class member functions
public:
    // Constructors
    BookType();
    BookType(string, string[], int, string, string, double, int);

    // Set functions to allow public program to set private class variables
    void setTitle(string);
    void setPublisher(string);
    void setISBN(string);
    void setPrice(double);
    void setCopies(int);
    void setAuthors(string[], int);

    void updateCopies(int);
    bool isThisTheTitle(string) const;
    bool isThisTheISBN(string) const;

    // Get functions to return private class variables to public program
    string getTitle() const;
    string getPublisher() const;
    string getISBN() const;
    double getPrice() const;
    int getCopies() const;
    void getAuthors(string[]) const;

    // Print functions to allow public program to print private class variables
    void printBook() const;
    void printTitle() const;
    void printPublisher() const;
    void printISBN() const;
    void printPrice() const;
    void printCopies() const;
    void printAuthors() const;
};

// -------------------------------------------------------------
// Main program
int main()
{
    // Declare variables
    string arrAuthor1[2] = {"N", "G"}, arrAuthor0[1] = {"James Clear"}, arrAuthor2[4];
    BookType bookOne("Book One", arrAuthor1, 2, "XCode", "No ISBN", 100.0, 1);
    BookType arrBooks[100];
    string sTitle0 = "Atomic Habits", sTitleA = "Atomic", sTitleC = "Title C", sTemp;
    int iTemp;
    double dTemp;
    arrBooks[1] = bookOne;

    // Test the constructors using the printBook() function
    // cout << fixed << setprecision(2);
    arrBooks[1].printBook();
    arrBooks[0].printBook();
    
    // Set a book's data
    arrBooks[0].setTitle(sTitle0);
    arrBooks[0].setAuthors(arrAuthor0, 1);
    arrBooks[0].setPublisher("Avery");
    arrBooks[0].setISBN("978-073521129-2");
    arrBooks[0].setPrice(11.99);
    arrBooks[0].setCopies(9999);
    
    // Test the print functions
    cout << "Test Print, book0. Are these 3 groups of 6 lines any different?: \n";
    cout << "\t 1 Manual: \n";
    cout << "Title: Atomic Habits" << endl;
    cout << "Author(s): James Clear" << endl;
    cout << "Publisher: Avery" << endl;
    cout << "ISBN: 978-073521129-2" << endl;
    cout << "Price: $11.99" << endl;
    cout << "Number of copies in stock: 9999" << endl;
    cout << endl << "\t 2 Each variable's printVar(): \n";
    arrBooks[0].printTitle();
    arrBooks[0].printAuthors();
    arrBooks[0].printPublisher();
    arrBooks[0].printISBN();
    arrBooks[0].printPrice();
    arrBooks[0].printCopies();
    cout << endl << "\t 3 printBook(): \n";
    arrBooks[0].printBook();
    
    // Test the title functions
    cout << "Test Titles, book0. Are these lines any different?: \n";
    cout << "1: Title: Atomic Habits" << endl;
    sTemp = arrBooks[0].getTitle();
    cout << "2: Title: " << sTemp << endl;
    cout << "3: ";
    arrBooks[0].printTitle();
    cout << endl;

    // Test the author functions
    cout << "Test Authors, book0. Are these lines any different?: \n";
    cout << "1: Author(s): James Clear" << endl;
    arrBooks[0].getAuthors(arrAuthor2);
    cout << "2: Author(s): ";
    for (int i = 0; i < 4; i++)
        cout << arrAuthor2[i] << " ";
    cout << endl << "3: ";
    arrBooks[0].printAuthors();
    cout << endl;
    
    cout << "Test Authors, book1. Are these lines any different?: \n";
    cout << "1: Author(s): N, G" << endl;
    arrBooks[1].getAuthors(arrAuthor2);
    cout << "2: Author(s): " << arrAuthor2[0] << ", ";
    for (int i = 1; i < 4; i++)
        cout << arrAuthor2[i] << " ";
    cout << endl << "3: ";
    arrBooks[1].printAuthors();
    cout << endl;

    // Test the price functions
    cout << "Test Prices, book0. Are these lines any different? \n";
    cout << "1: Price: $11.99" << endl;
    dTemp = arrBooks[0].getPrice();
    cout << "2: Price: $" << dTemp << endl;
    cout << "3: ";
    arrBooks[0].printPrice();
    cout << endl;
    
    cout << "Test Prices, book2. Are these lines any different? \n";
    cout << "1: Price: $12.00" << endl;
    arrBooks[2].setPrice(11.996);
    dTemp = arrBooks[2].getPrice();
    cout << "2: Price: $" << dTemp << endl;
    cout << "3: ";
    arrBooks[2].printPrice();
    cout << endl;

    
    // Test the number of copies functions
    cout << "Test NumCopies, book1. Are these lines any different? \n";
    cout << "1: Number of copies in stock: 1" << endl;
    iTemp = arrBooks[1].getCopies();
    cout << "2: Number of copies in stock: " << iTemp << endl;
    cout << "3: ";
    arrBooks[1].printCopies();
    cout << endl;
    // Try updating the number of copies, like a sale or inventory shipment
    cout << "Test updating copies \n";
    arrBooks[1].setCopies(arrBooks[1].getCopies() - 1);
    arrBooks[1].printCopies();
    arrBooks[1].setCopies(arrBooks[1].getCopies() + 30);
    arrBooks[1].printCopies();
    cout << endl;
    
    
    // Test the check functions
    if (!bookOne.isThisTheTitle("book one"))
        cout << "Failed test title 1! \n";
    if (bookOne.isThisTheISBN("No 1SBN"))
        cout << "Failed test ISBN 1! \n";
    if (arrBooks[0].isThisTheTitle("book one"))
        cout << "Failed test title 2! \n";
    if (!arrBooks[0].isThisTheISBN("978-073521129-2"))
        cout << "Failed test ISBN 2! \n";
    
    // Try searching the array for a few books
    cout << "Test searches. \n";
    iTemp = -1;
    for (int i = 0; i < 100; i++) {
        if (arrBooks[i].isThisTheTitle("Atomic Habits"))
            iTemp = i;
    }
    cout << "Index: " << iTemp << " , should be 0 for Atomic Habits \n";
    arrBooks[iTemp].printBook();
    
    iTemp = -1;
    for (int i = 0; i < 100; i++) {
        if (arrBooks[i].isThisTheTitle("Title C"))
            iTemp = i;
    }
    cout << "Index: " << iTemp << " , should be -1 for Title C \n";
    // arrBooks[-1].printTitle(); // negative index doesn't automatically error out !!

    arrBooks[99].setTitle(sTitleC);
    iTemp = -1;
    for (int i = 0; i < 100; i++) {
        if (arrBooks[i].isThisTheTitle("Title C"))
            iTemp = i;
    }
    cout << "Index: " << iTemp << " , should be 99 for new Title C \n";
    arrBooks[iTemp].printBook();

    iTemp = -1;
    for (int i = 0; i < 100; i++) {
        if (arrBooks[i].isThisTheISBN("No ISBN"))
            iTemp = i;
    }
    cout << "Index: " << iTemp << " , should be 1 for Book One \n";
    arrBooks[iTemp].printBook();
    
    
    cout << "\n\n";
    return 0;
}

// -------------------------------------------------------------
// Define BookType's member functions
// Condense the one-line functions so the program isn't so long.

// Constructors
// Default constructor without parameters
BookType::BookType()
{
    sTitle = "Unconstructed BookType";
    iNumAuthors = 2;
    sAuthors[0] = "Me";
    sAuthors[1] = "You";
    for (int i = 2; i < 4; i++)
        sAuthors[i] = "";
    sPublisher = "This machine";
    sISBN = "NA";
    dPrice = 0;
    iNumCopies = 1;
}
// Constructor with parameters
BookType::BookType(string sNewTitle, string sNewAuthors[], int iNewNumAuthors, string sNewPublisher, string sNewISBN, double dNewPrice, int iNewNumCopies)
{
    setTitle(sNewTitle);
    setAuthors(sNewAuthors, iNewNumAuthors);
    setPublisher(sNewPublisher);
    setISBN(sNewISBN);
    setPrice(dNewPrice);
    setCopies(iNewNumCopies);
}

// Set functions to allow public program to set private class variables
// Set the title
void BookType::setTitle(string sNewTitle) { sTitle = sNewTitle; }
// Set the publisher
void BookType::setPublisher(string sNewPublisher) { sPublisher = sNewPublisher; }
// Set the ISBN
void BookType::setISBN(string sNewISBN) { sISBN = sNewISBN; }
// Set the price
void BookType::setPrice(double dNewPrice) { dPrice = dNewPrice; }
// Set the number of copies
void BookType::setCopies(int iNewNumCopies) { iNumCopies = iNewNumCopies; }
// Set the author(s)
void BookType::setAuthors(string sNewAuthors[], int iNewNumAuthors)
{
    iNumAuthors = iNewNumAuthors;
    if (iNumAuthors > 4)
        iNumAuthors = 4;
    for (int i = 0; i < iNumAuthors; i++)
        sAuthors[i] = sNewAuthors[i];
}


// Update the number of copies
void BookType::updateCopies(int iNewNumCopies) {
    iNumCopies = iNewNumCopies;
}


// Check functions
// Return a boolean for whether the input equals the title
bool BookType::isThisTheTitle(string sThis) const
{ // Loop through the strings and compare each character in uppercase
    for (int i = 0; i < sTitle.length(); i++)
        if (toupper(sTitle[i]) != toupper(sThis[i]))
            return false;
    return true;
}
// Return a boolean for whether the input equals the ISBN
bool BookType::isThisTheISBN(string sThis) const
{ // Loop through the strings and remove any dashes "-"
    string sTemp = sISBN;
    for (int i = 0; i < sISBN.length(); i++)
    {
        if (sTemp[i] == '-')
        {
            sTemp.erase(i, 1);
            i--;
        }
        else if (sThis[i] == '-')
        {
            sThis.erase(i, 1);
            i--;
        }
    }
    return (sTemp == sThis);
}


// Get functions to return private class variables to public program
// Return the title as a string
string BookType::getTitle() const { return sTitle; }
// Return the publisher as a string
string BookType::getPublisher() const { return sPublisher; }
// Return the ISBN as a string
string BookType::getISBN() const { return sISBN; }
// Return the price as a double
double BookType::getPrice() const { return dPrice; }
// Return the number of copies as an int
int BookType::getCopies() const { return iNumCopies; }
// Return the author(s) by updating the reference parameter
void BookType::getAuthors(string sReference[]) const
{
    int i = 0;
    for (; i < iNumAuthors; i++)
        sReference[i] = sAuthors[i];
    for (; i < sizeof(*sReference)/sizeof(string); i++)
        sReference[i] = "";
}


// Print functions to allow public program to print private class variables
// Print all of the book's data
void BookType::printBook() const
{
    printTitle();
    printAuthors();
    printPublisher();
    printISBN();
    printPrice();
    printCopies();
    cout << endl;
}
// Print the title
void BookType::printTitle() const { cout << "Title: " << sTitle << endl; }
// Print the publisher
void BookType::printPublisher() const { cout << "Publisher: " << sPublisher << endl; }
// Print the ISBN
void BookType::printISBN() const { cout << "ISBN: " << sISBN << endl; }
// Print the Price
void BookType::printPrice() const { cout << fixed << setprecision(2) << "Price: $" << dPrice << endl; }
// Print the number of copies
void BookType::printCopies() const { cout << "Number of copies in stock: " << iNumCopies << endl; }
// Print the author(s)
void BookType::printAuthors() const
{
    cout << "Author(s): ";
    for (int i = 0; i < iNumAuthors - 1; i++)
        cout << sAuthors[i] << ", ";
    cout << sAuthors[iNumAuthors-1] << endl;
}

