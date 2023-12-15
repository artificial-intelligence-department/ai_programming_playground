#include<iostream>
using namespace std;

int main(){
long long n, cup[]={500, 200, 100, 50, 20, 10, 5, 2, 1};
int s = 0;

cin >> n;

for(int i = 0; i < 9; i++){
    s += n/cup[i];
    n %= cup[i];
}
cout << s;

    return 0;
}