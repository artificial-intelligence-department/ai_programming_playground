#include <stdio.h>  
int main()
{
    long long h[4];
    long long d[4];   
    scanf("%lld %lld %lld %lld",&h[0], &h[1], &h[2], &h[3]);
    for (int i=0; i<4; ++i){
    scanf("%lld",&d[i]);
    }
    int error = 0;
    int result = 1;
    for (int i=0; i<4; ++i){
        h[i]=h[i]-d[i];
        if(h[i]<0){
            error = 1;
        }
        long long max = h[0];
        for (int i=0; i<4; ++i){
        if(h[i]>max){
            max=h[i];
        }
        }
        if(h[i]*2<=max){
            result = 0;
        }
    }
    if(error == 1){
        printf("ERROR");
    }
    else if(result == 1){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
