#include<iostream>
using namespace std; 

int main()
{
    string S;
    bool ispal = 0;
    cin >> S;
    for (int i = 0; i < S.length() / 2; i++) {
 
        if (S[i] != S[S.length() - i - 1]) {
        ispal = 1;
            break;
        }
    }
if(ispal){
    cout << "No";
}
else{
    cout << "Yes";
}
    return 0;
}