#include <stdio.h>
#include <cstdlib>
void sered(int arr[], float sum=0){
    for (int i = 0; i < 10; i++){
        sum+=arr[i]/10.0;
    }
    printf("The average sum of 10 elements is %.1lf\n", sum);
}

int main(){
    int p1[10], p2[10], p3[10];
    for (int i = 0; i < 10; i++){
        p1[i]=1+rand()%10;
        p2[i]=1+rand()%10;
        p3[i]=1+rand()%10;
    }

    for (int i = 0; i < 10; i++){
        printf("%d ", p1[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++){
        printf("%d ", p2[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++){
        printf("%d ", p3[i]);
    }
    printf("\n");

    float sum1 = 0, sum2 = 0, sum3 = 0;
    sered(p1, sum1);
    sered(p2, sum2);
    sered(p3, sum3);
    return 0;
}