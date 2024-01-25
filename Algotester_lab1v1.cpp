#include <iostream>
using namespace std;

int main() {
    long long   hitPoints, mana,
                hitpointsForSpell, manaForSpell;
    cin >> hitPoints >> mana;

    for (int i = 0; i < 3; ++i) {
        cin >> hitpointsForSpell >> manaForSpell;
        hitPoints -= hitpointsForSpell;
        mana -= manaForSpell;

        if ((hitPoints <= 0 || mana <= 0) ||
            (hitpointsForSpell > 0 && manaForSpell > 0)) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
