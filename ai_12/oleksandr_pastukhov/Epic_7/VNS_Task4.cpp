#include<iostream>

int main(){
    using namespace std;

    double x1,x2,x3,x4,x5;

    cout << "Введіть x1: ";
    cin >> x1;

    cout << "Введіть x2: ";
    cin >> x2;

    cout << "Введіть x3: ";
    cin >> x3;

    cout << "Введіть x4: ";
    cin >> x4;

    cout << "Введіть x5: ";
    cin >> x5;

    double average = (x1+x2+x3+x4+x5)/5;

    cout << "Середнє арифметичне введених чисел: " << average << endl;

    return 0;

}