#include <iostream>

using namespace std;

int main() {
    long long int n;
    cin >> n;

    int kup[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int g = 0;

    for (int i = 0; i < 9; ++i) {
        g += n / kup[i];
        n %= kup[i];
    }

    cout << g << endl;

    return 0;
}
