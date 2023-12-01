#include <cmath>
#include <cstdio>
#define a 1000
#define b 0.0001

int main() {
    float res;

    res = (pow(a + b, 2) - (pow(a, 2) + 2*a*b))/(pow(b, 2));

    printf("%f", res);

    return 0;
}