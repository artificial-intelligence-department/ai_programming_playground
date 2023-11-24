//
// Created by olehio-p on 10/30/2023.
//
#include <iostream>
#include <cmath>


int main(int argc, char const *argv[])
{
    int ai;
    int cubeV, prevCubeV = INT_MAX;
    for(int i = 0; i < 5; i++) {
        std::cin >> ai;
        if(ai <= 0) {
            std::cout << "ERROR" << std::endl;
            return 0;
        }

        cubeV = pow(ai, 3);
        if(cubeV > prevCubeV) {
            std::cout << "LOSS" << std::endl;
            return 0;
        }
        prevCubeV = cubeV;
    }
    std::cout << "WIN" << std::endl;
    return 0;
}