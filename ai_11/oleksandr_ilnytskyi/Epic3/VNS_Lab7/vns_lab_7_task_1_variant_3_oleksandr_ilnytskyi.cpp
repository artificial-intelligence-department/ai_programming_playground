#include <iostream>
#include <cstdarg>

using namespace std;

int wholeSum(int pcount, ...) {
    int result = 0;

    va_list args;
    va_start(args, pcount);

    int lastUsed = 0;

    for (int i = 0; i < pcount - 1; i++) {
        if (i == 0) {
            int cur = va_arg(args, int);
            int next = va_arg(args, int);
            result += cur*next;
            cout << result << endl;
            lastUsed = next;
        }
        else {
            int next = va_arg(args, int);
            result += lastUsed * next;
            lastUsed = next;
            cout << result << endl;
        }
    }

    va_end(args);
    return result;
}

int main() {
    int sum1 = wholeSum(5, 3, 5, 6, 7, 8);
    cout << "Result 1 is: " << sum1;
    int sum2 = wholeSum(10, 3, 5, 6, 7, 8, 3, 5, 6, 7, 8);
    cout << "Result 2 is: " << sum2;
    int sum3 = wholeSum(10, 3, 5, 6, 7, 8, 3, 5, 6, 7, 8, 6, 2);
    cout << "Result 3 is: " << sum3;

    return 0;
}
