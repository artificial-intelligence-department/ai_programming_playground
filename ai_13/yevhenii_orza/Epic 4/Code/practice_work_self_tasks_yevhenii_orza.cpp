#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool isPalindrome (const string str){
     bool Palindrome = false;
     int lengthOfWord =str.length();
     
     string word = str;

    char* char_array = new char[lengthOfWord + 1];
     strcpy(char_array, word.c_str()); 
    for(int i = 0; i < (lengthOfWord/2); i++){
        char a = char_array[(lengthOfWord/2) - (i + 1)];
        char b = char_array[(lengthOfWord/2) + (i + 1)];
        if (a == b){
            Palindrome = true;
        }else{
            Palindrome = false;
        }
    }
   return Palindrome;
}
bool isPalindromenum (int num){
        bool Palindrome = true;
        std::vector<int> result;
        while (num > 0) {
        result.insert(result.begin(), num % 10);
        num /= 10;
    }
    std::vector<int> resultArray = result;
    
    int size = resultArray.size(); 
    for(int i = 0; i < size/2; i++){
        int a = result[(size/2) - (i + 1)];
        int b = result[(size/2) + (i + 1)];
        if (a != b){
            Palindrome = false;
        }
    }
   return Palindrome;
}   
bool is_digits(string& str)
{
    for (char ch : str) {
        int v = ch;
        if (!(ch >= 48 && ch <= 57)) {
            return 0;
        }// Перевірка, чи символ є цифрою (ASCII-коди цифр: 48 - '0' і 57 - '9')
    }
 
    return 1;
}

int main() {
    int finish = 0;
   do{ cout << "Enter the word or num"<<endl;
       cout << "If you want exit type - 0"<<endl;
    string word;
    cin >> word;
    if(word == "0"){
        return 0;
    }
    bool isnum = is_digits(word);
    if(isnum == 1){
        int num = stoi(word);
        if(isPalindromenum(num) == 1){
            cout << num << "  - is Palindrome"<< endl;
        }else{
            cout << num << "  - isn`t Palindrome"<< endl;
        }
    }else{
        if(isPalindrome(word) == 1){
            cout << word << "  - is Palindrome"<< endl;
        }else{
            cout << word << "  - isn`t Palindrome"<< endl;
        }
    }}while(finish != 1);
    return 0;
}