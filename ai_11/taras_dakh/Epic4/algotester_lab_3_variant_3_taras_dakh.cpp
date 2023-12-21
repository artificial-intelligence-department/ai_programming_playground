#include <iostream>
#include <string>

std::string compressString(const std::string& s) {
    std::string compressed;
    int count = 1;

    for (size_t i = 1; i <= s.size(); ++i) {
        if (i < s.size() && s[i] == s[i - 1]) {
            count++;
        } else {
            compressed += s[i - 1] + (count > 1 ? std::to_string(count) : "");
            count = 1;
        }
    }

    return compressed;
}

int main() {
    std::string inputString;
    std::cin >> inputString;

    std::string compressedString = compressString(inputString);

    std::cout << compressedString << std::endl;

    return 0;
}