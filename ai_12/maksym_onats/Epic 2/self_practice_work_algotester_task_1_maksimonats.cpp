#include <iostream>
using namespace std;

int main()
{

int var;
cout << " Enter a number to check for parity: ";
cin >> var;

if (var%2==0)
{
    cout << " Numeric " << var << " steamy!" << '\n';
}

else
{
    cout << " Numeric " << var << " odd! " << '\n';
}
    return 0;
}