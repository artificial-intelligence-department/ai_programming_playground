#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int num, fac = 1;
    printf("Enter number: ");
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++) {
        fac = fac * i;
    }
    
    printf("factorial = %d", fac);
    return 0;
}