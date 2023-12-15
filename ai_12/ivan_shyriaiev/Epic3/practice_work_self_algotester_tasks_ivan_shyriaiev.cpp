#include<iostream>
#include<string>
using namespace std;

int main(){
    int i,k;
    int counter = 0;
    string message;
    string word = "TOILET";
    cin>> k>> message;
    int length = word.size();

    while ((i = message.find(word, i))<message.size()) {
        counter++;
        i +=length;
    }

    if(counter>=k){
        cout<<"YES";
        return 0;
    }
        cout<<"NO";
        return 0;
}