#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

bool sortAlpha(const string& a, const string& b) {
    string aUpper = a;
    string bUpper = b;

    transform(a.begin(), a.end(), aUpper.begin(), ::toupper);
    transform(b.begin(), b.end(), bUpper.begin(), ::toupper);

    return aUpper < bUpper;
}
int main() {
    string input;
    vector<string> v;
    getline(cin, input); 
    stringstream ss(input);

    while (getline(ss, input, ' ')){
        if(isalpha(input[0])){
            v.push_back(input);
        }
    }
    sort(v.begin(), v.end(), sortAlpha);
    cout << "-----------------\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}