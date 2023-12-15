#include <iostream>
#include <string>

using namespace std;

bool palind(const string& str) {
  if (str.length() <= 1) {
    return true;
  }

  if (tolower(str.front()) == tolower(str.back())) {
    return palind(str.substr(1, str.length() - 2));
  } else {
    return false;
  }
}

int main() {
  string line;
  cout << "Enter a line: " << endl;
  getline(cin, line);

  if (palind(line)) {
    cout << line << " is a palindrome" << endl;
  } else {
    cout << line << " is not a palindrome" << endl;
  }

  return 0;
}