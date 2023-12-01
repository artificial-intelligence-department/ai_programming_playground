

#include <iostream>
#include <cstdarg>
#include <cmath>
using namespace std;
double length(double x1, double y1, double x2, double y2)
{
    double l = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    return l;
}
double area(double a, double b, double c)
{
    double p = (a + b + c) / 2;
    double ar = sqrt(p * (p - a) * (p - b) * (p - c));
    return ar;
}
bool belongtriangle(double xP, double yP, double xA, double yA, double xB, double yB, double xC, double yC)
{
    double area1 = area(length(xA, yA, xB, yB), length(xA, yA, xP, yP), length(xB, yB, xP, yP));
    double area2 = area(length(xB, yB, xC, yC), length(xB, yB, xP, yP), length(xC, yC, xP, yP));
    double area3 = area(length(xC, yC, xA, yA), length(xC, yC, xP, yP), length(xA, yA, xP, yP));
    double bigarea = area(length(xA, yA, xB, yB), length(xA, yA, xC, yC), length(xB, yB, xC, yC));
    if (fabs(bigarea - (area1 + area2 + area3)) < 0.0001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool belongpolygon(double xP, double yP,int k ...)
{
    va_list list;
    va_start(list, k);
    double* x = new double[k+1];
    double* y = new double[k+1];
    double* areas = new double[k];
    double sumareas = 0;
    double bigarea;
    for (int i = 0; i < k; i++)
    {
        x[i] = va_arg(list, double);
        y[i] = va_arg(list, double);
    }
    x[k] = x[0];
    y[k] = y[0];
    for (int i = 0; i < k; i++)
    {
        areas[i] = area(length(x[i], y[i], x[i + 1], y[i + 1]), length(x[i], y[i], xP, yP), length(x[i + 1], y[i + 1], xP, yP));
    }
    double e1 = 0;
    double e2 = 0;
    for (int i = 0; i < k - 2; i++)
    {
        e1 = e1 + x[i] * y[i + 1];
        e2 = e2 + y[i] * x[i + 1];
    }
    bigarea = abs(e1 - e2 + x[k - 1] * y[0] - x[0] * y[k - 1]);
    for (int i = 0; i < k; i++)
    {
        sumareas = sumareas + areas[i];
    }
    cout << "The sum of areas of triangles is " << sumareas << endl;
    cout << "The area of the polygon is " << bigarea << endl;;
    if (abs(bigarea - sumareas) < 0.0000001)
    {
        return true;
    }
    else
    {
        return false;
    }
}



int main()
{
    bool belong = belongpolygon(14.0, 6.0, 4, 0.0, 0.0, 0.0, 13.0, 13.0, 13.0, 13.0, 0.0);
    if (belong)
    {
        cout << "The point is in the polygon";
    }
    else
    {
        cout << "The point is out of the polygon";
    }
}


