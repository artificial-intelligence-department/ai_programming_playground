#include <stdio.h>  
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
void review(int *mas, int n, int K)
{
    K=K%n;
    for(int i=K-1; i<n; i++)
    {
        printf("%d ", mas[i]);
    }
    for(int i=0; i<K-1; i++)
    {
        printf("%d ", mas[i]);
    }
}
void odd (int *mas, int n, int K)
{
    K=K%n;
    for(int i=K-1; i<n; i++)
    {
        if(mas[i]%2!=0)
        {
            printf("%d ", mas[i]);
        }
    }
    for(int i=0; i<K-1; i++)
    {
        if(mas[i]%2!=0)
        {
            printf("%d ", mas[i]);
        }
    }
}

int main()
{
    int K;
    cin>> K;
    int d[] = {1, 6, 3, 2, 5, 5};
    review(d, sizeof(d)/sizeof(d[0]), K);
    sort(d, d+sizeof(d)/sizeof(d[0]));
    cout<<"\nsort: ";
    review(d, sizeof(d)/sizeof(d[0]), K);
     cout<<"\nno even: ";
    odd (d, sizeof(d)/sizeof(d[0]), K);

}
