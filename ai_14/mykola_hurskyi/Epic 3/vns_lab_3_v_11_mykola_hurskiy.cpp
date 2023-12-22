#include <iostream>
#include <cmath> 
using namespace std;

int fact(int n){
    int res;
    if(n == 1){
        return 1;
    }
    res = n * fact(n - 1);
    return res;
}

int main () {
    double x, a = 0.1, b = 1, k = 10, epsi = 0.0001, SN, SE, y;
    int N = 10;

    for(double x = a; x <= b; x += (b-a)/k)
    {
        SN = 0;
        for(int n = 1; n <= N; n++){
            SN += ((2*n + 1)/fact(n)) * pow(x, 2*n);
        }
        for(int n = 1; n <= N; n++){
            SE += ((2*n + 1)/fact(n)) * pow(x, 2*n);
            if(SE > epsi ){
                continue;
            }
            else{
                break;
            }
        }
        y = (1 + 2 * pow(x,2))* exp(pow(x,2));
    
        cout << "X = " << x  << "\tSN = " << SN  << "\tSE = " << SE << "\tY= " << y << endl;
    }
    return 0;
}