#include <iostream>
using namespace std;
int main(){
    int n, m, k=0, k1=0;
    cin>>n;
    int array1[n];
    for(int i=0; i<n; i++){
        cin>>array1[i];
    }
    cin>>m;
    int array2[m];
    for(int j=0; j<m; j++){
        cin>>array2[j];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(array1[i]==array2[j]){
                k++;
            } 
        }
    }
   cout<<k<<endl<<((n+m)-k);
}