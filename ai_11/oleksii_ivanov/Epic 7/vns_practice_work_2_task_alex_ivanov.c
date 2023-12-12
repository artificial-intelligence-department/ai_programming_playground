#include <stdio.h>
#include <math.h>

// Epsilon is defined to compare double values
// and to avoid floating point errors
// (define is a preprocessor directive that declares a macro here)
#define epsilon 1e-6

// Calculate the value by formula
// cos(x^2) * e^(-x)
double y(double x) {
    return cos(pow(x, 2)) * exp(-x);
}

int main() {
    // constant variables are calculated during runtime
    // and disallow to change their values
    const double    lower_bound = 0.3, upper_bound = 5.0,
                    step = 0.1;

    double          x = lower_bound;

    // alternates is a counter of the number of times function changes its sign
    int alternates = 0;

    // prev_y is the value of y(x) at the previous step
    // curr_y is the value of y(x) at the current step
    double prev_y = y(x), curr_y;
    // printf("x = %lf, y(x) = %lf\n", x, prev_y);

    // compare double values avoiding floating point errors
    while (x <= upper_bound + epsilon) {
        curr_y = y(x);
//        printf("x = %lf, y(x) = %lf\n", x, curr_y);

        // If the product of the previous and current y values is negative,
        // then the y values alternate between positive and negative.
        if (prev_y * curr_y < 0) alternates++;

        x += step;
        prev_y = curr_y;
    }

    // Print the result
    printf("The function y(x) alternates between "
           "positive and negative %d times "
           "in the interval [%.1lf, %.1f].\n",
           alternates, lower_bound, upper_bound);

    return 0;
}
