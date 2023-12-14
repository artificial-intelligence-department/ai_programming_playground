#include <iostream>
using namespace std;

int main() {
    int count;
    cout << "Enter count of pucks: ";
    cin >> count;
    int monthly_count = count * 7 * 2 * 26;
    cout << "Monthly count: " << monthly_count << endl;

    return 0;
}