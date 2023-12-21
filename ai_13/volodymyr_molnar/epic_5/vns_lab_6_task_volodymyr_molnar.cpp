#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    string str;

    cout << "enter: ";
    getline(cin, str);

    sort(str.begin(), str.end());

    cout << "result: " << str << endl;

    return 0;
}
