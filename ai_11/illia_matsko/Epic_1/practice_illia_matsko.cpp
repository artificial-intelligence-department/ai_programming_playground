#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double sum, rate;
    int time;
    string name;

    cout << "Your name: ";
    cin >> name;
    cout << "Please enter deposit amount: ";
    cin >> sum;
    cout << "Please, enter amount of years: ";
    cin >> time;
    cout << "Please, enter rate: ";
    cin >> rate;

    printf("%lf %d", sum * pow((1 + rate * 0.01), time), time);
}