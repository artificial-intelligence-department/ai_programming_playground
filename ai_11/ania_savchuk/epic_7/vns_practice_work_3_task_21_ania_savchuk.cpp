#include <iostream>
using namespace std;

int main(){
    double r1, r2, r;
    cout << "Enter r1:  ";
    cin >> r1;
    cout << "Enter r2:  ";
    cin >> r2;

    r = r1 + r2;

    cout << "Result: " << r << endl;

    double deposit, years;
    cout << "Enter deposit: ";
    cin >> deposit;

    cout << "Enter years: ";
    cin >> years;

    double new_deposit = deposit;
    for (years = 0; years < 2; years++){
        new_deposit = new_deposit * 1.03;
    }

    cout << "New deposit: " << new_deposit;
    return 0;
}