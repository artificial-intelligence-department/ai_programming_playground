#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double n;
    double sum=0;
cout << "Enter a number of n:";
cin >>n;
    for( int i=1;i<=n;i++){
double a=(pow((-1),i-1))/(pow(i,i));
sum += a;
    }
    cout << sum << "\n";
    return 0;
}