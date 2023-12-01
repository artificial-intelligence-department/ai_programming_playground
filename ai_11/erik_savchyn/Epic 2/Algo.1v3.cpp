#include <iostream>
using namespace std;
int main() {
    long long a[6];
    a[0] = 1000000000000;
    for(int i = 1; i < 6; i++){
        cin >> a[i];
        if(a[i] <= 0){
            cout << "ERROR";
            return 0;
        }
        if (a[i] > a[i-1]){
            cout << "LOSS";
            return 0;
        }
    }
    cout << "WIN";
    return 0;
}