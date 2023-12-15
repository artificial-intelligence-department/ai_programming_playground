#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;
// варіант 22

double areaOfTriangle(double a, double b, double c)
{
    double p = (a + b + c)/2.0;
    return sqrt(p * (p-a) * (p-b) * (p-c));
}

double square(int sides, ...)
{
    va_list args;
    va_start(args, sides);
    double area = 0.0;

    if(sides < 3)
    {
        cout << "The number of sides is incorrect!" << endl;
        return 0.0;
    }
    else if(sides == 3)
    {
        double side1 = va_arg(args, double);
        double side2 = va_arg(args, double);
        double side3 = va_arg(args, double);

        double p2 = (side1 + side2 + side3) / 2;
        area = sqrt(p2 * (p2 - side1) * (p2 - side2) * (p2 - side3));
    }
    else
    {
        int SIZE = sides;
        double areaPolygon;
        double sideLengths[SIZE];

        for(int i = 0; i < SIZE; i++)
        {
            sideLengths[i] = va_arg(args, double);
        }

        double sumOfAreas = 0.0;
        for(int i = 0; i < sides; i++)
        {
            int j = (i+1) % sides; 
            sumOfAreas += sideLengths[i] * sideLengths[j];
        }

        areaPolygon = 0.5 * sumOfAreas * sin(2 * (3.1415 / sides));
        area = areaPolygon;
    }

    va_end(args);

    return area;
}

int main()
{
    double side1, side2, side3;
    double Side1, Side2, Side3;

    cout << "Enter the lengths of sides of triangle: ";
    cin >> side1 >> side2 >> side3;

    double areaTriangle = areaOfTriangle(side1, side2, side3);
    cout << "The area of triangle is: " << areaTriangle << endl;

    double area1 = square(3, 3.0, 4.0, 5.0);
    cout << "The area of triangle is: " << area1 << endl;

    double area2 = square(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    cout << "The area of pentagon is: " << area2 << endl;

    double area3 = square(8, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0);
    cout << "The area of octagon is: " << area3 << endl;

    return 0;
}
