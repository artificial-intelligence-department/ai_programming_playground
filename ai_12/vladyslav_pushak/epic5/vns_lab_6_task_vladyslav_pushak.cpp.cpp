#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char str[256];
    cin.getline(str, 256);

    int strLength = strlen(str);
    for (int i = 0; i < strLength / 2; ++i) {
        swap(str[i], str[strLength - i - 1]);
    }

    cout << str << endl;

    return 0;
}
