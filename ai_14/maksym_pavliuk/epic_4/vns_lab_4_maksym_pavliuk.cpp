#include<iostream>
using namespace std;
#include<time.h>

int main(){
    int restr=100, minimal=101, N=100, Sum=0, Half;
    cout << "Input the number of elements in the array: ";
    cin >> N;
    int Numbers[N];

    srand( time(NULL) );

    for(int i=0; i<N; i++){
        Numbers[i] = rand() % restr;
        cout << Numbers[i] << " ";
        minimal = min(minimal, Numbers[i]);
    }
    for(int i=0; i<N; i++)
    {
        if(Numbers[i]==minimal)
        {
            for(int j=i; j<(N-1); j++)
                Numbers[j] = Numbers[j+1];
            i--;
            N--;
        }
    }
    cout <<endl;
    for(int i=0; i<N; i++){
        cout << Numbers[i] << " ";
        Sum += Numbers[i];
    }
    cout<<endl;
    Half = Sum/N;
    int NewArrLength = N+3;
    int a[NewArrLength];
    for(int i = 2; i <N+3; i++){
        a[i] = Numbers[i-3];
    }
    for(int i=0; i<=2; i++){
        a[i] = Half;
    }
    for(int i=0; i<N+3; i++){
        cout << a[i] << " ";
    }
    cout <<endl;
    return 0;
}