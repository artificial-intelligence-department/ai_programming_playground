#include <iostream>
#include <string>

bool isPalindrome(std::string string);
bool isPalindrome(int number);

int main () {
    std::string input1, operation;
    int input2;

    std::cout << "What do you want to check?" << std::endl;
    std::cin >> operation;

    if(operation == "string") {
        std::cout << "Enter the string: ";
        std::cin >> input1;
        isPalindrome(input1);

        if(isPalindrome(input1)) {
            std::cout << input1 << " is a palindrome" << std::endl;
        }else {
            std::cout << input1 << " is not a palindrome" << std::endl;
        }

    }else if(operation == "number"){
        std::cout << "Enter the number: ";
        std::cin >> input2;
        isPalindrome(input2);

        if(isPalindrome(input2)) {
            std::cout << input2 << " is a palindrome" << std::endl;
        }else {
            std::cout << input2 << " is not a palindrome" << std::endl;
        }

    }else {
        std::cout << "Invalid input";
    }

    return 0;
}

bool isPalindrome(std::string string) {
    int first = 0;
    int last = string.length() - 1;

    if(first < last){
        if (string[first] != string[last]){
            return false;
        }else {
            first++;
            last--;
            return isPalindrome(string.substr(first, last));
        }
    }

    return true;

}

bool isPalindrome(int number) {
    std::string str = std::to_string(number);
    return isPalindrome(str);
}