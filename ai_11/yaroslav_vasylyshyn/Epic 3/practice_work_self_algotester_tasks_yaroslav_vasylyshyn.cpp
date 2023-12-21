#include <iostream>
using namespace std;
int main() {

    int q=0;
    long k,n,c,max;
    c=0;
    max=0;
    cin>>n>>k;
    long posli[n];
    long a[n];
    long arr[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]>=k){
            c=1;
            arr[i]=c;

        }else{
            c=0;
            arr[i]=c;
        }

    }

    for(int j=0;j<n;j++) {
        posli[j]=0;
    }

    for(int j=0;j<n;j++) {
        if (arr[j]>0){
            posli[j]=posli[j]+1;
            if (arr[j+1]>0)
                posli[j+1]=posli[j];

        }else{
            posli[j]=0;
        }
    }
    for(int i=0;i<n;i++){
        if(max<posli[i])
            max=posli[i];
    }
    cout<<max;
    return 0;
}

