#include<iostream>
#include<string>
using namespace std;

int main(){
    string Input_String;
    string Compressed_String;

    int count = 1;

    cin >> Input_String;

    for(int i=1; i<=Input_String.length(); i++){
        if(Input_String[i] == Input_String[i-1]){
            count++;
        }else{
            if(count!=1){
                Compressed_String += Input_String[i-1] + to_string(count);
            }else{
                Compressed_String += Input_String[i-1];
            }
            count = 1;
        }
    }
    cout << Compressed_String;


    return 0;
}