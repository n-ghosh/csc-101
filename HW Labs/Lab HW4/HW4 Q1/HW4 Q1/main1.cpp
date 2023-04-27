/* Lab HW4 Q1
 By Nikhil Ghosh
 For STCC CSC 101
 
 The task is to fix someone else's program, which is intended to approximate the value of pi.
 
 There appears to be a typo in the homework question.
 The question states that the value of pi can be approximated using the series:
 pi = 4 (1 - 1/3 + 1/5 - 1/7 + ... + 1/(2n-1) + 1/(2n+1))
 Wikipedia says the Leibniz series, used to approximate pi, is:
 pi = 4 (1 - 1/3 + 1/5 - 1/7 + ... + (-1^n)/(2n+1))
 The first series' description of end behavior does not yield the alternating sequence of positive and negative indicated by the first few numbers, but the Leibniz series does. The pre-written program also seems to use the Leibniz series, so I am also choosing the Leibniz series over the series given by the homework question.
 */

#include <iostream>
//#include <iomanip> // this library is unused
using namespace std;

int main()
{
    double pi = 0;
    long i;
    long n;
    
    // One mistake was here. The following two lines were out of order.
    cout << "Enter the value of n: "; //
    cin >> n; //
    cout << endl;
    
    for (i = 0; i < n; i++)
    {
        // pi = 0; // this line seems like a mistake.
        
        // Two mistakes were here.
        // This conditional should not have been before the loop. This is the part of the series that continues for n times.
        // The calculation lines needed to specify a decimal to switch to floating-point arithmetic. Otherwise the program uses integers by default
        if (i % 2 == 0)
            pi = pi + (1.0 / (2 * i + 1)); //
        else
            pi = pi - (1.0 / (2 * i + 1)); // this line also says 2n+1, not 2n-1. I agree.

    }
    
    pi = 4 * pi; // this line should not have been inside the for loop

    cout << endl << "pi = " << pi << endl;
    return 0;
    
}
