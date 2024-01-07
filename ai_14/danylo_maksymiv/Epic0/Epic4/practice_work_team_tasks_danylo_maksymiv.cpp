#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] == str[end]) {
        return isPalindrome(str, start + 1, end - 1);
    }

    return false;
}

bool isPalindrome(int number) {
    string strNum = to_string(number);
    return isPalindrome(strNum, 0, strNum.length() - 1);
}

int main() {
    bool status1, status2;
    
    string str ;
    cin>>str;
    status1 = isPalindrome(str, 0, str.length() - 1);
    if (status1) {
        cout << str << " є паліндромом." << endl;
    } else {
        cout << str << " не є паліндромом." << endl;
    }

    int num ;
    cin>>num;
    status2 = isPalindrome(num);
    if (status2) {
        cout << num << " є паліндромом." << endl;
    } else {
        cout << num << " не є паліндромом." << endl;
    }

    return 0;
}
