#include <iostream>
#include <cmath>

int main() {
    double radius;
    double height;

    std::cout << "Calculation of the surface area of the cylinder." << std::endl;
    std::cout << "Enter the initial data:" << std::endl;

    std::cout << "Base radius (cm) > ";
    std::cin >> radius;

    std::cout << "Cylinder height (cm) > ";
    std::cin >> height;

    double surfaceArea = 2 * M_PI * radius * (radius + height);

    std::cout << "Surface area of the cylinder: " << surfaceArea << " square cm" << std::endl;

    return 0;
}