#include <iostream>
using namespace std;

int main (){
    int m;
    long long N;
    cin >> N;
    long long r [N];
    for(int i = 0; i < N; i++)
     {
        cin >> r[i];
     }
    for (int i= 0; i< N; i++)
    {
        for (int  j=0; j< N-1-i; j++)
        {
            if (r[j]>r[j+1])
            {
                int temp=r[j];
                r[j]=r[j+1];
                r[j+1]= temp;
            }
        }
    }
    if (N==1)
    {
        cout << 0;
    }
    else if (N==2){
        cout << r[N-1]-r[0];
    }
    else if (r[N-2]-r[0]<r[N-1]-r[1])
    {
    m= r[N-2]-r[0];
    cout << m;
    }
    else if (r[N-2]-r[0]>=r[N-1]-r[1])
    {
    m=(r[N-1]-r[1]);
    cout << m;
    }
    return 0;
}
