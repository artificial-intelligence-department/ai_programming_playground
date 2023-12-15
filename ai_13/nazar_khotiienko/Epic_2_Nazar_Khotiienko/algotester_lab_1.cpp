#include <iostream>
using namespace std;

int main()
{
    long H, M; // мана та хітпоінти
    long h1, h2, h3, m1, m2, m3; //використання мана та хітпоінти
    cin >> H >> M;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> h3 >> m3;

    if ((H - h1 - h2 - h3 <= 0) or (M - m1 - m2 - m3 <= 0)) // Перевірка додатньої суми
    {
        cout << "NO\n";
    }
    else if ((h1 > 0 and m1 > 0) or (h2 > 0 and m2 > 0) or (h3 > 0 and m3 > 0)) 
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return 0;
}


