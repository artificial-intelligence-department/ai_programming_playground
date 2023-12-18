#include <iostream>
#include <string>
using namespace std;

void Compression(string a)
{
    string b;
    int n = 1;
    int N = a.size();
    for (int i = 0; i < N; ++i)
    {
        if (a[i + 1] == a[i])
        {
            ++n;
        }
        else
        {
            b += a[i];
            if (n > 1)
            {
                b += to_string(n);
                n = 1;
            }
        }
    }
    cout << b;
}

int main()
{
    string S;
    cin >> S;
    Compression(S);
    return 0;
}
