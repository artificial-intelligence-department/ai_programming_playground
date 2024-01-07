#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
   cin >> k;

   string s;
   cin >> s;

   string substring = "TOILET";
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find(substring, pos)) !=string::npos) {
        ++count;
        pos += substring.length();
    }

    if (count >= k) {
       cout << "YES" <<endl;
    } else {
       cout << "NO" <<endl;
    }

    return 0;
}
