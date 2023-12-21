//
// Created by olehio-h on 11/23/2023.
//
#include <iostream>
#include <cmath>
#include <cstdarg>


double areaOfTriangle(double, double, double);
int perimeter(int,...);

int main(int argc, char const *argv[])
{
    std::cout << areaOfTriangle(3, 4, 5) << std::endl;
    std::cout << "Perimeter is: " << perimeter(3, 3, 4, 5) << std::endl;
    std::cout << "Perimeter is: " << perimeter(5, 3, 4, 5, 6, 7) << std::endl;
    std::cout << "Perimeter is: " << perimeter(8, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
    return 0;
}

double areaOfTriangle(double a, double b, double c) {
    if(a > b + c || b > a + c || c > a + b) {
        return -1;
    }

    double halfOfPerimeter = (a + b + c) / 2;
    double area = sqrt(halfOfPerimeter
                    * (halfOfPerimeter - a)
                    * (halfOfPerimeter - b)
                    * (halfOfPerimeter - c));

    return area;
}

int perimeter(int n,...) {
    va_list vargs_ptr;
    va_start(vargs_ptr, n);
    int perimeter = 0;

    while(n--) {
        perimeter += va_arg(vargs_ptr, int);
    }
    va_end(vargs_ptr);
    return perimeter;
}