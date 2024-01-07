#include <cmath>
#include <cstdio>
using namespace std;
int main(){
    float a = 0.1;
    float b = 0.8;
    float k = 10;
    float step = (b-a)/k;
    int n = 50;
    double ans = 0;
    for(float i=a;i<=b;i=i+step){
        printf("%.2f primary: %.4f", i, 1.0/2 - 3.1415/4 * abs(sin(i)));
        for(int j = 1; j<=n; j++) {
            ans += cos(2.0 * j * i)/(4*j*j - 1);

        }
        printf(" alternative: %0.4lf\n", ans);
        ans = 0;
    }
    return 0;
}
