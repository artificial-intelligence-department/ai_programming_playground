
#include <iostream>
#include <string>
using namespace std;

int main(){
    string S;
    cin >> S;
    int counter = 1;

    for (int i = 0; i < S.size(); i++){
        if (S[i] == S[i+1]){
            counter++;
        }else if(counter > 1){
            cout << S[i] << counter;
            counter = 1;
        }else {
            cout << S[i];
        }

    }
    return 0;
}
