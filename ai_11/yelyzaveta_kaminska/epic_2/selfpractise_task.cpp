#include <iostream>
#include <string>
using namespace std;

int main() {

    int month;
    string season;

    cout << "Enter the number of month(1-12): ";
    cin >> month;

    if (month >= 1 && month <= 12) {
        if (month == 12 || month == 1 || month == 2) {
            season = "winter";
        } else if (month >= 3 && month <= 5) {
            season = "spring";
        } else if (month >= 6 && month <= 8) {
            season = "summer";
        } else {
            season = "autumn";
        }

    cout << "Month " << month << " belongs to: " << season << endl;
    } else {
    cout << "Invalid month, try again." << endl;
    }

    return 0;
}
