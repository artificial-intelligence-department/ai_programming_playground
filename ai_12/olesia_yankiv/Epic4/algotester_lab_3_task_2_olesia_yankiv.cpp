#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    // Введення розміру першого масиву
    int n;
    cin >> n;

    // Введення елементів першого масиву
    vector<int> array1(n);
    for (int i = 0; i < n; i++) {
        cin >> array1[i];
    }

    int m;
    cin >> m;

    vector<int> array2(m);
    for (int i = 0; i < m; i++) {
        cin >> array2[i];
    }
   // Створення невпорядкованої множини для унікальних елементів
    unordered_set<int> uniqueElements;
    int commonElements = 0;

    // Додаємо унікальні елементи першого масиву до множини
    for (int i = 0; i < n; i++) {
        uniqueElements.insert(array1[i]);
    }
    // Порівнюємо елементи другого масиву з унікальними елементами першого
    for (int i = 0; i < m; i++) {
        if (uniqueElements.count(array2[i])) {
            commonElements++;
        } // Додаємо елемент до множини
        uniqueElements.insert(array2[i]);
    }
    //Вивід
    cout << commonElements << endl;
    cout << uniqueElements.size() << endl;

    return 0;
}
