#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long R, r;
    cin >> R >> r;
    if ((r < 1) || (r >= R) || (R > 1000000000))
    {
        cout << "FALSE VALUE" << endl;
    }
    else if (r > ((R * (sqrt(3) - 1)) / (sqrt(3) + 1)))
    {
        cout << "rumpled" << endl;
    }
    else
    {
        cout << "safe" << endl;
    }
    return 0;
}