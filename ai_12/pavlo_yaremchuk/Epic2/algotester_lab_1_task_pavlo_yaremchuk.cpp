#include <iostream>
using namespace std;

int main()
{
    long long H, M, H0, M0, h1, m1, h2, m2, m3, h3;
    cin >> H >> M;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;
    H0 = H - (h1 + h2 + h3);
    M0 = M - (m1 + m2 + m3);
    if ( (h1 > 0 && m1 > 0) || (h2 > 0 && m2 > 0) || (h3 > 0 && m3 > 0) || (h1 == m1) || (h3 == m3))
    {
        cout << "NO" << endl;
    }
    else if (h2 == m2)
    {
        cout << "NO" << endl;
    }
    else if (H0 <= 0 || M0 <= 0)
    {
        cout << "NO" << endl;
    }
    else 
    {
        cout << "YES" << endl;
    }
    return 0;
}