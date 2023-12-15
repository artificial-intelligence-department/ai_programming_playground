#include <iostream>
#include <cmath>
#include <cstdio>



using namespace std;

std::string name1;
double pricipal;
double rate;
int years;
int period;
double A;



int main()
{
    std::cout << "enter name ";
    std::cin >> name1;
    std::cout << "enter pricipal ";
    std::cin >> pricipal;
    std::cout << "enter rate ";
    std::cin >> rate;
    std::cout << "enter term ";
    std::cin >> years;
    std::cout << "enter time ";
    std::cin >> period;
    std::cout << (period*years) << endl;
    A = pricipal*pow((1+rate/100*period),(period*years));
    printf("%.2f",A);
    
}