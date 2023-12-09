#include <stdio.h>
#include <math.h>
#include <fcntl.h>

void set_utf8() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

double area(double a, double b, double angle_degrees) {
    return 0.5 * a * b * sin(angle_degrees * M_PI / 180);
}

int main() {
    set_utf8();

    double a, b, angle;

    wprintf(L"Введіть (через пропуск) довжини двох сторін (см) трикутника: ");
    wscanf(L"%lf %lf", &a, &b);

    wprintf(L"Введіть величину кута між сторонами трикутника (градуси): ");
    wscanf(L"%lf", &angle);

    wprintf(L"Площа трикутника: %.2lf (см^2)\n", area(a, b, angle));

    return 0;
}
