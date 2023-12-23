#include <stdio.h>
#include <fcntl.h>          // _setmode and _O_U8TEXT
// 1 cubic meter - 1 000 000 cubic centimeters
#define BOLT_VOLUME 2e-6    // macroconstant for bolt volume

// set UTF-8 mode to print Ukrainian characters
void set_utf8() {
    _setmode(_fileno(stdout), _O_U8TEXT);
    _setmode(_fileno(stdin), _O_U8TEXT);
}

// calculate the number of bolts in a box (H - height, B - breadth, S - width)
double calc_bolt_count(double H, double B, double S) {
    double box_volume = H * B * S;
    return box_volume / BOLT_VOLUME;
}

int main() {
    set_utf8();

    // read input
    double H, B, S;
    wprintf(L"Введіть висоту, ширину та глибину ящика (м, в одному рядку): ");
    wscanf(L"%lf %lf %lf", &H, &B, &S);

    // calculate and print result
    double bolt_count = calc_bolt_count(H, B, S);
    wprintf(L"Максимальна кількість болтів у ящику: %.2lf\n", bolt_count);

    return 0;
}
