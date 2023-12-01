#include <iostream>
#include <string>
using namespace std;
int main(){
    long long h[4], max=0, flag=0, sum=0, sum1=0;
    long long d[4];
    string rez = "YES";
    for (int i=0; i<4; i++){
        cin>>h[i];
        if(h[i]>max){
            max=h[i];
        }
        sum+=h[i];
    }
    
    for ( int i=0; i<4; i++){
        cin>>d[i];
        sum1+=d[i];
        
    }
    if(sum+sum1==0||sum1==0){
        cout<<"YES";
        return 0;
    }
    for (int i=0; i<4; i++){
        if(d[i]>h[i]){
            cout<<"ERROR";
            flag =1;
            return 0;
        }
        h[i]=h[i]-d[i];
        max=-1;
        for(int j=0; j<4; j++){
            if(h[j]>max){
            max=h[j];
        }
        }
        if(max>=2*h[i]){
            rez = "NO";
        }
    }
    if (flag == 0){
        cout<<rez;
    }
}