#include <iostream>
#include <string>

using namespace std;

void compress_prefix_string(string s) {

  string compressed_string = "";
  int count = 1;
  
  if (s.length() == 1) {
    cout << s;
  }

  for (int i = 0; i < s.length(); ) {
    while (i + 1 < s.length() && s[i] == s[i + 1]) {
      count++;
      i++;
    }

    if (count == 1) {
      compressed_string += s[i];
    } else {
      compressed_string += s[i] + to_string(count);
    }

    count = 1;
    i++;
  }
    cout << compressed_string;
}

int main() {
  string s;
  getline(cin, s);

  compress_prefix_string(s);

  return 0;
}
