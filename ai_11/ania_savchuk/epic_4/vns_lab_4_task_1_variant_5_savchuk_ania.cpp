#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int N = 100;
    int a[N];
    int n;
    cout << "Введіть реальну довжину масиву: ";
    cin >> n;
    cout << "Отриманий масив: ";
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 + 1;
        cout << a[i] << " ";
    }cout << endl;
    
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 7 != 0) {
            a[j] = a[i];
            j++;
        }
    }

    n=j;
    cout << "Масив після видалення елементів, кратних 7: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            for (int k = n; k > i; k--) {
                a[k] = a[k - 1];
            }
            a[i + 1] = 0;
            n++;
            i++;
        }
    }
    cout << "Масив після додавання 0 після кожного непарного елемента: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}
