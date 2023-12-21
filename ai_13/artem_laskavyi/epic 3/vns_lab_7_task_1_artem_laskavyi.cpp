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
    vector<int> prime;
    va_list args; 
    va_start(args, count); 
    
    for (int i = 0; i < count; i++) {
        Interval a = va_arg(args, Interval);

        for (int num = a.start; num <= a.end; num++) {
            if (isPrime(num)) {
                prime.push_back(num);
            }
        }
    }

    va_end(args); 
    return prime;
}

int main() {
    
    vector<int> arg3 = prost(2, Interval{4, 11}, Interval{15, 19});
    vector<int> arg5 = prost(4, Interval{27, 34}, Interval{19, 19}, Interval{41, 56}, Interval{34, 60});
    vector<int> arg6 = prost(5, Interval{111, 121}, Interval{145, 167}, Interval{11, 21}, Interval{150, 196}, Interval{49, 80});
    
    sort(arg3.begin(), arg3.end());
    sort(arg5.begin(), arg5.end());
    sort(arg6.begin(), arg6.end());
    
    cout << "Prime numbers (3 arguments): ";
    for (int prime : arg3) {
        cout << prime << " ";
    }
    cout << endl << "Prime numbers (5 arguments): ";
    for (int prime : arg5) {
        cout << prime << " ";
    }
    cout << endl << "Prime numbers (6 arguments): ";
    for (int prime : arg6) {
        cout << prime << " ";
    }

    return 0;
}
