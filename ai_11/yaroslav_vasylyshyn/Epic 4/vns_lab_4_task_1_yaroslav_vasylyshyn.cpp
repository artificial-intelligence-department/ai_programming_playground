#include <iostream>

using namespace std;

int main(){
    //ініціалізація змінних, початкового кільця, масиву
    int N,k,c=0;
    cin>>N>>k;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    int sort_a[N];
    //новий масив перегляду кільця від k до k-1
    for (int i = 0; i < N; i++)
    {
        if(c!=k){
            if(k+i<N)
                sort_a[i]=a[k+i];
            else{
                sort_a[i]=a[c];
                c++;
            }
        }
    }

    cout<<"Від k до k-1:"<<'\n';
    for (int i = 0; i < N; i++)
    {
        cout<<sort_a[i]<<" ";
    }
    cout<<'\n';

    N-=2;
    c=0;
    //видалення першого і останнього елементів
    int arr[N];
    for (int j = 0; j < N; j++)
    {
        arr[j]=a[j+1];
    }
    //новий масив перегляду кільця від k до k+1
    int sort_arr[N];
    for (int i = 0; i < N; i++)
    {
        if(k-i>=0){
            sort_arr[i]=arr[k-i];
        }else{
            sort_arr[i]=arr[N-1-c];
        }
    }

    cout<<"Від k до k+1 кільце без 1-го і N-го елементів:"<<'\n';
    for (int i = 0; i < N; i++)
    {
        cout<<sort_arr[i]<<" ";
    }
    return 0;
}