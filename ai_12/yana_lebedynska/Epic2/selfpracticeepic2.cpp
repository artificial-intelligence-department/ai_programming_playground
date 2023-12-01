#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main()
{
    string operation;
    string a = "addition";
    string s = "subtraction";
    string m = "multiplication";
    string e = "exponention";
    long n1, n2, n3;
    bool y = false;
    int pow1, pow2, pow3;

    cout << "Hi! I'm Kulky and I can do some mathematical operations for you\n";
    cout << "I can do these: addition, subtraction, multiplication, exponention\n";
    cout << "Please enter 3 numbers you want to work with: ";
    cin >> n1 >> n2 >> n3;
    cout << "Great! So you entered: " << n1 << ", " << n2 << ", " << n3 << "." << endl;


    cout << "Now enter an operation you want me to do: ";
    cin >> operation;

    while(y != true)
    {
        if(operation != a && operation != s && operation != m && operation != e)
        {
            cout << "This operation is not found. Try again please\n";
            cout << "Choose from existing operations: ";
            cin >> operation;  
        }
        else
        {
            y = true;
        }
    }


    switch(operation[0])
    {
        case 'a':
        cout << "The sum of these numbers is: " << n1+n2+n3;
        break;

        case 's':
        cout << "The subtraction of these is: " << n1-n2-n3;
        break;

        case 'm':
        cout << "The multiplaction of these numbers is: " << n1*n2*n3;
        break;
    }
    
    if(operation == e)
    {
        cout << "Enter the powers of the number to which they must be raised (the first number is a power of first number, the second - of second ect.): ";
        cin >> pow1 >> pow2 >> pow3;
        n1 = pow(n1, pow1);
        n2 = pow(n2, pow2);
        n3 = pow(n3, pow3);
        cout << "Here your numbers are in exalted powers: " << n1 << ", " << n2 << ", " << n3;
    }

    return 0;
}
