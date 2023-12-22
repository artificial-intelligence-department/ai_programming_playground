#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, k=0, v=0, resk=0, resv=0;
    cin>>n;
    char r;
    for(int i=0; i<n; i++){
        cin>>r;
        if(r=='K'){
            k++;
        }else if(r=='V'){
            v++;
        }
         if((k>= 11 || v>= 11) && abs(k-v) >= 2){
            if(r=='K'){
                resk++;
            }else if(r=='V'){
                resv++;
            }
        k=0;
        v=0;
         }
    }
    cout<<resk<<":"<<resv<<endl;
    if(k>0 || v>0){
        cout<<k<<":"<<v<<endl;
    }
   return 0;
}

