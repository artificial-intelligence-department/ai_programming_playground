#include <iostream>
#include <cmath>
using namespace std;

int main() {
    char name[30];
    double p, r, t, c ;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter the principal amount: ");
    scanf("%lf", &p);  
    printf("Enter the rate of interest (in percentage): ");
    scanf("%lf", &r);  
    printf("Enter the number of years: ");
    scanf("%lf", &t);  
    printf("Enter the number of times interest is compounded per year: ");
    scanf("%lf", &c);
    double result, ci;
    result = p * pow(1 + (r / (100*c)), c * t);
    ci = p * pow(1 + (r / (100*c)), c * t);
    cout << "Hello, " << name << "!" << endl;
    //cout << "The compound interest for a principal of " << p << " at a rate of " << r * 100 << "% "<< "compounded " << c << " times a year for " << t << " years is: " << ci << endl;//
    //cout << "The total amount after " << t << " years is: " << result << endl;//
    printf("The compound interest for a principal of %lf", p);
    printf(" at a rate of %lf",  r * 100 );
    printf("%");
    printf(" compounded %lf", c);
    printf(" times a year for %lf", t);
    printf(" years is:  %lf", ci);
    printf(" The total amount after  %lf", t);
    printf(" years is:  %lf", result);
    return 0;
}
