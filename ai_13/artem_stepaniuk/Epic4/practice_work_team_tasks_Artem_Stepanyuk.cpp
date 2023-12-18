#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
  if (start >= end) {
    return true;
  }

  if (str[start] != str[end]) {
    return false;
  }

  return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int num) {
  string s = to_string(num);
  return isPalindrome(s, 0, s.length() - 1);
}

int main() {
  cout << "Enter a word or number to check for palindrome: ";
  string input;
  cin >> input;

  if (isPalindrome(input, 0, input.length() - 1)) {
    cout << "\"" << input << "\" is a palindrome." << endl;
  } else {
    cout << "\"" << input << "\" is not a palindrome." << endl;
  }

  return 0;
}
