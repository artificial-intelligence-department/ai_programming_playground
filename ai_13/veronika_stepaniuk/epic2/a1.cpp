#include<iostream>
#include<Windows.h>
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<cmath>


int main()

{
	SetConsoleOutputCP (1251);
	SetConsoleCP (1251);
	float a=100, b=0.001, c, d, e;
    c=powf(a-b,4)-(powf(a,4)-4*powf(a,3)*b);
    d=6*powf(a,2)*powf(b,2)-4*a*powf(b,3)+pow(b,4);
    e=c/d;
    printf("float: %f", e);

	double a1=100, b1=0.001, c1, d1, e1;
    c1=pow(a1-b1,4)-(pow(a1,4)-4*pow(a1,3)*b1);
    d1=6*pow(a1,2)*pow(b1,2)-4*a1*pow(b1,3)+pow(b1,4);
    e1=c1/d1;
    printf("\ndouble: %lf", e1);

	return 0;
}