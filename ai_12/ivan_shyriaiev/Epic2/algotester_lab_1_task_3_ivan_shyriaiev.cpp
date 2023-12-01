#include<iostream> 
using namespace std;
int main(){
    int  i;
    long long cubesSideLengths[5];
    
    for(i=0; i<5; i++){
cin>>cubesSideLengths[i];
if(cubesSideLengths[i]<1){
    cout<<"ERROR\n";
    return 0;
        } else if(i>0 && cubesSideLengths[i-1]<cubesSideLengths[i]){
            cout<<"LOSS\n";
            return 0;
        }
    }
cout<<"WIN\n";
return 0;
}
