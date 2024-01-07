// as the 25th variant doesn't exist in this task, the 1st variant was done
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
        // TASK 1
    cout << "\tTask 1 - find the volume of the parallelepiped\n";

    double a, b, c;
    cout << "Enter the initial data:\n";
    cout << "Length(cm): ";
    cin >> a;
    cout << "Width(cm): ";
    cin >> b;
    cout << "Height(cm): ";
    cin >> c;
    double V = a * b * c;
    cout << "Volume: " << V << " cubic cm\n";

        // TASK 2
    cout << "\n\tTask 2 - convert pounds to kilograms\n";

    double weight_lb;
    cout << "Enter the weight you want to convert from lb to kg:\n";
    cout << "Pounds:    ";
    cin >> weight_lb;
    double weight_kg = weight_lb * 0.453592;
    cout << "Kilograms: " << weight_kg;
}