#include <iostream>

int main() {
    int k;
    std::string s, need = "TOILET";
    std::cin >> k >> s;
    size_t next = 0;
    while (k != 0) {
        auto found = s.find(need, next);
        if (found != std::string::npos) {
            next = found + 6;
            k--;
        }
        else {break;}
    }
    std::cout << (k == 0 ? "YES" : "NO");
    return 0;
}