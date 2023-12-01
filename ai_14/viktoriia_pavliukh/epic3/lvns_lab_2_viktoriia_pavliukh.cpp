#include <iostream>
#include <cmath>

using namespace std;


int main(){
    int n = 13, factorialSum = 1;
    double rowSum = 0.0, a_n = 1.0;
    for(int i = 1; i <= n; i++){
        factorialSum = 1;
        for (int j = 1; j <= n; j++) {
            factorialSum *= j;
        }
        a_n *= ( (pow(i, 2)) *( (1/pow(i + 1, 2)) + ( (log(i+1))/(pow(i + 1, 2) *log(factorialSum)) ) ) );
        rowSum += a_n;
    }
    cout << "Sum of row: " << rowSum << endl;

}
