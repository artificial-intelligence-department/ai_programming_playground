#include <iostream>
#include <string>
using namespace std;

string task(string s) {
    string result;
    int counter{1};
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == s[i + 1])
            counter++;
        else {
            result += s[i];
            if (counter > 1)
                result += to_string(counter);
            counter = 1;
        } 
    }
    return result;
}
int main() {
    string s;
    cin >> s;

    cout << task(s);

    return 0;
}

