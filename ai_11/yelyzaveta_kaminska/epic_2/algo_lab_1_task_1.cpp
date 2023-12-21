#include <iostream>

using namespace std;

int main() {
    long long int maxMana, maxHealth, mana, health;
    bool win = true;

    cin >> maxMana >> maxHealth;

    for (int i = 0; i < 3; i++) {
        cin >> mana >> health;

        if (mana > 0 && health > 0)
            win = false;

        maxMana -= mana;
        maxHealth -= health;
    }

    if (maxMana > 0 && maxHealth > 0 && win)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

