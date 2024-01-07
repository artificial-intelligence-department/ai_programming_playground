#include <iostream>
#include <stdlib.h>
using namespace std;

int form(int a[100]) //задаємо кожен елемент масиву
{
    int n, k;
    cout<<"\nEnter n: ";
    cin>>n;
    cout<<"\nEnter k: ";
    cin >>k;
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
    }
    return n;
}

void print(int a[100],int n) //виводить кожен елемент масиву
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\n";
}

void Dell(int a[100],int&n) //видаляє перший елемент масиву
{
    int j=0,i,b[100];
    for(i=0;i<n;i++)
    if(a[i]!=a[0]){
        b[j]=a[i];j++;
    }
    n=j;
    for(i=0;i<n;i++)
        a[i]=b[i];
}

int main()
{
    int a[100];
    int n, k;
    n=form(a);
    print(a,n);
    Dell(a,n);

    for (int i = 0; i < k; ++i) { //кількість зсувів
        int temp = a[n - 1]; //temp = останній елемент
        for (int j = n - 1; j > 0; --j) { //проходимося по кожному елементу масиву з кінця
            a[j] = a[j - 1]; //пересуваємо елементи, а перший елемент набуває значення останнього
        }
        a[0] = temp;
    }
    print(a,n);

    return 0;
}