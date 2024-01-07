#include <cstdarg>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;  
        }
    }
    return true; 
}

struct Interval {
    int start;
    int end;
};

vector<int> prost(int count, ...) {
    vector<int> primeNumbers;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; ++i) {
        Interval interval = va_arg(args, Interval);

        for (int num = interval.start; num <= interval.end; ++num) {
            if (isPrime(num)) {
                primeNumbers.push_back(num);
            }
        }
    }

    va_end(args);
    return primeNumbers;
}

int main() {
    vector<int> result1 = prost(3, Interval{2, 10}, Interval{15, 25}, Interval{30, 40});
    vector<int> result2 = prost(5, Interval{50, 60}, Interval{70, 80}, Interval{90, 100}, Interval{110, 120}, Interval{130, 140});
    vector<int> result3 = prost(6, Interval{150, 160}, Interval{170, 180}, Interval{190, 200}, Interval{210, 220}, Interval{230, 240}, Interval{250, 260});

    sort(result1.begin(), result1.end());
    sort(result2.begin(), result2.end());
    sort(result3.begin(), result3.end());

    cout << "Prime numbers (3 intervals): ";
    for (int prime : result1) {
        cout << prime << " ";
    }
    cout << endl << "Prime numbers (5 intervals): ";
    for (int prime : result2) {
        cout << prime << " ";
    }
    cout << endl << "Prime numbers (6 intervals): ";
    for (int prime : result3) {
        cout << prime << " ";
    }

    return 0;
}
