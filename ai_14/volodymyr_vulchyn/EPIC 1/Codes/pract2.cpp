#include <iostream>
#include <string>
#include <math.h>




int main(){
    std::string name;
    double pricipal, rate, total_amount, a ;
    int year, period ;

    std::cout << "Enter your name: " ;
    std::cin >> name;
    
    std::cout << "Enter the principal amount: ";
    std::cin >> pricipal;
    
    std::cout << "Enter the rate of interest (in percentage): ";
    std::cin >> rate;
    
    std::cout << "Enter the number of years: ";
    std::cin >> year;
    
    std::cout << "Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ";
    std::cin >> period;


    total_amount = pricipal * pow((1+ (rate/100) / period) , (period * year));
    a = total_amount - pricipal;

    std::cout << "Hello, " << name << "\n"; 
    std::cout << "The compound interest for a principal of " << pricipal << " at a rate of " << rate << "% compounded " << period << " times a year for " << year << " years is " << a << "\n";
    std::cout << "The total amount after 3 years is: " << total_amount << "\n";     





    return 0;
}