#include <cstdio>
#include <cmath>

int main(){
    

double p; //Principal
double r; //Rate
int t; //time
int n; //period

char name[50];

printf ("Print your name");
scanf ("%s", name);

printf ("Enter your Principal");
scanf ("%lf", &p);

printf ("Enter you Rate");
scanf ("%lf", &r);

printf ("Enter number of years");
scanf ("%d", &t);

printf ("Enter number periods");
scanf ("%d", &n);

//input

double A = p*pow((1+(r/n)),n*t);

printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", p, r * 100, n, t, A);

//output

}