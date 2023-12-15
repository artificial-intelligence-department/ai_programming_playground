#include <iostream> 
#include <cmath> 
using namespace std; 
 
int main() { 
 
    double e = 0.0001; 
    double S = 0.00; 
    double a = 0.00; 
    int n = 0; 
 
    do { 
        a = (2 * n - 1) / pow(2, n); 
        S += a; 
        n++; 
    } while (abs(a) >= e); 
 
    cout << "The sum of the series with an accuracy of " << e << " equals " << S << endl; 
 
    return 0; 
}
