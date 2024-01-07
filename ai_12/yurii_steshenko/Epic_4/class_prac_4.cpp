#include<iostream>
#include <string>
using namespace std;
bool isPalindrome(string n1)
{
    bool resalt=true;
    int size_ = size(n1);
    for (int i = 0; i < size_; i++)
    {
       if (n1[i]!=n1[size_-1-i])
       {
            resalt = false;
            break;
       }
    }
    return resalt;    
}
bool isPalindrome(int n2)
{
    bool resalt=true;
    string x = to_string(n2);
    int size_ = size(x);
    for (int i = 0; i < size_; i++)
    {
       if (x[i]!=x[size_-1-i])
       {
            resalt = false;
            break;
       }
    }
    return resalt;    
}
int main()
{
    int i1;
    string str1;
    cout<<"enter the string"<<endl;
    cin>> str1;
    if (isPalindrome(str1))
    {
        cout<<"Yes, the string is palindrome"<<endl;
    }
    else
    {
        cout<<"No, the string isn`t polindrome"<<endl;
    }
    cout<<"enter the integer"<<endl;
    cin>> i1;
    if (isPalindrome(i1))
    {
        cout<<"Yes, the integer is palindrome"<<endl;
    }
    else
    {
        cout<<"No, the integer isn`t polindrome"<<endl;
    }
    return 0;
}