#include <iostream>
#include <stack>

int main() {
    int n;
    std::cin >> n;

    std::stack<int> stickers;
    int sadnessCount = 0;

    for (int i = 0; i < n; ++i) {
        int operation;
        std::cin >> operation;

        if (operation == 1) {
            stickers.push(1); 
        } else {
            if (!stickers.empty()) {
                stickers.pop(); 
            } else {
                sadnessCount++; 
            }
        }
    }

    std::cout << sadnessCount << std::endl;

    return 0;
}
