#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long a, b, c, d;
    cin >> a >> b >> c >> d;

    unsigned long q1, q2, q3, q4;
    cin >> q1;
    cin >> q2;
    cin >> q3;
    cin >> q4;

    if (a < q1 or b < q2 or c < q3 or d < q4)
    {
        cout << ("ERROR");
    }
    else if (a - q1 >= 2 * min(min(b, c), d))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b), max(c, d)) >= 2 * min(min(b, c), min(a - q1, d)))
    {
        cout << "NO";
    }
    else if (b - q2 >= 2 * min(min(a - q1, c), d))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b - q2), max(c, d)) >= 2 * min(min(a - q1, c), min(b - q2, d)))
    {
        cout << "NO";
    }
    else if (c - q3 >= 2 * min(min(a - q1, b - q2), d))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b - q2), max(c - q3, d)) >= 2 * min(min(a - q1, c - q3), min(b - q2, d)))
    {
        cout << "NO";
    }
    else if (d - q4 >= 2 * min(min(a - q1, b - q2), c - q3))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b - q2), max(c - q3, d - q4)) >= 2 * min(min(a - q1, c - q3), min(b - q2, d - q4)))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return (0);
}