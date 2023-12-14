//v-10
#include <iostream>

int main() {
    int U, R; // U напруга, R опір
    float I; // I струм
    char answer[5]; // answer - the answer from the keyboard

    do{ // doing the loop fot multiple calculations
        std::cout << "Enter U: ";
        std::cin >> U;

        std::cout << "Enter R: ";
        std::cin >> R;

        I = (float)U / R; // convert U to float to get float result

        std::cout << "I = " << I << "\n";
        
        std::cout << "Do you want to continue? (yes/no): ";
        std::cin >> answer; //if the answer is yes, the program will start again

    }while (answer[0] == 'y'); // short way to check if the answer is yes

    std::cout << "Goodbye!\n"; // when the answer is no, the program will end

    return 0;
}