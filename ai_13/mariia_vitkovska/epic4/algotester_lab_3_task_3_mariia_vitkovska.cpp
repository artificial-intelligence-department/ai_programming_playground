#include <iostream>
#include <string>

using namespace std;
string compress(const string& s) {
    string compressed;
    
    int count = 1;
    for (size_t i = 0; i < s.size(); ++i) {
            if(s[i] == s[i + 1]) {
                count++;
            } 
        else {
            compressed += s[i] + (count > 1 ? to_string(count) : "");
            count = 1; 
        }
    }

    return compressed;
}

int main() {
    string a;
    cin >> a;

    string Scompressed = compress(a);

    cout << Scompressed << endl;

    return 0;
}