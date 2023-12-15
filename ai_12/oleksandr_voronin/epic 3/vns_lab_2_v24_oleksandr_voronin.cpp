#include <iostream>
#include <cmath>
using namespace std;

int main(){
    const double e = 2.7;
    double a,b;
    int n;
    cout << "Enter your n: " << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    // цикл від 1 до 9
    {
        a= pow(e,-sqrt(i));
        b +=  a;
        cout << a <<endl;
        
    }
        cout << b << " result" << endl;
}