#include <iostream>

using namespace std;

int gcd(int number1, int number2)
{
    while(number1 > 0 && number2 > 0){
        if(number1 > number2){
            number1 %= number2;
        } else{
            number2 %= number1;
        }
    }
    return number1 + number2;
}

int main(){
    int number;
    long long votes[1000];
    cin >> number;
    for(int i = 0; i < number; i++){
        cin >> votes[i];
    }
    long long nsd = votes[0];
    for(int i = 1; i < number; i++){
        nsd = gcd(nsd, votes[i]);
    }
    long long amount = 0;
    for(int i = 0; i < number; i++){
        amount += votes[i]/nsd;
    }
    cout << amount;
    return 0;
}