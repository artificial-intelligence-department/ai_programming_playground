#include <iostream>
int main() {
    long long HP;
    long long MANA;
    long long hp;
    long long mana;
    bool mana0cured= false;
    std::cin >> HP;
    std::cin >> MANA;
    for (int i = 0; i < 3; i++) {
        std::cin >> hp;
        std::cin >> mana;
        if (hp > 0 && mana > 0) {
            mana0cured = true;
        }
        if ((HP - hp <= 0) || (MANA - mana <= 0)) {
            HP -= hp;
            MANA -= mana;
            mana0cured = true;
        } else {
            HP -= hp;
            MANA -= mana;
        }
    }
    if (mana0cured)
        std::cout << "NO";
    else
        std::cout << "YES";
    return 0;
}

