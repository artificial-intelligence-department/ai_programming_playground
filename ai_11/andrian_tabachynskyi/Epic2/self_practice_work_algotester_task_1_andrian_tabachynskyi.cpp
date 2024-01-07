#include <iostream>

using namespace std;

int main() {
    long long H, M;
    cout << "Please write the value of H=";
    cin >> H;
    cout << "\nPlease write the value of M=";
    cin >> M;
    for (int i = 0; i < 3; i++) {

        long long h, m;
        cout << "\nPlease write the value of h=";
        cin >> h;
        cout << "\nPlease write the value of m=";
        cin >> m;
        if (h > 0 && m > 0) {
            cout << "NO" << endl;
            exit(0);
        }
        else {
            H = H - h;
            M = M - m;
        }
    }


    if (H > 0 && M > 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

}


/*if (H - h >= 0 && M - m >= 0) {
    H = H - h;
    M = M - m;
}
else {
    cout << "NO" << endl;
}*/