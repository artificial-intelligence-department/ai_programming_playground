#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    if (str[start] != str[end])
    {
        return false;
    }

    return isPalindrome(str, start+1, end-1);
}

bool isPalindrome(int number)
{
   string numstr = to_string(number);
   return isPalindrome(numstr, 0 ,numstr.length()-1);
}

int main()
{
    bool wordstatus;
    string word;
    cout<<"Please enter your word:"<<endl;
    cin>>word;
    wordstatus = isPalindrome(word, 0, word.length() - 1);
    if (wordstatus) 
    {
        cout << "Palindrome" << endl;
    } 
    else 
    {
        cout <<"Not a palindrome" << endl;
    }
    bool numstatus;
    int num;
    cout<<"Please enter your nummber:"<<endl;
    cin>>num;
    numstatus = isPalindrome(num);
    if (numstatus) 
    {
        cout <<"Palindrome" << endl;
    } 
    else
    {
        cout <<"Not a palindrome" << endl;
    }

    return 0;

}