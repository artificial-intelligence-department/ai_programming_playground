#include <iostream>
#include <cstdarg>
using namespace std;
int sum(int k, ...) {
    int result = 0;
    va_list args;
    va_start(args, k);
    for (int i = 0; i < k; i++) {
        int a = va_arg(args, int);
        result += (i % 2 == 0) ? a : -a;
    }
    va_end(args);
    return result;
}
int main() {
    int result1 = sum(5, 1, 2, 3, 4, 5);
    cout << "Sum with 5 parameters: " << result1 << endl;

    int result2 = sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    cout << "Sum with 10 parameters: " << result2 << endl;

    int result3 = sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
    cout << "Sum with 12 parameters: " << result3 << endl;

    return 0;
}
