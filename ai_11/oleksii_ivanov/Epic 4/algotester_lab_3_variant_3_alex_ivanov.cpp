#include <iostream>
#include <string>
using namespace std;

int main() {
    string input, result;
    getline(cin, input);

    char c;
    int count = 1;
    for (int i = 0; i < input.size(); ++i) {
        c = input[i];
        if (i + 1 < input.size() && input[i+1] == c) ++count;
        else {
            result += c;
            if (count > 1) result += to_string(count);
            count = 1;
        }
    }

    cout << result;
    return 0;
}
