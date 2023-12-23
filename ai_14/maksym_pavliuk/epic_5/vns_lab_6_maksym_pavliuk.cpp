#include<iostream>
using namespace std;

void sort_desc(char* str){
    int length = strlen(str);
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (isdigit(str[j]) && isdigit(str[j + 1]) && str[j] < str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main(){
    char str[255];
    int pcount=0;
    cout << "Your Input: ";
    gets(str);
    for(int i=0; i<strlen(str); i++){
        if(str[i]==' '){
            pcount++;
        }
    }
    for(int i=0; i<pcount; i++){
        sort_desc(str);
    }
    cout << str;


    return 0;
}