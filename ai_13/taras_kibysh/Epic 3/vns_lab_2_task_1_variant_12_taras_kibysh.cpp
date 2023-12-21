#include <iostream>
#include <cmath>
int main(){
using namespace std;
bool repeat = true;
double a = 2, sum = 2, n = 1;
double e = 0.0001;
while(repeat){


a = a* (2*pow(n,n))/(pow(n+1,n));
if (a< e)
repeat = false;

sum += a;






n++;

}

cout  << sum;
return 0;



}