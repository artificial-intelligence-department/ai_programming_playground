#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int N, int K, vector<int>& a) {
    // Сортування
    sort(a.begin(), a.end());
    // Видалення повторюючихся елементів
    auto last = unique(a.begin(), a.end());
    a.erase(last, a.end());
    
    
    // Циклічний зсув на K елементів
   
    rotate(a.begin(), a.begin() + (K % a.size()), a.end());
    
    // Виведення результату
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Зчитування вхідних даних
    int N, K;
    cin >> N >> K;
    
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Виклик функції та виведення результату
    solve(N, K, a);

    return 0;
}
