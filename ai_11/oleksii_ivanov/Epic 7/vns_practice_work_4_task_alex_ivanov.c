#include <stdio.h>
// may include math.h, but
#define abs(x) ((x) < 0 ? -(x) : (x))

#define epsilon 1e-6

int main() {
    double  lower_bound = -4, upper_bound = 4, step = 0.5,
            x = lower_bound, y;

    char* separator = "+-----------------------+\n";

    printf("%s", separator);
    printf("|  x\t|\t y\t|\n");
    printf("%s", separator);

    while (x <= upper_bound + epsilon) {
        y = abs(x);
        printf("|%.2lf\t|\t%.2lf\t|\n", x, y);
        x += step;
    }

    printf("%s", separator);

    return 0;
}
