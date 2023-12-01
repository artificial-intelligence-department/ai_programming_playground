#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    int count = 1;
    cout << "Enter your text: ";
    cin >> text;
    for (int i = 0; i < text.length(); i++) {
        if (i == 0)
            goto Label;
        if (text[i] == text[i - 1]) {
            count++;
        }
        else {
            Label:
            if (count > 1) {
                cout << count;
            }
            cout << text[i];
            count = 1;
        }
    }
    if(text.length()!=1)
    if (text[text.length()-1] == text[text.length() - 2]) {
        cout << count;
    }
    return 0;
}
