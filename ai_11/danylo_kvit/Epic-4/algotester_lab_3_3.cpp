#include <iostream>
using namespace std;
int main(){
    string s;
    cin >> s;
    string s_compressed;
    int j = 0;
    for(int i=0;i<s.size();i++){
        j++;
        if(i==s.size()-1||s[i]!=s[i+1]){
            s_compressed+= s[i];
            if(j!=1)s_compressed+= to_string(j);
            j = 0;
        }


    }
    for(char i: s_compressed) cout << i;
}
