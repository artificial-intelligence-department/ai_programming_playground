#include <iostream>
#include <vector>
#include <algorithm>      // функції для роботи з алгоритмами (sort, rotate)
#include <unordered_set>  // зберігає унікальні елементи
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    // Видаляємо дубльовані елементи з масиву
    unordered_set<int> uniqueSet;     //створює змінну яка буде використовуватись для зберігання унікальних цілих чисел
    for (auto i = a.begin(); i != a.end();) {
        if (uniqueSet.find(*i) != uniqueSet.end()) {
            i = a.erase(i);
        } else {
            uniqueSet.insert(*i);
            ++i;
        }
    }

    // Сортуємо масив та здійснюємо обертання на K елементів
    sort(a.begin(), a.end());        //сортує у порядку зростання

   // Знаходимо новий розмір масиву після видалення дублікатів
    int new_size = a.size();

    // Здійснюємо обертання на K % new_size елементів
    K %= new_size;
    rotate(a.begin(), a.begin() + K, a.end());

    // Виводимо результат
    cout << a.size() << endl;
    for (int num : a) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
