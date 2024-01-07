#include <iostream>
#include <set>
#include <algorithm>

int main() {
    size_t n, k;
    std::cin >> n >> k;

    std::multiset<size_t> doors, brushes;

    for (int i = 0; i < n; i++) {
        size_t temp;
        std::cin >> temp;
        doors.insert(temp);
    }

    for (int i = 0; i < k; i++) {
        size_t temp;
        std::cin >> temp;
        brushes.insert(temp);
    }

    size_t sum = 0;

    for (int i = 0; i < n; i++) {
        auto maxdoor = std::prev(doors.end());
        auto maxbrush = std::prev(brushes.end());

        auto doormax = *maxdoor;
        auto brushmax = *maxbrush;

        size_t temp = doormax * brushmax;
        sum += temp;

        doors.erase(maxdoor);
        brushes.erase(maxbrush);
        brushes.insert(brushmax - 1);
    }

    std::cout << sum;

    return 0;
}
