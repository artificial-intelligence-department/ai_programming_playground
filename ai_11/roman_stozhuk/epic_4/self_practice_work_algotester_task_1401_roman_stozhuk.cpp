#include <iostream>
#include <vector>

int main() {
    long n, count = 0;
    std::vector<long> a;
    std::cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i != 0) {
            if ((!(a[i]%2) && (a[i-1]%2)) || (!(a[i-1]%2) && (a[i]%2))) count++;
        }
    }
    std::cout << count;
    return 0;
}