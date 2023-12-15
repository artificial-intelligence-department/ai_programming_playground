#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const double e = 2.7;
    double a,x;
    int n;
    cout << "Enter your n: " << endl;
    cin >> n;
    //обчислення чисел від 1 до n
    for (int i = 1; i <= n; i++)
    {
        a = pow(e,-sqrt(i));
        //додає обчислення значення а до x
        x = x + a;
        cout << a <<endl;
        
    }
        cout << x << " result" << endl;
}