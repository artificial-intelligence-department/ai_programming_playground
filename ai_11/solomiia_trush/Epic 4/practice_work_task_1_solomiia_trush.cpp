#include <iostream>
using namespace std;

bool IsPalindrome (string word, int left, int right) {

    if (word[left]==word[right]) {
        left++;
        right--;
        IsPalindrome(word, left, right);
        return true;
    }
    else {
        return false;
    }

}

int IsPalindrome (int number, int digit, int reversed) {

    while (number > 0) {
        int digit = number%10;
        reversed = reversed*10 + digit;
        number /= 10;
        IsPalindrome(number, digit, reversed);
        return 1;
    }
    return 0;

}

int main () {
    int left, right, number, original_num, digit, reversed;
    string word;

    cin >> word;
    cin >> number;

    left = 0;
    right = size(word)-1;

    cout << IsPalindrome(word, left, right) << endl;
    
    string s_num = to_string(number);
    right = size(s_num)-1;
    cout << IsPalindrome (s_num, left, right) << endl;

    reversed = 0;
    original_num = number;
    
    cout << IsPalindrome(number, digit, reversed) << endl;
}