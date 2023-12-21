#include <stdio.h>
#include <stdarg.h>
#include <math.h>

#define DISTANCE(x1, y1, x2, y2) \
  sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))

// https://cpp.mazurok.com/tag/%D0%BF%D0%BB%D0%BE%D1%89%D0%B0%D0%B4%D1%8C-%D0%BC%D0%BD%D0%BE%D0%B3%D0%BE%D1%83%D0%B3%D0%BE%D0%BB%D1%8C%D0%BD%D0%B8%D0%BA%D0%B0/

typedef struct {
    double x, y;
} Point;

Point create_point(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

double square_n(int n, ...);
double square(Point p1, Point p2, Point p3) {
    return square_n(3, p1, p2, p3);
}

int main() {
    // Suspected output: sqrt(5) ~ 2.236068
    printf("Distance between (2, 4) and (3, 2): %lf\n", DISTANCE(2, 4, 3, 2));

    // Suspected output: 2
    printf("Square area of triangle: %lf\n",
           square(create_point(0, 0), create_point(0, 2), create_point(2, 0)));

    // Suspected output: 339865
    printf("Square area of %d-gon: %lf\n", 4, square_n(
            4,
            create_point(-1000, 500),
            create_point(-500, 1000),
            create_point(2, 10),
            create_point(35, 60)
    ));

    // Suspected output: 124562.5
    printf("Square area of %d-gon: %lf\n", 10, square_n(
            10,
            create_point(51, -20),
            create_point(15, 3),
            create_point(45, 200),
            create_point(100, -100),
            create_point(201, 55),
            create_point(70, -80),
            create_point(25, 333),
            create_point(999, 0),
            create_point(500, 77),
            create_point(5, -6)
    ));

    // Suspected output: 1446
    printf("Square area of %d-gon: %lf\n", 5, square_n(
            5,
            create_point(13, -92),
            create_point(44, 0),
            create_point(-800, 30),
            create_point(27, 2),
            create_point(1, 2)
    ));

    return 0;
}

double square_n(int n, ...) {
    va_list args;
    va_start(args, n);

    Point   start = va_arg(args, Point),    // x0,      y0
            current = start,                // xi,      yi
            next;                           // xi+1,    yi+1

    double sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        next = va_arg(args, Point);
        // Calculate the area of a triangle using Shoelace formula
        sum += current.x * next.y - next.x * current.y;
        current = next;
    }
    sum += current.x * start.y - start.x * current.y;

    va_end(args);

    double result = fabs(sum) / 2;
    return result;
}