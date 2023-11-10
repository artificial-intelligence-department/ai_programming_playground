#include <iostream>
using namespace std;

int main()
{
    long long int H, M, h, m;
    bool flag = true;

    cin >> H >> M;

    for (int i = 0; i < 3; i++)  {
        cin >> h >> m;
        if (h > 0 & m > 0)
            flag = false;
    H -= h;
    M -= m;
    }


    if (H > 0 & M > 0 & flag) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}