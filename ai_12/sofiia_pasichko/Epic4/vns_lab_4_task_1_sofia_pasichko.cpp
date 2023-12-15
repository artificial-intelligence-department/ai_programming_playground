#include<iostream>
#include<cstdlib>
#include <algorithm>
using namespace std;
int main()
{
int n, a_min, sum, average;
cout << "Enter the size of array:" << endl;
cin>>n;
cout << " " << endl;

int* a = new int[n];
for(int i=0; i<n; i++) {
    a[i]=rand() % 100 + 1;
    cout << a[i] << endl;
}
cout << " " << endl;

a_min=*min_element(a, a+n);
for (int i = 0; i < n; i++)
    {
        if (a[i]==a_min) {
            for (int j(i); j<n-1; ++j) a[j] = a[j + 1];
            --n;
            --i;
        }
    }
    for (int i=0; i < n; i++)
    {
        cout << a[i] << endl;
    }
cout << " " << endl;

sum=0;
for (int i = 0; i < n; i++)
sum+=a[i];
average=sum/n;

cout << " " << endl;

int newElements=3;
int* newA = new int[n+newElements];

for (int i = 0; i < newElements; ++i) {
    newA[i] = average;
}
    // Додаємо 3 елементи на початок нового масиву

for (int i = 0; i < n; ++i) {
    newA[i + newElements] = a[i];
}
    // Копіюємо залишок початкового масиву в новий масив

for (int i = 0; i < n + newElements; ++i) {
    cout << newA[i] << " ";
}
    // Виводимо змінений масив

delete[] a;
return 0;
}

