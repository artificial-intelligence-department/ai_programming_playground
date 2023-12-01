#include <cstdio>
#include <math.h>

int main() {
    double res = 0;
    
    for(int n = 0; n <= 7; ++n){
        res += pow(n, 2) * exp(-pow(n, 0.5));
    }

    printf("The summ of the series equals %lf.", res);

    return 0;
}