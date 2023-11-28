#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> coordinates(n);

    for (int i = 0; i < n; i++) {
        cin >> coordinates[i];
    }

    for (int i = 1; i < n; i++) {
        if (coordinates[i] - coordinates[i - 1] < 2) {
            cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}
