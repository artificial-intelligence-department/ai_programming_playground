#include<iostream>

using namespace std;

int main(){

    int n;
    double sum;

    sum = 1;//У моєму варіанті перший член ряду дорівнює 1, отже це і буде початкове значення

    cout << "\nInput n:";
    cin >> n;

    for(int i=0; i < n; i++){
        sum = sum + 3*(n+1)/(3*n+1)*sum;
        cout << "\n sum rn = " << sum;
    }

    cout << "\nSum: " << sum << endl;



    return 0;
}