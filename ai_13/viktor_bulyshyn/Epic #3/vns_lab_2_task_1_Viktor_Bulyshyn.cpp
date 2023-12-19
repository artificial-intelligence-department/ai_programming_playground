#include <iostream>
#include <cmath>

using namespace std;


unsigned long long factorial(int n) {

if (n == 0) {

     return 1;

} else {

     return n * factorial(n - 1);
}
}

int main () {

    float n;
    float d = 0;

    cout << "Enter num n" << endl;
    cin >> n;

    if (n < 0) {

        cout << "theres no factorial of 0" << endl;

    } else {

        unsigned long long result_factorial = factorial(n);

         float a = result_factorial;

         float b = 3*pow(n,n);

         float c = a/b;

    
    
    for (
    int i = 1;
    i <= n;
    i++ ) {
        d = d + c;
    }
    

cout<<"Result is:"<< endl << d;
    }
return 0;

}