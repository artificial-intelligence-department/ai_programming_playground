
#include <iostream>

using namespace std;

int main()
{

    double a1, a2, a3, a4, a5;

    cout << "Enter sides of cubes a1, a2, a3, a4, a5 \n";
    cin >> a1 >> a2 >> a3 >> a4 >> a5;

    if (a1 <= 0 || a2 <= 0 || a3 <= 0 || a4 <= 0 || a5 <= 0)
    {
        cout << "ERROR";
    }
    else if (a1 < a2 || a2 < a3 || a3 < a4 || a4 < a5)
    {
        cout << "LOOS";
    }
    else if (a1 >= a2 && a2 >= a3 && a3 >= a4 && a4 >= a5)
    {
        cout << "WIN";
    }

    return 0;
}