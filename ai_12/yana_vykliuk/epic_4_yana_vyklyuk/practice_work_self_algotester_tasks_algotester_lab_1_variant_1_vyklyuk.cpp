#include <iostream>

using namespace std;

long long H, M, h1, h2, h3, m1, m2 ,m3;

int main()
{
    cin >> H >> M >> h1 >> m1 >> h2 >> m2 >> h3 >> m3;

    if (H < 1 || M < 1)
    {
        return 0;
    }

    long long h[3] = {h1, h2, h3};
    long long m[3] = {m1, m2, m3};

    for(int i = 0; i < 3; i++)
    {
        if(h[i] > 0 && m[i] > 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        
        H -= h[i];
        M -= m[i];
    }

    if (H > 0 && M > 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
