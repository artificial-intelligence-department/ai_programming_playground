#include <stdio.h>
// may include math.h, but I defined abs(x) as a macro myself
#define abs(x) ((x) < 0 ? -(x) : (x))

// Epsilon is defined to compare double values
#define epsilon 1e-6

int main() {
    // constant variables are calculated during runtime
    const double    lower_bound = -4, upper_bound = 4, step = 0.5;
    double          x = lower_bound, y;

    // separator is a string that is used to separate table rows
    const char* separator = "+-----------------------+\n";

    // Print table head
    printf("%s", separator);
    printf("|  x\t|\t y\t|\n");
    printf("%s", separator);

    // Print table rows
    while (x <= upper_bound + epsilon) {
        // Calculate absolute value of x
        y = abs(x);
        // Print table row
        printf("|%.2lf\t|\t%.2lf\t|\n", x, y);
        // Increase x by step
        x += step;
    }

    // Print table bottom
    printf("%s", separator);

    return 0;
}
