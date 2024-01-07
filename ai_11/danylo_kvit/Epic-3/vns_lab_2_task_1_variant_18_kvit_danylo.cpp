#include <cstdio>
using namespace std;
double f(int x){
    if(x==0) return 1.0;
    return x*f(x-1);
}
int main(){
    int i = 1;
    double ans = 0;
    while(i*i*i/f(3*i-3)>0.00001) {
        ans += i * i * i / f(3 * i - 3);
        i++;
    }
    printf("%lf", ans);
}
