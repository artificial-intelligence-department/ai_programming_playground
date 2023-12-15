#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main()
{

double a = 1000;
double b = 0.0001;

cout << ((pow((a-b),3))-(pow(a,3)-3*pow(a,2)*b))/(pow(b,3)-(3*a*pow(b,2)));

}

