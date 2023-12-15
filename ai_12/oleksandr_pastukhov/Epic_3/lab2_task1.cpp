#include<iostream>
#include<cmath>

int main(){
    using namespace std;
    double eps = 0.0001;
    double sum = 0;
    double an = 1;
    int n = 2;

    for(n;an > eps;n++){
        an = an*(n/(pow(n-1,2)));
        sum += an;
    }
    cout << sum;
    return 1;
}