#include <iostream>
#include <vector>

std::vector<int> primeFactors(int n) {
    std::vector<int> primes;
    int candidate = 2;

    while (n > 1) {
        while (n % candidate == 0) {
            primes.push_back(candidate);
            n /= candidate;
        }
        candidate++;
    }

    return primes;
}

int main() {
    using namespace std;
    int number;

    cout << "Enter your number: ";
    cin >> number;

    vector<int> result = primeFactors(number);

    cout << "Prime factors:  " << number << ": ";
    for (int prime : result) {
         cout << prime << " ";
    }
    cout <<  endl;

    return 0;
}