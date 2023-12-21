#include<iostream>
using namespace std;
void two_dimantion_arr(int arr[],int size_of_arr){
    int arr1[size_of_arr][size_of_arr];
    for (int i=0;i<size_of_arr;i++){
        arr1[0][i]=arr[i]*2;
        arr1[1][i]=arr[i]*(-1);

        for(int j=2;j<size_of_arr;j++){
            if (j % 2==0)
                arr1[j][i]=arr[i];
            else
                arr1[j][i]=arr[i]*(-1);
        }
        if(size_of_arr %2 ==1)
            arr1[0][i]=arr[i];
    }
    for(int a=0;a<size_of_arr;a++){
        cout<<"{";
        for (int j=0;j<size_of_arr;j++){
            cout<<arr1[a][j]<<"  ";
            if(arr1[a][j]>0)
                cout<<" ";
        }
        cout<<"}"<<endl;
    }

}

int main()
{
    int N;
    cin>>N;
    int arr[100];
    for(int i=0;i<N;i++)
        cin>>arr[i];
        
    two_dimantion_arr(arr,N);
    
    return 0;
}