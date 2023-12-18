#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
bool more(const char* a,const char* b){
    if(*a=='\0'&&*b=='\0') return true;
    if(*a=='\0') return false;
    if(*b=='\0') return true;
    if(*a>*b) return true;
    if(*a<*b) return false;
    if(*a==*b) return more(a+1,b+1);
}
int main(){
    char a[255];
    fgets(a,255,stdin);
    char** b = new char*[128];
    int* lens = new int[128];
    int x=0,y=0;
    bool flag = false;
    int total = 0;
    for(int i=0;i<255;i++){
        if(isdigit(a[i])&&(i==0||a[i-1]==' ')) {
            flag = true;
            total++;
            b[x] = new char[255];
            lens[x]=0;
        }
        if(a[i]==' '||a[i]=='\0') {
            if (flag){
                b[x][y]='\0';
                x++;
            }
            y = 0;
            flag = false;
        }
        if(flag) {
            b[x][y] = a[i];
            y++;
            lens[x]++;
        }
    }
    for(int i=x-1;i>=0;i--){
        for(int j=0;j<i;j++){
            if(more(b[j],b[i])){
                char* p = b[j];
                b[j] = b[i];
                b[i] = p;
                int l = lens[j];
                lens[j] = lens[i];
                lens[i] = l;
            }
        }
    }
    for(int i=0;i<total;i++){
        for(int j=0;j<lens[i];j++){
            cout<<b[i][j];
        }
        cout << '\n';
    }
}