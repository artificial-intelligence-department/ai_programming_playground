#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Зчитування вхідних даних
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Видалення повторюючихся елементів
    sort(a.begin(), a.end());
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());

    // Обертання та виведення результату
    rotate(a.begin(), a.begin() + K % a.size(), a.end());

    // Виведення результату
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i];
        if (i < a.size() - 1) {
            cout << " ";
        }
    }

    return 0;
}