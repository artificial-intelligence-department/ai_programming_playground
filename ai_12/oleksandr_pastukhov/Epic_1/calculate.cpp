
#include<cstdio>
#include<cmath>
using namespace std;


int main(){
char name[50];
double principal, rate, total;
int time, n;
printf("Enter your name:\n");
scanf("%s", &name);

printf("enter the principal amount:\n");
scanf("%lf", &principal);

printf("enter the rate of interest:\n");
scanf("%lf", &rate);

    rate= rate/100;

printf("enter the number of years:\n");
scanf("%d", &time);

printf("enter the number of times interest is compouded per year(e.g., 1 for annually, 4 for quarterly, 12 for monthly: \n");
scanf("%d", &n);

    total= principal*pow(1+(rate/n), n*time);
    double compound = total - principal;

printf("The compound interest for a principal of %.2f at a rate of %.2f%% compounded %d times a year for %d years is: %.2f\n", principal, rate * 100, n, time, compound);

        printf("total amount is %lf", total);
}

/*
#include<iostream>
#include<cmath>
#include<string>

int main() {
    using namespace std;
    string name;
    double principal, rate, time, n;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the rate of interest (in percentage): ";
    cin >> rate;
    cout << "Enter the number of years: ";
    cin >> time;
    cout << "Enter the number of times interest is compounded per year: ";
    cin >> n;

    rate /= 100;  
    double amount = principal * pow(1 + rate / n, n * time);

    cout << "Hello, " << name << "!" << endl;
    cout << "The compound interest for a principal of " << principal << " at a rate of " << rate * 100 << "% compounded " << n << " times a year for " << time << " years is: " << amount - principal << endl;
    cout << "The total amount after " << time << " years is: " << amount << endl;

    return 0;
}
*/