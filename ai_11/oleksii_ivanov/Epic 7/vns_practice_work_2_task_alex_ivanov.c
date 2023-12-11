#include <stdio.h>
#include <math.h>

#define epsilon 1e-6

double y(double x) {
    return cos(pow(x, 2)) * exp(-x);
}

int main() {
    double  lower_bound = 0.3, upper_bound = 5.0,
            step = 0.1,
            x = lower_bound;

    int alternates = 0;

    double prev_y = y(x), curr_y;
    // printf("x = %lf, y(x) = %lf\n", x, prev_y);
    while (x <= upper_bound + epsilon) {
        curr_y = y(x);
//        printf("x = %lf, y(x) = %lf\n", x, curr_y);

        // If the product of the previous and current y values is negative,
        // then the y values alternate between positive and negative.
        if (prev_y * curr_y < 0) alternates++;

        x += step;
        prev_y = curr_y;
    }

    printf("The function y(x) alternates between "
           "positive and negative %d times "
           "in the interval [%.1lf, %.1f].\n",
           alternates, lower_bound, upper_bound);

    return 0;
}
