#include <iostream>
#include <cstdio>
#include <string>
#include<ctype.h>
#include<stdio.h>
using namespace std;
  
int main(){
    const int SIZE = 255;
    char some_text[SIZE] ={0};
    cout << "Enter your text:";
    gets_s(some_text, SIZE);
    int i=0;
    string result;
    for(i=0; i< SIZE; i++){
        if (isdigit(some_text[i])){
             continue;
        }else {
           result+= some_text[i];
        }   
    }
    cout << "Your text:" << result;
    return 0;
}