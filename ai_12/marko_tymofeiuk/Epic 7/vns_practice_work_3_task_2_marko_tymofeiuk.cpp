#include <iostream>

int main(){
    long double R, V, I;

    std::cout << "Enter the value of voltage (V): ";
    std::cin >> V;

    std::cout << "Enter the value of current (I): ";
    std::cin >> I;

    R = V/I;
    std::cout << R << " - value of resistance (R).";
}