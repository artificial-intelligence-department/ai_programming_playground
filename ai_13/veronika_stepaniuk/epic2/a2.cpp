#include<iostream>
#include<Windows.h>
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<cmath>


int main()

{
	SetConsoleOutputCP (1251);
	SetConsoleCP (1251);
    float n, m;
    printf("n=?");
    scanf("%f",&n);
    printf("m=?");
    scanf("%f",&m);   
    float p1=++n*++m;
    float p2=m++<n;
    float p3=n++>m;
    printf("++n*++m=%f\nm++<n=%f\nn++>m=%f", p1, p2, p3);
    
	return 0;
}