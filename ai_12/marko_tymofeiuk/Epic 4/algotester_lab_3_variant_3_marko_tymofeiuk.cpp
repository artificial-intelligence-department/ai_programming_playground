#include <iostream>
#include <string>

std::string compressString(const std::string &input) {
    std::string compressed;
    int count = 1;

    for (int i = 0; i < input.length(); i++) {
        if (i < (input.length()-1) && input[i] == input[i + 1]) {
            count++;
        } else if (count>1){
            compressed += input[i] + std::to_string(count);
            count = 1;
        } else {
            compressed += input[i];
            count = 1;
        }
        }
    return (compressed);
}

int main() {
    std::string input;
    std::cin >> input;

    std::string compressed = compressString(input);

    std::cout << compressed;

    return 0;
}
