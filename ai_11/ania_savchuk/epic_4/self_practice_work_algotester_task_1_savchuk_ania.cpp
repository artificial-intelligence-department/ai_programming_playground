#include <iostream>
using namespace std;

int main() {
    long long sides[5];

    
    for (int i = 0; i < 5; ++i) {
        cin >> sides[i];
        
        if (sides[i] <= 0) {
            cout << "ERROR";
            return 0;
        }
        else if (sides[i-1] < sides[i]) {
            cout << "LOSS";
            return 0;
        }
    }

    cout << "WIN";
    return 0;
}