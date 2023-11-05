#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main(){
    double sum = 0.25;
    double a;
    int e = 0.0001;

    for(int n = 1 ; n  > e; n++){
        a = 1.0 / ((3.0*n-2)*(3.0*n+1));
        sum += a;
    }

    cout << sum << endl;
    
    return 0;

}
