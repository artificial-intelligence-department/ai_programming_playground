#include <iostream>

using namespace std;

int main(){
    //Task 2
    int n,m=0;
    cin>>n>>m;
    bool c = m-->m;
    cout<<"n++*m = "<<(n++*m)<<" (= n*m, n+=1)"<<'\n';
    cout<<(n++<m)<<" depends on n,m True(if n+1<m) False if n+1>=m"<<'\n';
    cout<<(c)<<" always true"<<'\n';
    return 0;
}