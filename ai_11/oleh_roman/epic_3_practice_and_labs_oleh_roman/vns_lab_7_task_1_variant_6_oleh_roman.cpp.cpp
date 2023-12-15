#include <iostream>
#include <cstdarg>

using namespace std;

int min(int count, ...) {
    va_list args;
    va_start(args, count);

    int minimum = va_arg(args, int);

    for (int i = 1; i < count; ++i) {
        int current = va_arg(args, int);
        if (current < minimum) {
            minimum = current;
        }
    }

    va_end(args);
    return minimum;
}

int main() {
    int result1 = min(5, 8, 3, 12, 6, 10);
    int result2 = min(10, 7, 15, 2, 9, 4, 11, 8, 14, 6, 13);
    int result3 = min(12, 25, 12, 18, 5, 30, 14, 11, 9, 8, 7, 6, 5);

    cout << "Minimum of set 1: " << result1 << endl;
    cout << "Minimum of set 2: " << result2 << endl;
    cout << "Minimum of set 3: " << result3 << endl;

    return 0;
}
