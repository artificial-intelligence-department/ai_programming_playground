#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(const string& str, int start, int end){
    if(start >= end) return true;

    if (str[start] != str[end]) {
        return false;
    }

    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const vector<int>& vec, int start, int end){
    if (start >= end) return true;

    if (vec[start] != vec[end]) {
        return false;
    }

    return isPalindrome(vec, start + 1, end - 1);
}

int main(){ 
    string str1 = "radar";
    string str2 = "level";
    string str3 = "forest";
    vector<int> vec1 = {1, 2, 3, 4, 3, 2, 1};
    vector<int> vec2 = {1, 1, 1};
    vector<int> vec3 = {12, 17, 99};
    vector<int> vec4 = {12, 21};

    if (isPalindrome(str1, 0, str1.length() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }

    if (isPalindrome(vec1, 0, vec1.size() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }

    if (isPalindrome(str2, 0, str2.length() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }

    if (isPalindrome(vec2, 0, vec2.size() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }

    if (isPalindrome(str3, 0, str3.length() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }
    
    if (isPalindrome(vec3, 0, vec3.size() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }
    
    if (isPalindrome(vec4, 0, vec3.size() - 1)) {
        cout << "Palindrome.\n";
    } else {
        cout << "Not a palindrome.\n";
    }
    return 0;
}

