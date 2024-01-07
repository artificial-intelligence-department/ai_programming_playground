#include <iostream>
#include <cstdarg>
#include <ctime>

using namespace std;

int sum(int count, ...) { 
    int result = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i += 2) {
        int a1 = va_arg(args, int);
        int a2 = va_arg(args, int);
        result += a1 * a2;
    }

    va_end(args);
    return result;
}

int main() {
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int numbers1[8], numbers2[10], numbers3[12];

    cout << "generated rows: ";
    for (int i = 0; i < 8; ++i) {
        numbers1[i] = rand() % 10 + 1; // Генерація випадкового числа від 1 до 10
        cout << numbers1[i] << " ";
    }

    int res1 = sum(8, numbers1[0], numbers1[1], numbers1[2], numbers1[3], numbers1[4], numbers1[5], numbers1[6], numbers1[7]);

    cout << endl << "result: " << res1 << endl;

    cout << "generated rows: ";
    for (int i = 0; i < 10; ++i) {
        numbers2[i] = rand() % 10 + 1; 
        cout << numbers2[i] << " ";
    }

    int res2 = sum(10, numbers2[0], numbers2[1], numbers2[2], numbers2[3], numbers2[4], numbers2[5], numbers2[6], numbers2[7], numbers2[8], numbers2[9]);

    cout << endl << "result: " << res2 << endl;

    cout << "generated rows: ";
     for (int i = 0; i < 12; ++i) {
        numbers3[i] = rand() % 10 + 1; 
        cout << numbers3[i] << " ";
    }

    int res3 = sum(12, numbers3[0], numbers3[1], numbers3[2], numbers3[3], numbers3[4], numbers3[5], numbers3[6], numbers3[7], numbers3[8], numbers3[9], numbers3[10], numbers3[11]);

    cout << endl << "result: " << res3 << endl;


    return 0;
}
