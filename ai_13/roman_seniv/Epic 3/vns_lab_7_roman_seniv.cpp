#include <iostream>
#include <cstdarg>

using namespace std;

int sum(int k, ...) {
    va_list args;
    va_start(args, k);

    int result = 0;

    for (int i = 0; i < k - 1; ++i) {
        if (i % 2 == 0) {
            result += va_arg(args, int) * va_arg(args, int);

        } else {
            result -= va_arg(args, int) * va_arg(args, int);
        }
    }

    va_end(args);
    return result;
}

int main() {
    int result1 = sum(5, 1, 2, 3, 4, 5);
    cout << "Result for 5: " << result1 << "\n";

    int result2 = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << "Result for 10: " << result2 << "\n";

    int result3 = sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    cout << "Result for 12: " << result3 << "\n";

    return 0;
}