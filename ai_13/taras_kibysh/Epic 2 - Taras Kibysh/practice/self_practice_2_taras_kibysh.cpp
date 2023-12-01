#include <cstdio>

int main() {
    long long int a1, a2, a3, a4, a5;
    scanf("%lli", &a1);
    scanf("%lli", &a2);
    scanf("%lli", &a3);
    scanf("%lli", &a4);
    scanf("%lli", &a5);

    

    if (a1 <= 0){
    printf("ERROR");
    return 0;
    }
    else if(a1 < a2){
    printf("LOSS");
    return 0;}




     if (a2 <= 0){
    printf("ERROR");
    return 0;}
    else if(a2 < a3){
    printf("LOSS");
    return 0;
    }




     if (a3 <= 0){
    printf("ERROR");
    return 0;
     }
    else if(a3 < a4){
    printf("LOSS");
    return 0;
    }



     if (a4 <= 0){
    printf("ERROR");
    return 0;
     }
    else if(a4 < a5){
    printf("LOSS");
    return 0;
    }
    else if (a5 <= 0){
    printf("ERROR");
    return 0;
    }

   
     printf("WIN");
    
return 0;

}

