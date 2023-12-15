#include <iostream>
#include <string>

using namespace std;

string compress_prefix_string(string s) {

  string compressed_string = "";
  int count = 1;
  
  if (s.length() == 1) {
    return s;
  }

  for (int i = 0; i < s.length(); ) {
    while (i + 1 < s.length() && s[i] == s[i + 1]) {
      ++count;
      ++i;
    }

    if (count == 1) {
      compressed_string += s[i];
    } else {
      compressed_string += s[i] + to_string(count);
    }

    count = 1;
    ++i;
  }
  return compressed_string;
}

int main() {
  string s;
  getline(cin, s);

  string compressed_string = compress_prefix_string(s);
  cout << compressed_string << endl;

  return 0;
}