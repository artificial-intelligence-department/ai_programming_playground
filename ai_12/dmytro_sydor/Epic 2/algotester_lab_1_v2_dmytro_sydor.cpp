#include <iostream>
using namespace std;

int main()
{
    long int H, M;
    long int h1, m1, h2, m2, h3, m3;

    cout << "Write your Hp and Mana " << endl;
    cin >> H >> M;

    cout << "Input first skill kost " << endl;
    cin >> h1 >> m1;
    cout << "Input second skill kost " << endl;
    cin >> h2 >> m2;
    cout << "Input third skill kost " << endl;
    cin >> h3 >> m3;

    if (h1 > 0 && m1 > 0)
    {
        cout << "NO";
        return 0;
    }
    else if (h1 > 0)
    {
        H -= h1;
    }
    else
    {
        M -= m1;
    }

    // second skill cost check

    if (h2 > 0 && m2 > 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    else if (h2 > 0)
    {
        H -= h2;
    }
    else
    {
        M -= m2;
    }

    // third skill cost check

    if (h3 > 0 && m3 > 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    else if (h3 > 0)
    {
        H -= h3;
    }
    else
    {
        M -= m3;
    }

    if (M > 0 && H > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
