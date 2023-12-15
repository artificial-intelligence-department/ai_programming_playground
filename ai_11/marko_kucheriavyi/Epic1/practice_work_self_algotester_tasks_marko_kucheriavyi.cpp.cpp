#include <iostream>
using namespace std;
int main(){
    int number, factorial = 1;
    cout << "Enter the number: ";
    cin >> number;
    for (int i = 1; i < number + 1; i++){
        factorial = factorial * i;
    }
    cout << "factorial = " << factorial;
    return 0;
}