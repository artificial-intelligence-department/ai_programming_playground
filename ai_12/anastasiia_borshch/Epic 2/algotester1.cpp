#include <iostream>
using namespace std;

int main() {
    long long Hitpoints, Mana, h, m;
    bool win = true;
    cin >> Hitpoints >> Mana;
    for (int i = 0; i < 3; ++i) {
        cin >> h >> m;
        Hitpoints -= h;
        Mana -= m;
        win = (( (h && m) || (Hitpoints < 1) || (Mana < 1) ) ? false : win);
        h = 0, m = 0;
    }
    cout << ( win ? "YES" : "NO");
    return 0;
}



