#include <iostream>
#include <string>

std::string compressString(const std::string& s) {
    std::string compressed;
    int count = 1;
    
    for (int i = 0; i < s.length(); i++) {
        // Порівнюємо поточний символ з наступним
        if (s[i] == s[i+1]) {
            count++;
        } else {
            // Якщо символ вже зустрічається багато разів, додаємо його до результуючої стрічки
            if (count > 1) {
                compressed += s[i] + std::to_string(count);
            } else {
                compressed += s[i];
            }
            count = 1;
        }
    }
    
    return compressed;
}

int main() {
    std::string s;
    std::cin >> s;
    
    std::string compressedS = compressString(s);
    std::cout << compressedS << std::endl;
    
    return 0;
}
