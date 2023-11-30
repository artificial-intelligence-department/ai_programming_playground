#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int maxTeeth = 0;
    int currentTeeth = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            currentTeeth++;
        } else {
            currentTeeth = 0;
        }

        maxTeeth = std::max(maxTeeth, currentTeeth);
    }

    std::cout << maxTeeth << std::endl;

    return 0;
}