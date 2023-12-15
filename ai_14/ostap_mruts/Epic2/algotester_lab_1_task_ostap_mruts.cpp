#include <iostream>
using namespace std;

int main() {    
    long long M, m, H, h;
    int lose = 0;
    cin >> H >> M;

    for (int i = 0; i < 3; ++i) {
        cin >> h >> m;
        H -= h;
        M -= m;
        if ((h != 0 && m != 0) || (H < 0 || M < 0)) {
            lose = 1;
        }
    }

    else if (H > 0 && M > 0 && lose == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}