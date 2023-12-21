#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    if ((end - start > 1)) {
        if (!isPalindrome(str, 1+start, end-1))
        return 0;
    }
    if (str[start] == str[end]) { return 1; }
    else { return 0;}
}

bool isPalindrome(int number) {
    string abc = to_string(number);
    return isPalindrome(abc, 0, abc.length()-1);;
}

int main() {
    string input;
    cin >> input;
    cout << (isPalindrome(input, 0, input.length()-1)?"Yes":"No") << endl << (isPalindrome(123421)?"Yes":"No");
    return 0;
}