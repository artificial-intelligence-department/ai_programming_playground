//
// Created by olehio-p on 10/30/2023.
//
#include <iostream>


int main(int argc, char const *argv[])
{
    int n;
    std::cin >> n;
    int array[n];
    int drone1Pos, drone2Pos;
    for(int i = 0; i < n; i++) {
        std::cin >> array[i];
    }


    drone1Pos = 0;
    drone2Pos = n - 1;
    while(drone1Pos <= drone2Pos) {
        if(drone1Pos == drone2Pos) {
            std::cout << drone1Pos + 1 << " " << drone2Pos + 1 << std::endl;
            std::cout << "Collision" << std::endl;
            return 0;
        } else if(abs(drone1Pos - drone2Pos) == 1) {
            std::cout << drone1Pos + 1 << " " << drone2Pos + 1 << std::endl;
            std::cout << "Stopped" << std::endl;
            return 0;
        }
        drone1Pos += array[drone1Pos];
        drone2Pos -= array[drone2Pos];
    }
    std::cout << drone1Pos + 1 << " " << drone2Pos + 1 << std::endl;
    std::cout << "Miss" << std::endl;
    return 0;
}
