#include <iostream>
#include <cmath>
using namespace std;

int main() {
int a = 1;
int b = 2;
int c = 5;
int d = 10;
int e = 20;
int f = 50;
int g = 100;
int h = 200;
int i = 500;
long long cpresent;
long long num = 0;
cin >> cpresent;
if(cpresent <= 0){
return 0;
}
while(cpresent >= i){
cpresent -= i;
num++;
}

while(cpresent >= h){
cpresent -= h;
num++;
}

while(cpresent >= g){
cpresent -= g;
num++;
}

while(cpresent >= f){
cpresent -= f;
num++;
}

while(cpresent >= e){
cpresent -= e;
num++;
}

while(cpresent >= d){
cpresent -= d;
num++;
}

while(cpresent >= c){
cpresent -= c;
num++;
}

while(cpresent >= b){
cpresent -= b;
num++;
}

while(cpresent >= a){
cpresent -= a;
num++;
}

cout<<num<<endl;

}