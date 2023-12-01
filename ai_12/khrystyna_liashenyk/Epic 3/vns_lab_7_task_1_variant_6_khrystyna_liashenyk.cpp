#include <iostream>
#include <stdarg.h>

using namespace std;
int min(int count, ...) {
    va_list args;
    va_start(args, count);

    int min_value = va_arg(args, int);
    for (int i = 1; i < count; ++i) {
        int current = va_arg(args, int);
        if (current < min_value) {
            min_value = current;
        }
    }

    va_end(args);
    return min_value;
}

int main() {
    int res1 = min(5, 4, 6, 2, 8, 3);
    int res2 = min(10, 15, 7, 21, 11, 9, 13, 5, 18, 6, 12);
    int res3 = min(12, 32, 19, 25, 14, 28, 22, 17, 20, 23, 27, 24, 30);

    cout<<res1<<endl;
    cout<<res2<<endl;
    cout<<res3<<endl;
    return 0;
}
