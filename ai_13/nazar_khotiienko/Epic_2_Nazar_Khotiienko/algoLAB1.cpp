#include <iostream>
using namespace std;
int main()
{
    long a, b;
    cin >> a >> b;
    long q1, q2;
    cin >> q1 >> q2;
    long w1, w2;
    cin >> w1 >> w2;
    long e1, e2;
    cin >> e1 >> e2;
    if (a - q1 - w1 - e1 <= 0)
    {
        cout << "NO";
    }
    else if (b - q2 - w2 - e2 <= 0)
    {
        cout << "NO";
    }
    else if (q1 > 0 and q2 > 0)
    {
        cout << "NO";
    }
    else if (w1 > 0 and w2 > 0)
    {
        cout << "NO";
    }
    else if (e1 > 0 and e2 > 0)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return (0);
}