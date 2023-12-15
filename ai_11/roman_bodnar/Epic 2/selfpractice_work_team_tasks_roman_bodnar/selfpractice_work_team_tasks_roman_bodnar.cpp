#include <iostream>
using namespace std;

int main() {
    // if
    int a = 10;
    if (a > 0) {
        cout << "a > 0" << endl;
    }

    // if else
    int b = -10;
    if (b > 0) {
        cout << "b > 0" << endl;
    } else {
        cout << "b <= 0" << endl;
    }

    // switch
    char c = 'a';
    switch (c) {
        case 'a':
            cout << "c == 'a'" << endl;
            break;
        case 'b':
            cout << "c == 'b'" << endl;
            break;
        default:
            cout << "c != 'a' && c != 'b'" << endl;
            break;
    }

    // goto
    int d = 1;
    goto label;

    label:
    cout << "d == 1" << endl;

    // for
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }

    // while
    int j = 0;
    while (j < 10) {
        cout << j << endl;
        j++;
    }

    // do while
    int k = 0;
    do {
        cout << k << endl;
        k++;
    } while (k < 10);

    return 0;
}