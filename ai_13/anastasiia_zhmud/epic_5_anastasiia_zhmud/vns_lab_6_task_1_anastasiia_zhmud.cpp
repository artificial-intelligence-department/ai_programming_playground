#include <iostream>
#include <string>
using namespace std;
int shotrest(string s){
    int k=0,length=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            if(length==0){
                length=k;
            }
            if(k<length){
                length=k;
            }
            k=0;
        }
        else{
            k++;
        }
    }
    return length;
}
int main(){
    string s;
    cout<<"Enter a string: ";
    getline(cin, s);
    cout<<shotrest(s);
}