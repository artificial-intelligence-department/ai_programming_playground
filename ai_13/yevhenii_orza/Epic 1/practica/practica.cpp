#include <cstdio>
#include <cmath>
#include <iostream>

int main(){

    double pricipal;
    double rate;
    int time;
    int period;
    //int result;
    char name[32];
    printf ("Enter your name:\n");
    scanf ("%s", name);

    printf ("Enter your pricipal:\n");
    scanf ("%lf", &pricipal);
    printf ("Enter your rate:\n");
    scanf ("%lf", &rate);
    printf ("Enter number of years:\n");
    scanf ("%d", &time);
    printf ("Enter the number of times interest is compouded:\n ");
    scanf ("%d", &period);

    // A= P(1 + r/n)^nt
    double A;
    double d;
    d = 1+(rate/period);
    A = pow(d, period*time);
    double m = period*d;

    std::cout<<  "Hello " << name << " the compound interest for a principal of " << pricipal << " at a rate " << rate << "%\n" << " compounded " << period << " times a year for " << time << " \nis : " << A << " The total amount is " << A+pricipal << std::endl;
    // printf("Hello", &name, "the compound interest for a principal of", &p, "at a rate", &r, "%\n");
    // printf ( "compounded", &n, "times a year for", &t, 
    //  "\nis : ", &A, "The total amount is ", A+p); 
  return 0;
}