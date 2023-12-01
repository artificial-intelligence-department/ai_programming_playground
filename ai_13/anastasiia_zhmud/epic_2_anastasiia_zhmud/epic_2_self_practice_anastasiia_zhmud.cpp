#include<iostream>
#include<string>
using namespace std;
int main(){
    int n, vasia=0, kolia=0, k=0, v=0;
    cin>>n;
    string c;
    cin>>c;
    for(int i=0; i<n; i++){
        if( c[i]=='V'){
            vasia++;
        }
        else {
            kolia++;
        }
        if((kolia>10)&&(kolia>vasia+1)){
            k++;
            kolia=0;
            vasia=0;
        }   
        else if((vasia>10)&&(vasia>kolia+1)){
            v++;
            kolia=0;
            vasia=0;
        }
    }
    cout<<k<<":"<<v<<endl;
    if(kolia!=0 or vasia!=0){
    cout<<kolia<<":"<<vasia;
    }
    return 0;
}