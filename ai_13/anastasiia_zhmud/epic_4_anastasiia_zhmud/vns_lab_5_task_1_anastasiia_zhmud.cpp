#include <iostream>
using namespace std;

int function(int n, int array[]){
    int array1 [n][n];
    int sum=0;
    for( int j=0; j<n; j++){
        sum=0;
        for(int i=0; i<n; i++){
            if(i==n-1){
                array1[i][j]=array[j]-sum;
            } else{
            array1[i][j]=rand();
            if(array1[i][j]==0){
                --i;
            }
            sum+=array1[i][j];
            }
        }
    }

    for( int i=0; i<n; i++){
        cout<<endl;
        for(int j=0; j<n; j++){
            cout<<array1[i][j]<<"   ";
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of array numbers:  ";
    cin>>n;
    int array[n];
    cout<<"Enter the array:  ";
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    function(n, array);
}
