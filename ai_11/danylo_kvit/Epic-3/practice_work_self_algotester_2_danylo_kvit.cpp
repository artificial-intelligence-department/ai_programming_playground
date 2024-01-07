#include <iostream>
using namespace std;

long find_nsd(long a, long b){
    if(a%b==0)return b;
    else if(b%a==0)return a;
    else if(a>b) return find_nsd(a%b,b);
    else if(a<b) return find_nsd(a,b%a);
}
int main(){
    int n;
    cin >> n;
    long a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    long answer=0;
    long nsd=a[0];
    for(int i=1;i<n;i++){
        nsd=find_nsd(nsd,a[i]);
    }
    for(int i=0;i<n;i++){
        answer+=a[i]/nsd;
    }
    cout << answer;
}