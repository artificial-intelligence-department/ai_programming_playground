#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false; 
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; 
        }
    }
    return true; 
}


vector<int> sieveOfEratosthenes(int b) {
    vector<bool> isPrime(b + 1, true); 
    vector<int> newPrime; 

    isPrime[0] = isPrime[1] = false; 
    for (int i = 2; i * i <= b; ++i) {
        if (isPrime[i]) {
            newPrime.push_back(i); 
            for (int j = i * i; j <= b; j += i) {
                isPrime[j] = false; // Викреслюємо всі кратні числа простого числа
            }
        }
    }

    // Додаємо решту простих чисел після обчислення кореня
    for (int i = max(2, int(sqrt(b) + 0.5) + 1); i <= b; ++i) {
        if (isPrime[i]) {
            newPrime.push_back(i); 
        }
    }

    return newPrime;
}

int main() {
    int n;

    cout << "Введіть верхню межу (n): ";
    cin >> n;

    vector<int> primes = sieveOfEratosthenes(n);

    cout << "Прості числа до " << n << ": ";
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}
