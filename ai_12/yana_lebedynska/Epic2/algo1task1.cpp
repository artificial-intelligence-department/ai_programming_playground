#include <iostream>
using namespace std;

int main()
{
    long long H, M, h1, h2, h3, m1, m2, m3;

    cin >> H >> M;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;

    long long sumOfH = h1 + h2 + h3;
    long long sumOfM = m1 + m2 + m3;

    if((h1 > 0 && m1 > 0) || (h2 > 0 && m2 > 0) || (h3 > 0 && m3 > 0))
    {
        cout << "NO";
    }

    else if((sumOfH >= H) || (sumOfM >= M) )
    {
        cout << "NO";
    }

    else
    {
        cout << "YES";
    }

    return 0;
}