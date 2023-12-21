//
// Created by olehio-p on 11/23/2023.
//
#include <iostream>


int main(int argc, char const *argv[])
{
    int height, width;
    std::cin >> height >> width;

    std::string cave[height];
    for(int i = 0; i < height; i++) {
        std::cin >> cave[i];
    }

    int occurrences;
    for (int i = height - 1; i > 0; i--) {
        for (int j = width - 1; j >= 0; j--) {
            if (cave[i][j] == 'O') {
                occurrences = 0;
                for (int k = i - 1; k >= 0; k--) {
                    if (cave[k][j] == 'S') {
                        cave[i-occurrences][j] = 'S';
                        cave[k][j] = 'O';
                        occurrences++;
                    } else if(cave[k][j] == 'X') {
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < height; i++) {
        std::cout << cave[i] << std::endl;
    }
    return 0;
}