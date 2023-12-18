//
#include <iostream>
#include <vector>
using namespace std;  

int main ()
{
    int N, K;
    cin >> N >> K;
    int a[N];
    for (int i=0; i< N; i++){
        cin >> a[i];
    }
    
    for (int i= 0; i< N; i++)
    {
        for (int  j=0; j< N-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]= temp;
            }
        }
    }

    vector<int> c; 
    c.push_back(a[0]);  
    for (int i = 1; i < N; i++) 
    {   
        if(a[i] != a[i-1])
            c.push_back(a[i]);
    }
    cout << c.size() << endl;
    int result[c.size()];

        //перевірка різних значень K
    if(K > c.size())
        K = K % c.size();
    else if (K == N)
    {
        for (int i = 0; i < c.size(); i++)
            cout << c[i] << " "; 
        return 0;
    }
    
    for (int i = 0, j = 0; i < c.size(); i++)
    {
        if(K > 0) {// проходимось по першим K-им елементам масиву і записуємо їх у кінець
            K--;
            result[c.size()-1 - K] = c[i]; 
            }
        else // записуємо всі елементи в початок 
            result[j++] = c[i];
    }
    
        //вивід данних
    for (int i = 0; i < c.size(); i++) 
        cout << result[i] << " ";
    return 0;
}