#include<iostream>
#include<string>
#include <cmath>
using namespace std;

int main()
{
    int a = 1000;
    double b = 0.0001;
    double c = (pow((a+b),3)-(pow(a,3)+(3*pow(a,2)*b)))/((3*a*pow(b,2))+pow(b,3));
    cout << c <<endl;
    
    return 0;
}