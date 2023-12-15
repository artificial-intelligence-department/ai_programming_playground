#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Розрахунок префіксних сум
    vector<int> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }

    // Обробка запитів
    for (int q = 0; q < m; ++q) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            // Запит першого типу: знайти суму елементів на відрізку від l до r
            int l, r;
            cin >> l >> r;
            int result = prefix_sum[r] - prefix_sum[l - 1];
            cout << result << endl;
        } else if (query_type == 2) {
            // Запит другого типу: додати число d до i-го елементу масиву
            int i, d;
            cin >> i >> d;
            a[i - 1] += d;
            // Оновлення префіксних сум після зміни елементу
            for (int j = i; j <= n; ++j) {
                prefix_sum[j] += d;
            }
        }
    }

    return 0;
}
