#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isPalindrome (const string& str,int start, int end){
    if(start>=end)
        return true;
    if (str[start]!= str[end])
        return false;
    return isPalindrome(str, start +1,end-1);
}
bool isPalindrome(int num){
    string convert=to_string(num);
    return isPalindrome(convert, 0,convert.size()-1);
}



int main()
{
    string word;
    cout<<"Enter a word: ";
    cin>>word;
    bool check_str=isPalindrome(word,0,word.size()-1);
    if(check_str)
        cout<<"Yes"<<endl;
    else   
        cout<<"No"<<endl;

    int num;
    cout<<"Enter a number: ";
    cin>>num;
    bool check_num=isPalindrome(num);
    if(check_num)
        cout<<"Yes"<<endl;
    else   
        cout<<"No"<<endl;
    return 0;
}