#include <string>
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    int i = 0;
    while (i < s.size()) {
        char current_char = s[i];
        int count = 0;

        
        while (i < s.size() && s[i] == current_char) 
        {
            count++;
            i++;
        }

        cout << current_char;
        if (count > 1) 
        {
            cout << count;
        }
    }

    return 0;
}