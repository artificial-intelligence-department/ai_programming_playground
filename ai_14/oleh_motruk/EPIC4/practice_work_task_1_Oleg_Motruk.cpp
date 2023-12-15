#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void isPalindrom(string pal_checker,char front, int back ){
    if (front >= back){
        cout << "isPalindrom"<< endl;
    }
    else{
        if(pal_checker[front] == pal_checker[back - 1]){
            isPalindrom(pal_checker , front + 1 , back - 1);
        }
        else
            cout << "Not Palindrom" << endl;
        }
}

bool isPalindrom(int num){
    string palnum_checker = to_string(num);
    return palnum_checker == string(palnum_checker.rbegin() , palnum_checker.rend());
}

int main(){

    string pal_checker;
    cin >> pal_checker;
    int back = pal_checker.length();
    int front = 0;
    isPalindrom(pal_checker, front, back);
    int num = 123321;
    cout << num << endl;
    if(isPalindrom(num)){
        cout << "isPalindrom"; 
    }
    else
        cout << "Not Palindrom";

    return 0;
}