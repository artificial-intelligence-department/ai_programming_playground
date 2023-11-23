#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Amount of companies: ";
    cin >> n;
    int offices[100000];  // Масив для зберігання довжин офісів
    int indices[100000];  // Масив для зберігання індексів компаній

cout << "Enter lenth of offices: ";
    for (int i = 0; i < n; i++) {
        cin >> offices[i];
        indices[i] = i + 1;
    }

    // Сортуємо індекси компаній за довжинами офісів
    sort(indices, indices + n, [&offices](int a, int b) {
        return offices[a - 1] < offices[b - 1];
    });

    for (int i = 0; i < n; i++) {
        cout << indices[i] << " ";
    }
    cout << endl;

    return 0;
}
