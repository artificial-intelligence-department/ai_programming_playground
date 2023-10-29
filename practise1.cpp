#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string name;
    int compoundInterest;
    int years;
    double rate;
    double amount=0;
    double result;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the principal amount:";
    cin >> amount;
    cout << "Enter the rate of interest (in percentage): ";
    cin >> rate;
    cout << "Enter the number of years: ";
    cin >> years;
    cout << "Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly):";
    cin >> compoundInterest;

    result = amount * pow((1+(rate/(100*compoundInterest))), years*compoundInterest)- amount;

    cout << "Hello, "<< name <<"!" << endl;

    printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", amount, rate, years, compoundInterest, result);

    return 0;

}