#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool checkPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    
    if (str[start] != str[end]) {
        return false;
    }
    
    return checkPalindrome(str, start + 1, end - 1);
}

bool checkPalindrome(int num, int reversedNum = 0) {
    if (num != 0) {
        if (reversedNum == 0) {
            int size = -1;
            for (int temp = num; temp != 0; temp /= 10)
                size++;
            
            for (int temp = num; temp != 0; temp /= 10)
                reversedNum += temp % 10 * pow(10, size--);
        }  
        if (num % 10 != reversedNum % 10)
            return false;
        return checkPalindrome(num / 10, reversedNum / 10);
    }
   
    return true;  
}

int main() {
    int number;
    cin >> number;

    if (checkPalindrome(number)) {
        cout << "The entered word or number is a palindrome." << endl;
    } else {
        cout << "The entered word or number is not a palindrome." << endl;
    }

    return 0;
}
