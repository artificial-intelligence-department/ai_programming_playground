#include <iostream>
#include <cmath>

int main() 
{
    double a0, p, fr, n;
    std::cout<<"Enter your name: ";
    std::string name;
    std::cin>>name;
    std::cout<<"Enter the principal amount: ";
    std::cin>>a0;
    std::cout<<"Enter the annual interest rate (in percentage): ";
    std::cin>>p;
    std::cout<<"Enter the number of times interest is compounded per year (e.g., 1 for annually, 4 for quarterly, 12 for monthly): ";
    std::cin>>fr;
    if(fr!=1&&fr!=4&&fr!=12)
    {std::cout<<"Wrong input. Try again and chooose one of the following: 1 for annually, 4 for quarterly, 12 for monthly";
    return 0;}
    std::cout<<"Enter the number of years: ";
    std::cin>>n;

    double amount=a0*pow(1+((p/100)/fr), fr*n);
    std::cout<<"Hello, "<<name<<"!";
    std::cout<<"\nThe compound interest for a principal of " <<a0<<" at a rate of "<<p<<"% compounded "<<fr<<" times a year for "<<n<<" years is: "<<(amount-a0);
    std::cout<<"\nThe total amount after "<<n<<" years is: "<<amount;

    return 0;
}