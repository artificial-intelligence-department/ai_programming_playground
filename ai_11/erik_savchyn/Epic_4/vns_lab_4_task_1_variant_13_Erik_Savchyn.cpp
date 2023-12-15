#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    const int N = 100;
    int a[N];

    start:
    cout << "Введіть довжину масиву (не більше " << N << "): ";
    int length;
    cin >> length;

    if (length > N || length < 1) {
        cout << "не допустима довжина масиву. Змініть довжину.\n";
        goto start;
    }

    for (int i = 0; i < length; ++i) {
        a[i] = rand() % 100;
    }

    cout << "Початковий масив:\n";
    for (int i = 0; i < length; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    int minElement = a[0];
    for (int i = 1; i < length; ++i) {
        if (a[i] < minElement) {
            minElement = a[i];
        }
    }

    int newSize = 0;
    for (int i = 0; i < length; ++i) {
        if (a[i] != minElement) {
            a[newSize++] = a[i];
        }
    }

    int sum = 0;
    for (int i = 0; i < newSize; ++i) {
       sum += a[i];
    }   

    float average = static_cast<float>(sum) / newSize;

    for (int i = newSize - 1; i >= 0; --i) {
        a[i + 3] = a[i];
    }

    for (int i = 0; i < 3; ++i) {
        a[i] = static_cast<int>(average);
    }

    newSize += 3;

    cout << "Оновлений масив:\n";
    for (int i = 0; i < newSize; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
