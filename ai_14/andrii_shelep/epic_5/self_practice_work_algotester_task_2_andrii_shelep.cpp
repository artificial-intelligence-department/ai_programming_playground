//Задача на алготестері - 0541 Дзідзьо і його пісня
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    cin >> str;
    string new_str;
    for(int i = 0; i < str.size(); i++){
        if(str[i]!=str[i+1]){
            new_str+=str[i];
        } else{
            while(str[i]==str[i+1]){
                i++;
            }
            i--;
        }
    }
    cout << new_str.size() << endl;
    return 0;
}