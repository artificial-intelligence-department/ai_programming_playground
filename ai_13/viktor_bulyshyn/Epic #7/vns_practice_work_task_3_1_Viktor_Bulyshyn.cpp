#include <iostream>

using namespace std;

int main() {
    double R1, R2;

    cout << "The value of the first resistance (Ohm)> ";
    cin >> R1;
    cout << "The value of the second resistance (Ohm)> ";
    cin >> R2;

    double TR = R1 + R2;

    cout << "Total resistance > " << TR << " Ом" << endl;

    return 0;
}
