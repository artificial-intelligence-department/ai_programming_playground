#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long time = 0, n;
    long mx_x = 0, mx_y = 0;
    std::cin >> n;

    std::vector<long> x(n), y(n);
    for (int i = 0; i < n; i++) { std::cin >> x[i] >> y[i]; }

    mx_x = *max_element(begin(x), end(x));
    mx_y = *max_element(begin(y), end(y));

    for (int i = 0; i<n; i++) {
        time += mx_x - x[i];
        time += mx_y - y[i];
    }
    std::cout << time;
    return 0;
}