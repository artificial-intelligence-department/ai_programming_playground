#include <iostream>
using namespace std;

int main() {
    char op;
    double n_1, n_2, res;

    while (true) {

        cout << "Choose option (+, -, *, /) or 'q' for entering: ";
        cin >> op;

        if (op == 'q') {
            cout << "End of the programm." << endl;
            break;
        }

        cout << "Enter the first number: ";
        cin >> n_1;

        cout << "Enter the second number: ";
        cin >> n_2;

        switch (op) {
            case '+':
                res = n_1 + n_2;
                cout << "Result: " << res << endl;
                break;
            case '-':
                res = n_1 - n_2;
                cout << "Result:" << res << endl;
                break;
            case '*':
                res = n_1 * n_2;
                cout << "Result: " << res << endl;
                break;
            case '/':
                if (n_2 != 0) {
                    res = n_1 / n_2;
                    cout << " Result: " << res << endl;
                } else {
                    cout << "EROR! Division by 0!" << endl;
                }
                break;
            default:
                cout << "Invalid operation,try again." << endl;
        }
    }

    return 0;
}
