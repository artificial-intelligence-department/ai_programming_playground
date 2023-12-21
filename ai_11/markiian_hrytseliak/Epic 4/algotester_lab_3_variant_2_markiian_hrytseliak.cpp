#include <iostream>

using namespace std;

int main()
{   
    int N,M;

    cin>>N;

    int arr1[N];

    for(int i=0; i<N; i++)
    {
        cin>>arr1[i];
    }

    cin>>M;

    int arr2[M];

    for(int j=0; j<M; j++)
    {
        cin>>arr2[j];
    }

    int count1=0;

    for(int i=0; i<N; i++)
    {   
        for(int j=0; j<M; j++)
        {
            if (arr1[i]==arr2[j])
            {
                count1++;
            }
        
        }
    }

    int count2=M+N;

    for(int i=0; i<N; i++)
    {   
        for(int j=0; j<M; j++)
        {
            if (arr1[i] == arr2[j])
            {
                count2--;
            }
        
        }
    }
    cout <<count1 <<endl << count2;
    return 0;
}