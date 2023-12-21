#include <iostream>
#include <cmath>
#include <string>
using namespace std;
bool isPalindrome(string str, int start, int end);
bool isPalindrome(int number, int length);

int main(){
    string palindrome;
	cout << "Enter a word or number to check if it's a palindrome: ";
	cin >> palindrome;
    bool IfIs;
    
    if (isdigit(palindrome[0])){ // isdigit checks whether first symbol of "palindrome" is a int
        int length = palindrome.length();
        IfIs = isPalindrome(stoi(palindrome), length); // stoi - string to integer
    }
    else{
        IfIs = isPalindrome(palindrome, 0, palindrome.size() - 1);
    }
    (IfIs == true)? cout << palindrome << " is a polindrome" : cout << palindrome << " is not a polindrome";
	return 0;
}
bool isPalindrome(string str, int start, int end){
    if (start >= end) return true; 
    else if(str[start] != str[end]) return false;
    return isPalindrome(str, start  + 1, end - 1);
}
bool isPalindrome(int number, int length){
    if (length <= 1) return true;
    int divisor = pow(10, length - 1);
    if (number / divisor != number % 10) return false;
    int newNumber = (number % divisor) / 10;
    return isPalindrome(newNumber, length -2);
}