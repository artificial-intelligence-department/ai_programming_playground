#include <iostream>
using namespace std;



void Print_k(int array[],int n,int k);
void BubbleSort(int array[],int n);
void DeleteEven(int array[],int &n);
int main(){

    int N;
    cout << "Enter size of array ";
    cin >> N;
    int array[N];
    
    
    for(int i = 0;i < N;i++)
    {
        cin >> array[i];
    }
    int k;
    cout << "Enter position";
    cin >> k;
    
    Print_k(array,N,k);
    DeleteEven(array,N);
    BubbleSort(array,N);
    Print_k(array,N,k);

    return 0;
}

void Print_k(int array[],int n,int k){
 for (int i = k; i < n ; ++i) 
 {
    cout << array[i] << " ";
 }
 for (int i = 0; i < k; ++i) 
 {
    cout << array[i] << " ";
 }
 
    cout << endl;
}

void BubbleSort(int array[],int n){
     for (int i = 0; i < n; i++)
    {
    for (int j ; j < n - i ; j++)
        {
        if(array[j]>array[j+1])
            {
                swap (array[j],array[j+1]);
            }
        } 
    }
    
}
void DeleteEven(int array[],int &n){
    int newsize = 0;
    for(int i=0;i<n;i++){
        if (array[i] % 2 != 0)
        {
           array[newsize]=array[i];
           ++newsize;

           
        }  
    }
    n = newsize;
}