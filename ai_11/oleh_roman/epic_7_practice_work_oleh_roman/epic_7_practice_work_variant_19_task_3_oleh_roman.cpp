#include <iostream>
#include <cmath>

double AreaOfTriangle(double x1, double y1,double x2, double y2,double x3, double y3);
double length(double x, double y, double x2, double y2);



int main(){
    double x1, y1, x2, y2, x3, y3, area;

    std::cout << "Введіть координати кутів трикутника" << std::endl;

    std::cout << "(x1,y1) = ";
    std::cin >> x1 >> y1;

    std::cout << "(x2,y2) = ";
    std::cin >> x2 >> y2;

    std::cout << "(x3,y3) = ";
    std::cin >> x3 >> y3;

    area =  AreaOfTriangle(x1, y1, x2, y2, x3, y3);
    std::cout << "Area of your triangle is equal to = " << area;
    return 0;
}


double AreaOfTriangle(double x1, double y1,double x2, double y2,double x3, double y3){
    double length1 = length(x1, y1, x2, y2);
    double length2 = length(x2, y2, x3, y3);
    double length3 = length(x3, y3, x1, y1);

    double p = (length1 + length2 + length3) / 2;
    return sqrt(p * (p - length1) * (p - length2) * (p - length3));
}

double length(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}