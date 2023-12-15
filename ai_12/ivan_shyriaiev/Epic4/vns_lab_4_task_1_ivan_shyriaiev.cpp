#include<iostream>
#include<random>
#include<time.h>
using namespace std;
void printarray(int array[], int n){
        for( int i = 0; i<n; i++)
            cout<< array[i]<<" ";
}
int main(){
    int array[100];
    int n, i, j, k;
    cin>> n;
    srand(time(0));
 
        for( i = 0; i<n; i++){
            array[i] = rand()%10;
            cout<< array[i]<<" ";
        }
        cout<<"\n";
        
        cin>> k ;
        
        cout<< "\n";

        for(i=k;i<n;i++)
            array[i]=array[i+1];
        n--;
        printarray(array, n);
        cout<<"\n";
        
    int firstelement = array[0];

        for(i=0; i<n; i++){
            if(array[i]%2==0){
                for(j=n;j>i;j--)
                    array[j+1]=array[j];
                
                array[i+1]=array[0];
                n++;
                i++;
            }
        }

        printarray(array,n);
                    
return 0 ;
}
