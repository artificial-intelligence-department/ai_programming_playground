#include <iostream>
#include <string>
#include <cmath>

using namespace std;
void isPalindrom(string ar,int start,int end){
    if(start>=end){
        cout<<"Is Palindrom";
    }else{
        if(ar[start++]==ar[end--]){
            isPalindrom(ar,start,end);
        }else{
            cout<<"Isn't Palindrom";
        }
    }
}
void isPalindrom(int num,int length){
    if(length<=1){
        cout<<"Is Palindrom";
    }else{
        int k = pow(10, length-1);
        if((num%10)==(num/k)){
            num = ((num%k)/10);
            length -=2;
            isPalindrom(num,length);
        }else{
            cout<<"Isn't Palindrom";
        }
    }
}
int main(){
    string ex="radr";
    isPalindrom(ex,0,3);
    cout<<'\n';
    int num = 12321,size = 5;
    isPalindrom(num, size);
    cout<<'\n';
    ex = to_string(num);
    isPalindrom(ex,0,4);
    return 0;
}