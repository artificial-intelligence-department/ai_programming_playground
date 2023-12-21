#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(const string& str, int start, int end);
bool isPalindrome(int number);
int main()
{
string radar="radar";
string level="level";
string notPalindrome="orange";
cout<<"Is 'radar' palindrome? "<<(isPalindrome(radar,0,(radar.size()-1))?"Yes :)":"No :(")<<endl;
cout<<"Is 'level' palindrome? "<<(isPalindrome(level,0,(level.size()-1))?"Yes :)":"No :(")<<endl;
cout<<"Is 'orange' palindrome? "<<(isPalindrome(notPalindrome,0,(notPalindrome.size()-1))?"Yes :)":"No :(")<<endl;
cout<<"Is 564 palindrome? "<<(isPalindrome(564)?"Yes :)":"No :(")<<endl;
cout<<"Is 12321 palindrome? "<<(isPalindrome(12321)?"Yes :)":"No :(")<<endl;

    return 0;
} 
bool isPalindrome(const string& str, int start, int end){

    if(str[start]!=str[end]){
        return false;
    }
    if(start>=end){
        return true;
    }
    return isPalindrome(str,start+1,end-1);
}
bool isPalindrome(int number){
    string str_number=to_string(number);
    return isPalindrome(str_number,0,(str_number.size()-1));

}

