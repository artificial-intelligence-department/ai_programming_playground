#include<iostream>
using namespace std;


int main(){
    unsigned int signal = 15, amount;
    string input_oper;
    cin >> amount;
    cin >> input_oper;
    for(int i=0; i<amount; i++){
        if(input_oper[i] == 'k' && signal > 0){
            signal--;
        }else if(input_oper[i] == 'p' && signal!=0){
            signal = 15;
        }else if(input_oper[i] == 'z' && signal >= 1){
            signal=0;
        }else if (input_oper[i] == 'z' && signal == 0){
            signal = 15;
        }
    }
    
    cout << signal;
    return 0;
}
