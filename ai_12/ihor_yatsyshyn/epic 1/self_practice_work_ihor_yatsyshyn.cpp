#include <iostream>
//код задачі на Algotester - 011
int main() {
    long long n, sum;
    std::cin >> n;
    if(n < 1 || n > 100000){
        return 1;
    }

    long long a[n];
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        if(a[i] < 0 || a[i] > 10000){
            return 1;
        }
    }

    for(int i = 0; i < n; i++){
        sum += a[i] - 1;
    }

    std::cout << sum;

    return 0;
}
