#include <iostream>
#include <cstring> 


using namespace std;

int main() {
    char rad[255];
    cout<<"Введіть рядок: ";
    gets(rad);
    char* scape;
    scape=strtok(rad, " ");
    while(scape!=0){
        int num=0;
        for(int i=0; scape[i]!=0; i++){
            if(isdigit(scape[i])){
                num++;
            }
        }
        if(num==1){
           
            puts(scape);
        }
        scape=strtok(0, " ");
    }

    return 0;
}

