#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
bool isPalindrome (const string str){
     bool Palindrome = false;
     string stringArray[str.length()];
     int lengthOfWord =str.length();
     
     string word = str;

     for (int i = 0; i < lengthOfWord; i++)
     {
      stringArray[i] = string(word);
    }

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
bool isPalindrome (int num){
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

int main() {
   
    string exmp1 = "level";
    string exmp2 = "scam";
    string exmp3 = "Artificial Intelligence";
    int exmp4 = 12321;
    int exmp5 = 123321;
    if(isPalindrome(exmp1) == 1){
        cout << exmp1 << " - Is palindrome" << endl;
    }else{
        cout << exmp1 <<" isn`t palindrome" << endl;
    }
     if(isPalindrome(exmp3) == 1){
        cout << exmp3 << " - Is palindrome" << endl;
    }else{
        cout << exmp2 <<" isn`t palindrome" << endl;
    }
   
     if(isPalindrome(exmp3) == 1){
        cout << exmp3 << " - Is palindrome" << endl;
    }else{
        cout << exmp3 <<" isn`t palindrome" << endl;
    }
    if(isPalindrome(exmp4) == 1){
        cout << exmp4 << " - Is palindrome" << endl;
    }else{
        cout << exmp4 <<" isn`t palindrome" << endl;
    }
    if(isPalindrome(exmp5) == 1){
        cout << exmp5 << " - Is palindrome" << endl;
    }else{
        cout << exmp5 <<" isn`t palindrome" << endl;
    }
   
   
    return 0;
}