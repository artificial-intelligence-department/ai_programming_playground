#include <iostream>
#include <string>

using namespace std;

int main() {
    const int n = 5;
    long long numbers[n];
    string check;

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] <= 0) {
            cout << "ERROR" << endl;
        }
            exit(0);
        if (numbers[i] > numbers[i -1] ){
            check = "LOSS";
            exit(0);
        }
    }


    
    cout << check << endl;

    return 0;
}
