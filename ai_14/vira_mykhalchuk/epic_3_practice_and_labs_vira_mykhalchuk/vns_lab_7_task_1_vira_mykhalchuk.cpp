#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

const double PI = 3.14159265358979323846;

double areaOfTriangle(double a, double b, double c)
{
    if ((a + b > c) && (a + c > b) && (b + c > a))
    {
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else
    {
        cout << "Invalid sides for a triangle!\n";
        return 0.0;
    }
}

double areaOfPolygon(int sides, ...)
{
    va_list args;
    va_start(args, sides);
    double area = 0.0;

    if (sides < 3)
    {
        cout << "The number of sides is incorrect!\n";
        return 0.0;
    }
    else
    {
        double sideLengths[sides];

        for (int i = 0; i < sides; i++)
        {
            sideLengths[i] = va_arg(args, double);
        }

        double sumOfAreas = 0.0;
        for (int i = 0; i < sides; i++)
        {
            int x = (i + 1) % sides;
            sumOfAreas += sideLengths[i] * sideLengths[x];
        }

        area = 0.5 * sumOfAreas * sin(2 * (PI / sides));
    }

    va_end(args);

    return area;
}

int main()
{
    double side1, side2, side3;

    cout << "Enter the lengths of sides of triangle: ";
    cin >> side1 >> side2 >> side3;

    double areaTriangle = areaOfTriangle(side1, side2, side3);
    cout << "The area of triangle is: " << areaTriangle << '\n';

    double area1 = areaOfPolygon(3, 3.0, 4.0, 5.0);
    cout << "The area of triangle is: " << areaTriangle << '\n';

    double area2 = areaOfPolygon(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    cout << "The area of pentagon is: " << area2 << '\n';

    double area3 = areaOfPolygon(8, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    cout << "The area of octagon is: " << area3 << '\n';

    return 0;
}