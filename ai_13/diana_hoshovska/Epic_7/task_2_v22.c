#include <stdio.h>
#include <math.h>

int main(){
    int x, y;
    int R;

    printf("Enter radius: ");
    scanf("%d", &R);

    for (int i = 0; i < 5; i++){
        printf("Point ", i+1, ": ");
        scanf("%d", &x);
        scanf("%d", &y);

        int K = sqrt(x*x+y*y);
        if (R==K){
            printf("Point %d is in circumference.\n", i+1);
        }
        else{
            printf("Point %d is not in circumference.\n", i+1);
        }

    }
    return 0;
}