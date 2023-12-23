#include<iostream>
#include<string>
using namespace std;
 
bool palindrome(string str, int start, int end) 
{
    if (start>=end)
        return true;
    if (str[start]!=str[end])
        return false;
    return palindrome(str, start+1, end-1);  
}

bool palindrome(long long number)
{
    string str=to_string(number);
    int size=str.length();
    int start=0;
    int end=size-1;

    return palindrome(str, start, end);
}

int main()
{
    string str1;
    getline(cin, str1);

    int size1=str1.length();
    int start1=0;
    int end1=size1-1;

    if (palindrome(str1, start1, end1))
        cout<<"PALINDROME"<<endl<<endl;
    else
        cout<<"NO PALINDROME"<<endl<<endl;

    long long number;
    cin>>number;

    if (palindrome(number))
        cout<<"PALINDROME"<<endl<<endl;
    else
        cout<<"NO PALINDROME"<<endl<<endl;

    return 0;
}