#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;

        // Перевірка, чи є місяць осіннім (вересень, жовтень, листопад)
        if (m == 9 || m == 10 || m == 11) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
