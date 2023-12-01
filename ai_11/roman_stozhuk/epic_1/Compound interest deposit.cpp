#include <iostream>  
#include <stdio.h>
using namespace std;

int main() {
    cout << "Input: \n" << endl;
    
    string name;
    cout << "Enter your name: ";
    cin >> name;
    
    double principal;
    cout << "Enter the principal amount: ";
    cin >> principal;
    
    double percent;
    cout << "Enter the rate of interest (in percentage): ";
    cin >> percent;
    
    int years;
    cout << "Enter the number of years: ";
    cin >> years;

    int per;
    cout << "Enter the number of times interest is compounded per year \n(e.g., 1 for annually, 4 for quarterly, 12 for monthly): ";
    cin >> per;

    double rate = (100 + percent) / 100;
    double final = principal;
    
    for (int a = 0; a < (years * per); a++) {
        final = final * rate;
    }

    cout << "\nOutput: \n" << endl;

    printf("Hello, %s!\nThe compound interest for a principal of %.2lf \nat a rate of %.2lf compounded %d times a year for %d years is: %.2lf\nThe total amount after %d years is: %.2lf", (name.c_str()), principal, percent, per, years, (final - principal), years, final);
    return 0;
}