//
// Created by olehio-p on 12/10/2023.
//
#include <iostream>
#include <cstdlib>

int main(int argc, char const *argv[])
{
    int ranges[3][10];
    srand(time(nullptr));

    for(auto& range : ranges) {
        for(int& elem : range) {
            elem = 1 + rand() % 10;
        }
    }

    double average;
    for(int i = 0; i < 3; i++) {
        average = 0;
        printf("The sequence #%d: ", i + 1);
        for(int j = 0; j < 10; j++) {
            std::cout << ranges[i][j] << " ";
            average += ranges[i][j];
        }
        std::cout << std::endl;
        printf("The average of the sequence #%d: %.2f\n", i + 1, average / 10);
    }

    return 0;
}
