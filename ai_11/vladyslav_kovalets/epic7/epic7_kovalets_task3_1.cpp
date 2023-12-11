#include <iostream>

int main()
{
    long double volt, Ohm, Amperage;

    std::cout << "Voltage (volt) > ";
    std::cin >> volt;

    std::cout << "Resistance (Ohm) > ";
    std::cin >> Ohm;

    Amperage  = volt/Ohm;
    std::cout << "Amperage: " << Amperage;
}