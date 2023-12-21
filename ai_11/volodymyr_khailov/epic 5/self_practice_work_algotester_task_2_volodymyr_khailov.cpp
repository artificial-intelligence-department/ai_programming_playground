// Кількість речень
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    getline(cin, a);

    int count = 0;
    for (char c : a) {
        if (c == '.' || c == '!' || c == '?') {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
