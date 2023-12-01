#include <iostream>
#include <string>

using namespace std;

void Recursion(const string& str, int midleft, int midright) {
    if (str[midleft] == str[midright]) {
        if (midleft == 0) {
            cout << "YES!";
            return;
        }
        Recursion(str, midleft - 1, midright + 1);
    } else {
        cout << "NO!";
    }
}
void Recursion(const int& num, int midleft, int midright) {
    string str = to_string(num);

    if (str[midleft] == str[midright]) {
        if (midleft == 0) {
            cout << "YES!";
            return;
        }
        Recursion(str, midleft - 1, midright + 1);
    } else {
        cout << "NO!";
    }
}

int main() {
    string str;
    cin >> str;

    int mid = str.length() / 2;
    int midleft = mid - 1;
    int midright = mid + 1;

    Recursion(str, midleft, midright);

    return 0;
}
