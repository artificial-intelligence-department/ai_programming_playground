#include <cmath>
#include <iostream>
#include <cstdio>

//char name[50];

using namespace std;

int main(){

double a = 1000;
double b = 0.001;

double d = pow(a + b,3) - pow(a,3);
double c = 3*a*pow(a,2) + pow(b,3) + 3*pow(a,2)*b;
double e = d/c;

float k = 1000;
float f = 0.001;

float j = pow(k +f,3) - pow(k,3);
float g = 3*a*pow(k,2) + pow(f,3) + 3*pow(k,2)*f;
float z = j/g;


cout<<(e)<<endl;
cout<<(z)<<endl;



}

