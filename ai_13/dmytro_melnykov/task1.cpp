#include <cstdio>
#include <cmath>
#include <iostream>




int main(){


int n; // period
double p; //pricial
double r; //rate 
int t; // time
char name[50];



printf ("Enter your Name:\n");
scanf ("%s" ,name);

printf ("Enter your pricipial:\n");
scanf ("%lf" ,&p);

printf ("Enter your percent:\n");
scanf ("%lf", &r);

printf ("Enter time:");
scanf ("%u" , &t);

printf ("Enter the number of times interest: ");
scanf ("%udi",&n);

double A = p*pow((1+(r/n)),n*t);

printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", p, r * 100, n, t, A );

















}
