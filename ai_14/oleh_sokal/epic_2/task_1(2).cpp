#include <iostream>


using namespace std;


int main() {
    float n, m, result;
    int var;
   
    cout << "задача:(1,2,3)";
    cin >> var;


    if (var == 1) {
        cout << "n:";
        cin >> n;
        cout << "m:";
        cin >> m;
        n -= 1;
        result = n - m;
        cout << "результат виразу:" << result << endl;
        return 0;
    }


    if (var == 2) {
        cout << "n:";
        cin >> n;
        cout << "m:";
        cin >> m;
        m -= 1;
        if (m < n) {
            cout << "TRUE!" << endl;
            return 0;
        }
        if (m > n) {
            cout << "FALSE!" << endl;
            return 0;
        }
    }


    if (var == 3) {
        cout << "n:";
        cin >> n;
        cout << "m:";
        cin >> m;
        n += 1;
        if (m < n) {
            cout << "TRUE!" << endl;
            return 0;
        }
        if (m > n) {
            cout << "FALSE!" << endl;
            return 0;
        }
  }
   else {
        cout << "не та задача" << endl;
        return 0;
    }


    return 0;
}
