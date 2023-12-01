#include <iostream>
#include <cstdio>
using namespace std;

long long int lenth[4];
long long int cut[4];
int f=2;

long long int maxel(long long int a,long long int b,long long int c,long long int d){
    long long int e=a;
    if (b>e){
        e = b;
    }
    if (c>e){
        e = c;
    }
    if (d>e){
        e = d;
    }
    return (e);
}

int main(){
for (int i = 0; i < 4; i++) {
  std::cin >> lenth[i];
}
for (int i = 0; i < 4; i++) {
  std::cin >> cut[i];
}
for (int i = 0; i < 4; i++) {
    if (lenth[i]<cut[i]){
        std::cout<< "ERROR";
        f=1;
        break;
    }
    lenth[i]=lenth[i]-cut[i];
  if ((lenth[i])*2<=maxel(lenth[0],lenth[1],lenth[2],lenth[3])){
    f=3;
  }
}
if (lenth[0]==lenth[1] && lenth[2]==lenth[3] && lenth[1]==lenth[2] && f==2){
    f=0;
    std::cout<< "YES";
}
if (f>1){
    std::cout<< "NO";
}
}