#include <iostream>

int main() {
    long long n, k, maxs = 0, currents = 0;
    std::cin >> n >> k;

    long long a[n];

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for(int i = 0; i < n; i++) {
        if(a[i] >= k){
            currents++;
            maxs = std::max(maxs, currents);
        }else{
            currents = 0;
        }
    }

    std::cout << maxs;

    return 0;
}
