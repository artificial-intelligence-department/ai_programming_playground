#include <iostream>
using namespace std;

int main() {
    int H, M;
    cin >> H >> M;

    bool won = true;

    for (int i = 0; i < 3; i++) {
        int hi, mi;
        cin >> hi >> mi;

        // Використовуємо закляття для витрати хітпойнтів
        if (hi <= H) {
            H -= hi;
        }
        // Використовуємо закляття для витрати мани
        else if (mi <= M) {
            M -= mi;
        }
        // В іншому випадку, персонаж програв
        else {
            won = false;
            break;
        }
    }

    // Перевірка, чи персонаж виграв
    if (won && (H > 0 || M > 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
