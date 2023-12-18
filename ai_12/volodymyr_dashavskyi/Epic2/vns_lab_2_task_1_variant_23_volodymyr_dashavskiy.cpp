#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter number for n: \n";
    cin >> n;
    cout << "Enter number for m: \n";
    cin >> m;

    cout << "First result is: " << (n) - (--m) << endl;
    cout << "Second resust is: " << boolalpha << ((m++) < (n)) << endl;
    cout << "Third result is: " << boolalpha << ((n++) > (m)) << endl;
}
