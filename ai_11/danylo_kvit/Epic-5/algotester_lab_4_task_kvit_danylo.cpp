#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    char a[n][m];
    for(int i=0;i<n;i++){
        string r;
        cin >> r;
        for(int j=0;j<m;j++) a[i][j]=r[j];
    }
    for(int j=0;j<m;j++){
        for(int i=n-1;i>=1;i--){
            if(a[i][j]=='O'&&a[i-1][j]=='S'){
                a[i-1][j]='O';
                a[i][j]='S';
                if(i!=n-1)
                    i+=2;
            }
        }
    }



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cout << a[i][j];
        cout << '\n';
    }
    return 0;
}