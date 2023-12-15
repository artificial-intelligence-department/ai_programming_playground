//задача на алготестері - 0081 Допоможе чи заб'є?
#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int number;
    cin >> number;
    cin >> str;
    int current_n=0;
    for(int i = 0; i < str.size(); i++){
        if(str[i]=='T' && i+5<str.size()){
            if(str[i+1]=='O' && str[i+2]=='I' && str[i+3]=='L' && str[i+4]=='E' && str[i+5]=='T'){
                current_n++;
                i+=5;
            }
        }
    }
    if(current_n>=number){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
    return 0;
}