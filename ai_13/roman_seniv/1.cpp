#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int years, number;
    float principal, rate, compoundInterest;
    string name;

    cout << "Enter your name: " << endl;
    cin >> name;

    cout << "Enter the principal amount: " << endl;
    cin >> principal;

    cout << "Enter the rate of interest (e.g., 0.05 if it is 5%): " << endl;
    cin >> rate;

    cout << "Enter the number of years: " << endl;
    cin >> years;

    cout << "Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): " << endl;
    cin >> number;

    compoundInterest = principal * pow(1 + (rate / number), number * years);

    cout << "Hello " << name << "!" << endl;
    cout <<"The compound interest for a principal of " <<principal << "at a rate of " <<rate << " compounded " <<number << " times a year for " <<years << " years is " << compoundInterest - principal << endl;
    cout <<"The total amount after " << years << " years is " << compoundInterest << endl;

    return 0;
}