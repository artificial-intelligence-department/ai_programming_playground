#include <stdio.h>
#include <stdarg.h>

int sum(int k, ...){
   int s = 0;
   int *p=&k;
   int a=*(++p);
   for(int i = 0; i < k-1; i++){
   int a1=*(++p);
   int a2=*(++p+1);
   s+=a1*a2;
   }
   return s;
}
int main() {
    int s5 = sum(5, 2, 3, 4, 5, 1);
    printf("S5=%d\n", s5);

    int s10 = sum(10, 1, 2, 3, 4, 2, 5, 1, 3, 7, 1);
    printf("S10=%d\n", s10);

    int s12 = sum(12, 2, 3, 4, 5, 6, 7, 8, 9, 2, 1, 2, 3);
    printf("S12=%d\n", s12);

    return 0;
}

