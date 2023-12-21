#include <iostream> 
#include <cmath>
using namespace std;


int main () {
    
    unsigned int n=1;
    double factorial=1;
    double an;
    double sum=0;
    
    cout << "Enter n: ";
    cin >> n;
  
    for (int i=1; i<=n; i++) {

        factorial*=i;

        an = factorial/pow(i,i);
        sum += an;
    }

    cout << sum;
    

    return 0;
}