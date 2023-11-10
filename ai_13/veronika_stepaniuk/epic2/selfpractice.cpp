#include<iostream>
#include<stdio.h>
#include<cmath>

int main()
{
    unsigned long int su, sd, v, tu, td;
    scanf("%lu %lu %lu", &sd, &su, &v);
    if(sd>100000||su>100000||v>100000)
    return 0;
    tu=su/(v/2);
    td=sd/(v*2);
    if(tu>td)
    printf("Down");
    else if(tu<td)
    printf("Up");
    else
    printf("Never mind");

    return 0;
}