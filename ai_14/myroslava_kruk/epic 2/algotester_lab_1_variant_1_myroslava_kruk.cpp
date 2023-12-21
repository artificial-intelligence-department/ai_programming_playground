#include <iostream>

using namespace std;

int main() {
    int H, M;
    cin >> H >> M;

    int h[3], m[3];
    for (int i = 0; i < 3; ++i) {
        cin >> h[i] >> m[i];
    }

    for (int i = 0; i < 8; ++i) {
        int health = H, mana = M;
        for (int j = 0; j < 3; ++j) {
            if (i & (1 << j)) {
                health -= h[j];
                mana -= m[j];
            }
        }
        if (health > 0 && mana > 0) {
            cout << "YES" << endl;
            return 0;  // Завершення програми, оскільки знайдено виграшну комбінацію
        }
    }

    cout << "NO" << endl;
    return 0;
}
