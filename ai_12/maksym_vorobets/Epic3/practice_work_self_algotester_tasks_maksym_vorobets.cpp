#include <iostream>

using namespace std;

int main(){
    int n;
    long s=0;
    cin>>n;
int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]>0){
        s +=a[i]-1;
        }else
        {s=0;}
    }
     cout<<s<<endl;
     
return 0;
}