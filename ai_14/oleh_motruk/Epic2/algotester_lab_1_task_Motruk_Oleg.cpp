#include <iostream>

using namespace std;

int main() {
    long long numbers[5];

    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
        if (numbers[i] <= 0) {
            cout << "ERROR" << endl;
            exit(0);
        }
        if (numbers[i] > numbers[i - 1] ){
            cout << "LOSS";
            exit(0);
        }
    }
    cout << "WIN";

    

    return 0;
}
