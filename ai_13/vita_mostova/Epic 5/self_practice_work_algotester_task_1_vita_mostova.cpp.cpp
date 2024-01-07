#include <iostream>
#include <vector>
using namespace std;
vector<int> get_primes(int n);
int solve(int n,int k);
int main(){

int n,k;
cin>>n>>k;
cout<<solve(n,k);

    return 0;
}
vector<int> get_primes(int n){
vector<bool> vykresleni(n+1,true);
vykresleni[0]=vykresleni[1]=false;
vector<int> primes;
for(int i=2;i<=n;i++){
    if(vykresleni[i]){
        primes.push_back(i);
        for(int j=2*i;j<=n;j+=i){
            vykresleni[j]=false;}
        }
    }
return primes;
}
int solve(int n,int k){
    int max=2000000;
    vector<vector<int>>np(k+1);
    vector<int> primes=get_primes(max);
    np[0]=primes;
    for(int i=1;i<=k;++i){
        for(int j=0;j<primes.size();++j){
            if(primes[j]-1>=np[i-1].size())
            break;
            np[i].push_back(np[i-1][primes[j]-1]);
        }
    }
    return np[k][n-1];
}