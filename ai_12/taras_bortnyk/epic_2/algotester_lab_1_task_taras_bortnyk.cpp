#include <iostream>
using namespace std;
int main()
{
    long long int hbegin, mbegin, m1, m2, m3, h1, h2, h3;
    string result;
    cin >> hbegin >> mbegin;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;

    for (int i =0; i != 1;)
    {
        if (h1 == 0 || m1 == 0)
        {
            hbegin -= h1;
            mbegin -= m1;
        }
        else
        {
            result = "NO";
            break;
        }
        if (h2 == 0 || m2 == 0)
        {
            hbegin -= h2;
            mbegin -= m2;
        }
        else
        {
            result = "NO";
            break;
        }
        if (h3 == 0 || m3 == 0)
        {
            hbegin -= h3;
            mbegin -= m3;
        }
        else
        {
            result = "NO";
            break;
        }
        if (hbegin > 0 && mbegin > 0)
        {
            result = "YES";
        }
        else
        {
            result = "NO";
        }
        i = 1;
    }
    cout << result;
}