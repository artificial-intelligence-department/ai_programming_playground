#include <iostream>
using namespace std;

int main(){
    double n1, n2, n3, n4, n5;
    // скануєм вхідні дані
    cin >> n1 >> n2 >> n3 >> n4 >> n5;
    // обчислюєм результат
    double result = (n1+n2+n3+n4+n5)/5;
    // виводим результат
    cout << result;

    return 0;
}