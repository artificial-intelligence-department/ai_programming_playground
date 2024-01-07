#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const int n = 13;
    double a[n];
    double sum = 0;
    int k, p;  //k - факторіал
    k = 1;
    p = 1;

    for(int i = 0; i < n; i++){
        k = k * p;
        a[i] = log(k) / pow(p, 2);
        sum += a[i];
        ++p;
    }

    cout << "The sum is " << sum << endl;
    return 0;
}