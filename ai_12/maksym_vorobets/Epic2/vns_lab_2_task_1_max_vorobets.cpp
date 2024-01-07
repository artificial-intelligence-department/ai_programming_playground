#include <stdio.h>

int main(){
    int x=0;
    for(int i=1; i<200; i+=2)
     {
        x+=i;
    }
     printf("Сума цілих додатніх непарних чисел, менших за 200: %d\n", x);

    return 0;
}