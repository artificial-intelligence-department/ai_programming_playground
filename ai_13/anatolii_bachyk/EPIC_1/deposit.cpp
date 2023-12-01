#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main () {

string name;
int principal_amount, number, times, interest;
float sum_1, sum_2;
cout << "Enter your name:" << endl;
    cin >> name;
cout << "Enter the principal amount:" << endl;
    cin >> principal_amount;
cout << "Enter the rate of interest:" << endl;
    cin >> interest;
cout << "Enter the number of years:" << endl;
    cin >> number;
cout << "Enter the number of times interest is compounded per year:" << endl;
    cin >> times;

    sum_1=principal_amount * pow((1+(0.01*interest/times)), number*times) ;
    sum_2=sum_1- principal_amount;


    cout << "Hello, " << name << "!" << endl;
    cout << "The compound interest for a principal of " << principal_amount << " at a rate of " << interest << "% compounded " << times << " times a year for " << number << " years is: "<< sum_2 << ". The total amount after " << number << " years is: " << sum_1 << endl;   
    return 0;
}