#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int count(int m, double x, double* d){
    int ans = 0;
    for(int i=0;i<m;i++) ans+=int(d[i]/x);
    return ans;
}
int f(double* len, int m, double x){
    for(int i=0;i<m;i++) if(x==len[i]) return i;
    return -1;
}
double max_el(double* len, int m){
    double ans = len[0];
    for(int i=0;i<m;i++) ans = max(ans,len[i]);
    return ans;
}
int main(){
    int n, m;
    cin >> n >> m;
    auto* d = new double[m];
    for(int i=0;i<m;i++) cin >> d[i];
    int* r = new int[m];
    auto* len = new double[m];
    for(int i=0;i<m;i++) r[i]=1;
    for(int i=0;i<m;i++) {len[i]=d[i]/r[i]; }
    double x;
    int ind_x;
    while(true){
        x = max_el(len,m);
        ind_x = f(len,m,x);
        if(count(m, x, d)>=n){
            printf("%.8lf", x);
            break;
        }
        r[ind_x]+=1;
        len[ind_x]=d[ind_x]/r[ind_x];
    }
    return 0;
}
