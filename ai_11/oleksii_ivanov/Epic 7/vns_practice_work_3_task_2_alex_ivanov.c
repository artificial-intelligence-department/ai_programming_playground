#include <stdio.h>
#include <fcntl.h>
// 1 cubic meter - 1 000 000 cubic centimeters
#define BOLT_VOLUME 2e-6

void set_utf8() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

double calc_bolt_count(double H, double B, double S) {
    double box_volume = H * B * S;
    return box_volume / BOLT_VOLUME;
}

int main() {
    set_utf8();

    double H, B, S;
    wprintf(L"Введіть висоту, ширину та глибину ящика (м, в одному рядку): ");
    wscanf(L"%lf %lf %lf", &H, &B, &S);

    double bolt_count = calc_bolt_count(H, B, S);
    wprintf(L"Максимальна кількість болтів у ящику: %.2lf\n", bolt_count);

    return 0;
}
