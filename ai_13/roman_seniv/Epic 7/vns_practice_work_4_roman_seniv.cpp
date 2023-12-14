#include <iostream>

using namespace std;

int main() {
     int n = 7;
     int rows = 10; 

    cout << "Multiplication Table for " << n << ":\n\n";


    for (int i = 1; i <= rows; ++i) {
        int result = n * i;
        cout << "  " << i << "  |  " << result << "\n";
    }

    return 0;
}
