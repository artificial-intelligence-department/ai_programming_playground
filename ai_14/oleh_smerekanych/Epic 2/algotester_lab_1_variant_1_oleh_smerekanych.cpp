#include <iostream>
using namespace std;

int main() {
    long long H, M; 
    cin >> H >> M; 

    for (int i = 0; i < 3; i++) {
        long long hi, mi;
        cin >> hi >> mi; 

        if (hi > 0 && mi > 0) {
            cout << "NO" << endl;
            return 0;
        }

        H -= hi;
        M -= mi; 

        if (H <= 0 || M <= 0) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}