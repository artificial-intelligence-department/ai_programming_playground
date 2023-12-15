#include <iostream>
#include <cstdarg>

int min(int n, ...) {
    va_list VL;
    va_start(VL, n);
    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        int cur = va_arg(VL, int);
        if (cur < min) min = cur;
    }
    va_end(VL);
    return min;
}

int main( ) {
    std::cout << min(5, 1, 100, -3, -1, 24) << '\n';
    std::cout << min(10, 0, 5, 7, 13234, -6921, 4, 88888888, -103834, -1, -4826) << '\n';
    std::cout << min(12, 9, -412, 4235342, 7561995, 0, 1, 64, -174, 587, 6, -927867, 10) << '\n';
    return 0;
}
