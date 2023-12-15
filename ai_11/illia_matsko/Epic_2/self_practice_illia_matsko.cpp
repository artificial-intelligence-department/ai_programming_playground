#include <iostream>
using namespace std;

int main() {
    int hour, minute;

    cout << "Enter hour (0-23): ";
    cin >> hour;

    cout << "Enter minute (0-59): ";
    cin >> minute;

    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        cout << "Error!";
    } else {
        if (hour < 12) {
            cout << "Good morning!";
        } else if (hour < 18) {
            cout << "Good day!";
        } else if (hour == 12 && minute == 0) {
            cout << "Midday!";
        } else if (hour < 24) {
            cout << "Good evening!";
        }

        if ((hour == 0 && minute == 0) || (hour == 12 && minute == 0)) {
            cout << "Midnight!";
        } else if (hour >= 0 && hour < 6) {
            cout << "Good night!";
        }
    }

    return 0;
}
