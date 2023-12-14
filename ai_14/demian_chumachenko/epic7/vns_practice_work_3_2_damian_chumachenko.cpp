//v-10
#include <iostream>

int main() {
    double a, b, c, d; // a, b, c, d - the values from the keyboard
    char answer[5]; // answer - the answer from the keyboard

    do{ // doing the loop for multiple calculations
        std::cout << "Enter the values from the keyboard: ";
        std::cin >> a >> b >> c >> d;

        double difference = a * b - c * d;
        std::cout << "The difference between the products is: " << difference << '\n';

        std::cout << "Do you want to continue? (yes/no): ";
        std::cin >> answer; //if the answer is yes, the program will start again

    }while (answer[0] == 'y'); // short way to check if the answer is yes

    std::cout << "Goodbye!\n"; // when the answer is no, the program will end

    return 0;
}