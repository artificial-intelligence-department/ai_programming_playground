#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n=1;
    double e=0.0001;
    double sum = 0.0;
    while (right){
        double term=pow(n+1,3)/ (3*n);

        if (term < e)
          break;
        sum += term;
        n++;
    }
    cout << "The sum:" << sum << endl;
    return 0;
}