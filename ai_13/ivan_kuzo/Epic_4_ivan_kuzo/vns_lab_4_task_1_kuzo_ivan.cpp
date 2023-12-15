#include<iostream>
using namespace std;
const int N=100;
void no_max_value(int arr[],int &size_arr){
    int max=arr[0];
    int a=0;
    for(int i=1;i<size_arr;i++){
        if(max<arr[i])
            max=arr[i];
    }
    for(int i=0;i<size_arr;i++){
        if(arr[i]!=max){
            arr[a]=arr[i];
            a++;
        }
    }
    size_arr=a;
}
void forward(int arr[],int k,int size_arr){
    for(int i=0;i<size_arr;i++){
        cout<<arr[(k+i-1)%size_arr]<<endl;
    }
}
void backward(int arr[],int k,int size_arr){
    int j=0;
    for(int i=0;i<size_arr;i++){
        if((k-i-1)>=0)
                cout<<arr[(k-i-1)]<<endl;
        else{
            cout<<arr[size_arr-j-1]<<endl;
            j++;
        }
    }
}
int main()
{
    int arr[N];
    int a=0;
    int size_arr;
    cin>>size_arr;
    size_arr=size_arr % N;
    for (int i=0;i<size_arr;i++){
        cin>>a;
        arr[i]=a;
    }
    int k=0;
    cin>>k;
    k=k%size_arr;
    cout<<endl;
    forward(arr,k,size_arr);
    no_max_value(arr,size_arr);
    cout<<endl;
    backward(arr,k,size_arr);
    



    return 0;
}