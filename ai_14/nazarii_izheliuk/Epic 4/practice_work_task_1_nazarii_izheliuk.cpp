#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
  if(start >= end)
    return true;
  
  if(str[start] != str[end])  
    return false;

  return isPalindrome(str, start+1, end-1);  
}

bool isPalindrome(string str) {
  int n = str.length();
  return isPalindrome(str, 0, n-1); 
}

int main() {

  string input;
  cout << "Введіть слово: ";
  getline(cin, input);

  if(isPalindrome(input)) {
    cout << input << ": паліндром" << endl;
  } else {
    cout << input << ": не паліндром" << endl;
  }

  int number;
  cout << "Введіть число: ";
  cin >> number;

  string numStr = to_string(number);
  
  if(isPalindrome(numStr)) {
    cout << number << ": паліндром" << endl;
  } else {
    cout << number << ": не паліндром" << endl;
  }

  return 0;
}