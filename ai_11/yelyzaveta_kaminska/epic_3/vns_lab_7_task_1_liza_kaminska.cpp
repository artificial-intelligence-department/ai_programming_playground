#include <iostream>
#include <cstdarg>
using namespace std;

int Min (int count, ...) {
    va_list args;
    va_start(args, count);

    int min = va_arg(args, int);

    for (int i = 1; i < count; ++i) {
        int current = va_arg(args, int);
        if (current < min) {
            min = current;
        }
    }

    va_end(args);

    return min;
}

int main() {
    int result1 = Min(5, 3, 7, 2, 9, 5);
    cout << "Min of 5 numbers: " << result1 << endl;

    int result2 = Min(10, 8, 4, 2, 6, 10, 12, 1, 5, 3, 9);
    cout << "Min of 10 numbers: " << result2 << endl;

    int result3 = Min(12, 15, 4, 18, 20, 9, 14, 16, 22, 7, 13, 5, 17);
    cout << "Min of 12 numbers: " << result3 << endl;

    return 0;
}
