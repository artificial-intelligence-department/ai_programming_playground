#include <iostream>

int main() {
    std::cout << "Calculation of the volume of a parallelepiped.\n";
    std::cout << "Enter the length, width and height of the parallelepiped (in centimeters) in one line.\n";
    std::cout << "Separate the numbers with spaces.\n";

    double length, width, height;
    std::cin >> length >> width >> height;

    double volume = length * width * height;
    std::cout << "Answer " << volume;

    return 0;
}
