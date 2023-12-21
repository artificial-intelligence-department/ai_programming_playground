#include <iostream>
#include <cmath>
using namespace std;
  
static const double EPSILON = 0.0001;
 
int main() {
    double sum = 0;
    double An;
 
    for (int n = 2; true ; n++) {
        An = n / pow(n - 1, 2);
 
        if (An < EPSILON) break;
        sum += An;
    }
 
    cout << sum;
}
