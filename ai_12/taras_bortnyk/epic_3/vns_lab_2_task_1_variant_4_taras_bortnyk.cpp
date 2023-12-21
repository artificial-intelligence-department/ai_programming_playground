#include <iostream>

using namespace std;

int main() {
    int start = 21;
    int end = 99;

    int n = (end - start) / 3 + 1; 
    int sum = (n * (start + end)) / 2; 

    cout << "sum: " << sum;
}
