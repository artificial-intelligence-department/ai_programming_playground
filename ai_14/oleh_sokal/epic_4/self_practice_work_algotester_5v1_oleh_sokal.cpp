#include <iostream>
using namespace std;

int main() {
    unsigned long long n;
    char arr[64] = {0};
    unsigned long long a;
    unsigned long long b = 0;
    int untouchablePlace;
    int correctPlace;
    int rows, columns;
    cin >> a;
    cin >> n;
    
    for (int i = 0; i < 64; i++) {
        if ((a >> i) & 1) {
            arr[i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> rows >> columns;
        untouchablePlace = (rows - 1) * 8 + columns - 1;
        arr[untouchablePlace] = (arr[untouchablePlace] == 1) ? 0 : 1;

        for (int j = 0; j < 8; j++) {
            correctPlace = j * 8 + columns - 1;
            if (correctPlace != untouchablePlace) {
                arr[correctPlace] = (arr[correctPlace] == 1) ? 0 : 1;
            }
        }

        for (int j = 0; j < 8; j++) {
            correctPlace = (rows - 1) * 8 + j;
            if (correctPlace != untouchablePlace) {
                arr[correctPlace] = (arr[correctPlace] == 1) ? 0 : 1;
            }
        }
    }
    for (int i = 63; i >= 0; i--) {
        if (arr[i] == 1) {
            b |= (1ULL << i);
        }
    }

    cout << b << endl;
    return 0;
}



