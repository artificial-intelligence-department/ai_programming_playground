#include <iostream>
#include <string>
using namespace std;


bool palindrome(string word_num, int start, int end){

    if(word_num[start] != word_num[end]) return false;
    if(start >= end) return true;

    return palindrome(word_num, start+1, end-1);
}

bool palindrome(int number){

    string check_number = to_string(number);
    return palindrome(check_number, 0, check_number.length()-1);
}

int main(){

    string word;
    int number;

    cout << "Give a word to check" << endl;
    cin >> word;
    cout << "Give a number to check" << endl;
    cin >> number;

    cout << "---------------------" << endl;
    if (palindrome(word, 0, word.length()-1)==true){
        cout << word << " " << "is a palindrome)" << endl; } 
    else {
        cout << word << " " << "isn't a palindrome(" << endl; }


    if (palindrome(number)==true){
        cout << number << " " << "is a palindrome)" << endl; } 
    else {
        cout << number << " " << "isn't a palindrome(" << endl; }

    return 0;
}