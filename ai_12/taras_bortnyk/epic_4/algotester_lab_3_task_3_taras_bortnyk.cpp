#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    
    int count = 1;
    string result;

    for (int i = 0; i < str.size(); i++) {
        if (i + 1 < str.size() && str[i] == str[i + 1]) {
            count++;
        } else {
            result += str[i];
            if (count > 1) {
                result += to_string(count);
            }
            count = 1;
        }
    }

    cout << result << endl;
    return 0;
}
