#include <iostream>
using namespace std;

int main()
{
    int H, M;
    bool win = true;
    cout << "Character's hitpoints and mana: ";
    cin >> H >> M;

    cout << "Enter an amount of HP and mana the character will spend for spell:" << endl;
    for (int i = 0; i < 3; i++)
    {
        int h, m;
        cin >> h >> m;
        if (h > 0 && m > 0) {
            win = false;
        }
        H -= h;
        M -= m;
    }
    if (H <= 0 || M <= 0 || win == false) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
    
    return 0;
}
