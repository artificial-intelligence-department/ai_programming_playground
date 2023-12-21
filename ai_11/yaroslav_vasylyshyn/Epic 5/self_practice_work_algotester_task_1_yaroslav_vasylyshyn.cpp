#include <iostream>

using namespace std;

void sort(int a[], int size){
    for(int i=0;i<size-1;i++)
    {
        for(int j=size-1;j>i;j--)
        {
            if(a[j]<a[j-1])
                swap(a[j],a[j-1]);
        }
    }  
    cout<<size<<'\n';
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<'\n';
}

int main(){
    //Блок ініціалізації змінних та масивів
    //Задання першої множини
    int N,M,spilnea=0,spilneb=0,k=0;
    cin>>N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin>>a[i];
    }
    //Задання другої множинни
    cin>>M;
    int b[M];
    for (int i = 0; i < M; i++)
    {
        cin>>b[i];
    }
    //Допоміжні масиви
    int bufa[N],bufb[M];
    for (int i = 0; i < N; i++)
    {
        bufa[i]=0;
    }
    for (int i = 0; i < M; i++)
    {
        bufb[i]=0;
    }
    //Блок розрахунків
    //Знаходження кількості спільних елементів для другої множини
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(a[j]==b[i])
            bufb[i]=1;; 
        }
        spilneb += bufb[i];
    }
    //Знаходження кількості спільних елементів для першої множини
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(a[i]==b[j])
            bufa[i]=1; 
        }
        spilnea+=bufa[i];
    }
    //Перша множина без спільних елементів
    int sorta[N-spilnea];
    for (int i = 0; i < N; i++)
    {
        if(bufa[i] == 0)
            sorta[k++]=a[i];
    }
    sort(sorta, N-spilnea);
    //Друга множина без спільних елементів
    int sortb[M-spilneb];
    k=0;
    for (int i = 0; i < M; i++)
    {
        if(bufb[i] == 0)
            sortb[k++]=b[i];
    }
    sort(sortb, M-spilneb);
    //Знаходження кількості унікальних спільних чисел
    int spilne=0;
    k=0;
    for (int i = 0; i < N; i++)
    {
        if(bufa[i] != 0 && sorta[i] != sorta[i+1])
        spilne++;
    }
    //Знаходження масиву унікальних спільних чисел
    int sort_peretuny[spilne];
    k=0;
    for (int i = 0; i < N; i++)
    {
        if(bufa[i] != 0 && sorta[i] != sorta[i+1])
        {
            sort_peretuny[k]=a[i];
            k++;
        }
    }
    sort(sort_peretuny, spilne);
    //об'єднання множини першої без спільного другої без спільного і спільного
    int size = N-spilnea+M-spilneb+spilne;      
    int sort_full[size];
    k=0;
    for (int i = 0; i < N-spilnea; i++)
    {
        sort_full[i] = sorta[i];
    }
    for (int i = 0; i < M; i++)
    {
            sort_full[N-spilnea+i]=sortb[i];
    } 
    k=0;
    for (int i = 0; i < spilne; i++)
    {
        sort_full[N-spilnea+M-spilneb+i]=sort_peretuny[i];
    }
    sort(sort_full, size);
    //об'єднання множини першої без спільного другої без спільного
    int size1 = size - spilne;
    int symdif[size1];
    for (int i = 0; i < N; i++)
    {
        symdif[i]=sorta[i];
    }
    for (int i = 0; i < M; i++)
    {
        symdif[N-spilnea+i]=sortb[i];
    } 
    sort(symdif, size1);    
    return 0;
}