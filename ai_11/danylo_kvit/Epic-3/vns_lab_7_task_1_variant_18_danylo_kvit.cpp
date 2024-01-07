#include <iostream>
using namespace std;
int sum(int k, ...) {
    int *p = &k; //налаштували вказівник на параметр k
    int s = 0;
    p--;
    for (; k != 0; k--)
        s += *(p+=2);
    return s;
}
int nsd(int a, int b){
    if(a==0||b==0) return max(a,b);
    return nsd(min(a,b), max(a,b)%min(a,b));
}
int nsk2(int a, int b){
    return a*b/nsd(a,b);
}
int nsk(int k, ...){
    int*p = &k;
    int ans = 1;
    p+=3;
    for(;k!=0;k--)
        ans = nsk2(ans, *(p+=2));

    return ans;
}
int main(){
    cout << nsk(3, 1, 2, 3) << '\n';
    cout << nsk(5, 4, 2, 4, 2, 8) << '\n';
    cout << nsk(6, 1, 2, 3, 4, 5, 6) << '\n';
}