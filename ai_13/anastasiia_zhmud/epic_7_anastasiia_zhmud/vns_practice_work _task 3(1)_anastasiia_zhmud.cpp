#include<iostream>
#include<string>
using namespace std;
    void convert(string a){
        for(int i=0; i<a.length(); i++){
            if(a[i]=='.'){
                cout<<" "<<"grn."<<" ";
            }else cout<<a[i];
        }
        cout<<" "<<"cop.";
    }
int main(){
    string a;
    cout<<"Enter a number:  ";
    cin>>a;
    convert(a);
}