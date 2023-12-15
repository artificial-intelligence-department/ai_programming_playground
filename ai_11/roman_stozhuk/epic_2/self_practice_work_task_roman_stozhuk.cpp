#include <iostream>

int main() {   
    long long cubes[5];
    bool win = true;

    for (short i = 0; i<5; i++) {
        std::cin >> cubes[i];
    }

    for (short i = 1; i<5; i++) {
        if (cubes[i] <= 0 || cubes[i-1] <= 0) {
            std::cout << "ERROR";
            win = false;
            break;
        }
        else if(cubes[i] > cubes[i-1]) {
            std::cout << "LOSS";
            win = false;
            break;
        }
    }

    if (win) {
        std::cout << "WIN";
    }
    return 0;
}