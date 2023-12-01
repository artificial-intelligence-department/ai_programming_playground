#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double h {0.0001};
    double a {0};
    double step{0};
    int n = 1;
    do {
        step = (pow(-1, n-1)/pow(n,n));
        a += step;
        cout << a << endl;
        n++;
    } while(fabs(step)>h);

    cout<< "complete";
    return 0;
}
