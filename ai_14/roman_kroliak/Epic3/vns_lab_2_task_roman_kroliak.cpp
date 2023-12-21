#include <iostream>
using namespace std;
int main() {
    int sum = 0;
    for (int i = 0; i < 100; i+=2) sum+=i;
    cout << "Sum even (1-100): " << sum;
    return 0;
}
