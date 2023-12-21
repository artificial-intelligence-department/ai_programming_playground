#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    int amount = 1;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == str[i+1]){
            amount++;
        }
        else if(str[i] != str[i+1] && str[i] != str[i-1]){
            cout << str[i];
        }
        else{
            cout << str[i] << amount;
            amount = 1;
        }
    }
    return 0;
}