#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s, int start, int end)
{
 if (start == end) 
 {
  return true;
 }
 if(s[start] != s[end])
 {
  return false;
 }

 return isPalindrome(s, start + 1, end - 1);
}

bool isPalindrome(int num)
{
 string number = to_string(num);
 return isPalindrome(number, 0, number.length() - 1);
}

int main()
{
 string s;
 cout << "Enter string/number: ";
  cin >> s;

  if (isPalindrome(s, 0, s.length() - 1))
  {
   cout << s << " is palindrome";
  }
  else {
   cout << s << " is not palindrome";
  }

  return 0;
}
