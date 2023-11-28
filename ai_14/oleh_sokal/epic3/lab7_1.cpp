#include <stdio.h>
#include <stdarg.h>
#include <math.h>

int pointInCircle(double x, double y, double R) {
    double distance = sqrt(x * x + y * y);
    return distance <= R;
}

int belong(int R, int numPoints, ...) {
    int count = 0;

    va_list args;
    va_start(args, numPoints);

    for (int i = 0; i < numPoints; i++) {
        double x = va_arg(args, double);
        double y = va_arg(args, double);

        if (pointInCircle(x, y, R)) {
            count++;
        }
    }

    va_end(args);

    return count;
}

int main() {
    int R = 100;

    int count1 = belong(R, 3, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0);
    printf("Number of points belonging to the circle with 3 parameters: %d\n", count1);

    int count2 = belong(R, 5, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0);
    printf("Number of points belonging to the circle with 9 parameters: %d\n", count2);

    int count3 = belong(R, 6, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0);
    printf("Number of points belonging to the circle with 11 parameters: %d\n", count3);

    return 0;
}
