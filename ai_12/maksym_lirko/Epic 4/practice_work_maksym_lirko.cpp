#include<iostream>
#include<string>
using namespace std;


bool isPalindrome(string &b)
{
    int a = 0;
    int size = b.length();

   for (int i = 0; i < size; i++)
   {
        if(b[i] == b[size-1-i])
        {
            a++;
        }
   }
   if (a == size)
   {
        return true;
   }
    else {
    return false;
    }
}
bool isPalindrome(int number)
{
    string b = to_string(number);
    return isPalindrome(b);
}

int main(){
    string A;
    cout<<"Enter a string: "<<endl;
    cin>>A;

    if (isPalindrome(A)==true)
    {
        cout<<"Your string is Palindrome! "<<endl;
    }
    else
    {
        cout<<"Your string is not Palindrome! "<<endl;
    }

    int a;
    cout<<"Enter a number!"<<endl;
    cin>>a;
    if (isPalindrome(a)==true)
    {
        cout<<"Your number is Palindrome! "<<endl;
    }
    else{
        cout<<"Your number is not Palindrome!"<<endl;
    }
    return 0;
}