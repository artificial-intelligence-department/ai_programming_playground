#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main ()
{
    int b, c;
    double d, e, f, g;
    string a;
//name = a; per year = b; number of years = c; principal amount = d; rate interest = e; compound interest = f; loan with interest = g

    cout<<"Enter your name:\n";
    cin>>a;
    cout<<"Enter the principal amount:\n";
    cin>>d;
    cout<<"Enter the rate of interest (in percentage):\n";
    cin>>e;
    e = e/100; // перепис числа відсотків десятковим числом, щоб формула виконувалась правильно
    cout<<"Enter the number of years:\n";
    cin>>c;
    cout<<"Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):\n";
    cin>>b;

    g = d*pow(1+(e/b), c*b); // формула обчислення складних відсотків
    f = g-d; // обрахунок повної суми до сплати після n років

    cout<<"Hello "<<a<<"!\n";
    cout<<"The compound interest for a principal of "<<d<<" at a rate of "<<e*100<<" compounded "<<b<<" times a year for "<<c<<" years is: "<<f<<"\n";
    cout<<"The total amount after "<<c<<" years is: "<<g;

    return 0;
}