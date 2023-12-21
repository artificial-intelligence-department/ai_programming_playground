#include <iostream> 
#include <cmath>
using namespace std;

int main(){
    double result=0.0, n, e=0.0001, x=1.0, a=0.0;
    cout << "Enter n:" <<endl;
    cin >> n;
    while (1){
        result += a;
        a=1/pow(x += 1,n);
        if (a < e){
            break;
        }
    }
    cout << result;
    return 0;
}


