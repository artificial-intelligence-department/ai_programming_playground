#include <iostream>
using namespace std;
int main(){
    string str;
    cin >> str;
    int n = 1;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == str[i+1]){
            n++;
        }
        else{
            cout << str[i];
            if (n != 1){
                cout << n;
            }
            n = 1;
        }
    }
    return 0;
}