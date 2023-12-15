#include <iostream>
#include <string>

using namespace std;
bool isPalindrome(const string& str, int start, int end){
    if(start>=end){
        return true;
    }
    if (str[start] != str[end-1]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(int length, int number[]) {
    for (int i = 0; i < length / 2; i++) {
        if (number[i] != number[length - i - 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    string word;
    cout << "Введіть рядок: ";
    cin >> word;

    if (isPalindrome(word, 0, word.length())== true) {
        cout << "Це паліндром." << endl;
    } else {
        cout << "Це не паліндром." << endl;
    }

    int length;
    cout << "Введіть кількість чисел: ";
    cin>>length;
    cout << "Введіть число: ";
    int *number = new int[length];
    for(int i=0; i<length; i++){
        cin>>number[i];
    }

    if (isPalindrome(length, number) == true) {
        cout << "Це паліндром." << endl;
    } else {
        cout << "Це не паліндром." << endl;
    }
    return 0;
}


