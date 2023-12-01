#include <iostream>
#include <cmath>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    char name [30];
    int years, n;
    double principal, rateOfInterest, compounded;
    
      cout << "Enter your name";
           cin >> name;
      cout << "Enter the principal amount:";
           cin >> principal;
      cout << "Enter the rate of interest (in percentage):";
           cin >> rateOfInterest;
      cout << "Enter the number of years:";
           cin >> years;
      cout << "Enter the number of times interest is compounded per year :";
           cin >> n  ;

    rateOfInterest = rateOfInterest /100;
    double total =principal * pow(1+rateOfInterest/n, n*years);
    compounded = total - principal;

           cout << "\nHello, " << name << "!" << endl;
           cout << "The compound interest for a principal of " << principal << " at a rate of " << rateOfInterest * 100 << "% componded " << n << " times a year for " << years << " years is: " << compounded << endl;
           cout << "The total amount after " << years << " years is: " << total << endl;

    

    return 0;
}