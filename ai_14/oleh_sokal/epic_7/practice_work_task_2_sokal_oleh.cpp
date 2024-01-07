#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double x = 2.0;
    double result = 0;
    for(int i=1; i<=10; i++){
        result += pow(x, i)/i;
    }
    cout << result;
    return 0;
}