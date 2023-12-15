#include <iostream>
#include <cmath>
#include <cstdarg>

bool in_circle(int x, int y, int R) {
    int d = sqrt(x * x + y * y);
    return d <= R;
}

int belong(int R, int n, ...) {
    va_list args;
    va_start(args, n);

    int counter = 0;

    for (int i = 0; i < n; i++) {
        int x = va_arg(args, int);
        int y = va_arg(args, int);

        if (in_circle(x, y, R)) {
            counter++;
        }
    }

    va_end(args);
    return counter;
}

int main() {

    int result1 = belong(5, 3, 1,0, 2,0, 3,0);
    std::cout << "Number of points belonging to the circle: " << result1 << std::endl;

    int result2 = belong(10, 9, 1,6, 2,0, 3,13, 4,9, 5,11, 6,0, 7,0, 8,7, 7,6);
    std::cout << "Number of points belonging to the circle: " << result2 << std::endl;

    int result3 = belong(15, 11, 0,16, 3,4, 4,3, 5,12, 6,8, 8,23, 9,12, 6,0, 7,0, 8,19, 7,6);
    std::cout << "Number of points belonging to the circle: " << result3 << std::endl;

    return 0;
}


