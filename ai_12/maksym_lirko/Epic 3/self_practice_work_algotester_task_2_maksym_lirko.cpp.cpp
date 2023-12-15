#include<iostream>
using namespace std;

int main()
{
    long N,M;
    int counter=0, suma;

    cin>>N;

    long array1[N];
    
    for (int i2 = 0; i2 < N; i2++)
    {
        cin>>array1[i2];
    }

    cin>>M;

    long array2[M];

    for (int j =0; j < M; j++)
        {
            cin>>array2[j];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if(array1[i]==array2[j])
                {
                    counter++;
                }
            }
        }

        cout<<counter<<endl;
        suma=(N+M)-counter;
        cout<<suma<<endl;
        
    return 0;
}