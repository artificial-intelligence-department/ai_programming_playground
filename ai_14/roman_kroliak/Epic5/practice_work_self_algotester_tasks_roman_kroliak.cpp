#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int power = 15;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'k' && power != 0) power--;
        else if (s[i] == 'k' && power == 0) power = 0;
        else if (s[i] == 'p' && power >= 1) power = 15;
        else if (s[i] == 'p' && power == 0) power = 0;
        else if (s[i] == 'z' && power == 0) power = 15;
        else if (s[i] == 'z' && power >= 1) power = 0;
    }
    cout << power;
    return 0;
}