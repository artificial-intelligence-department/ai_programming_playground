#include <cstdio>
 int main(){
int value;
double result;


printf("how many friends you have?:");
scanf("%u", &value);
int a[value];
printf("write your  friends age(for example: 15  18 20):");
for (int i= 0 ; i < value; i++){
scanf("%u", &a[i]);
result = result + a[i]; 
}

result = result/value;
printf("the avarage age your friends is: %lf", result);



return 0;
 }