//
// Created by olehio-p on 12/10/2023.
//
#include <iostream>

double areaOfTriangle(const int*);

int main(int argc, char const *argv[])
{
    int coords[6];

    for(int i = 0; i < 6; i += 2) {
        std::cout << "Please enter the coors of the triangle vertex: ";
        std::cin >> coords[i] >> coords[i + 1];
    }
    printf("The area of the triangle is %.2f\n", areaOfTriangle(coords));

    return 0;
}

double areaOfTriangle(const int* coords) {
    double area = 0;

    for(int i = 0; i < 6; i += 2) {
        if(i + 3 < 6) {
            area += coords[i] * coords[i + 3];
        } else {
            area += coords[i] * coords[1];
        }

    }

    for(int i = 1; i < 6; i += 2) {
        if(i + 1 < 6) {
            area -= coords[i + 1] * coords[i];
        } else {
            area -= coords[0] * coords[i];
        }
    }

    return std::abs(area / 2);
}