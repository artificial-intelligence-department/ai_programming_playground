#include <iostream>
#include <string>
using namespace std;

int main(){
    string S = {""}, Scomp = {""};
    string counterToStr;
    char current;
    int counter = 1;
    cin >> S;

    for(int i = 1; i <= S.length(); i++){
        current = S[i-1];
        if (S[i] == current){
            counter++;
        }
        else{
            Scomp += current;
            if(counter > 1){
                counterToStr = to_string(counter);
                Scomp += counterToStr;
            }
            counter = 1;
        }
    }
    cout << Scomp;
    return 0;
}
