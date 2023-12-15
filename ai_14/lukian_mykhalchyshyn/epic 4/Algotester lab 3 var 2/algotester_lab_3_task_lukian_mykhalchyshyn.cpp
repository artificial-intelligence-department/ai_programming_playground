#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main ()
{   int N, M;

    cout << "Введіть розмір масиву N: ";
    cin >> N;

    int* array1 = new int[N];
        for (int i = 0; i < N; i++) 
        {  
	        cin >> array1[i];  
	    }
            
    cout << "Введіть розмір масиву M: ";
    cin >> M;
    
    int* array2 = new int[M];
        for (int j = 0; j < M; j++) 
        {  
	        cin >> array2[j];  
	    }

    unordered_set <int> common_Elements; // використовуєм unordered_set для зберігання елементів: insert для додавання чисел, find для перевірки їх наявності і size для виводу розміру множини
         for (int i = 0; i < N; i++) 
        {
            common_Elements.insert(array1[i]); // додавання елементів 1 масиву до множини
        }

    int common_Count = 0;
    for (int j = 0; j < M; j++) 
        {
            if (common_Elements.find(array2[j]) != common_Elements.end()) // пошук спільних елемнтів
            {
                 common_Count++;
            }
        }

    unordered_set <int> unique_Elements;
        for (int i = 0; i < N; i++) 
        {
            unique_Elements.insert(array1[i]); // додавання числа до множини
        }
        for (int j = 0; j < M; j++) 
        {
            unique_Elements.insert(array2[j]);
        }

    
    cout << "Cпільні елементи: " << common_Count << endl; 
    cout << "Унікальні елементи: " << unique_Elements.size() << endl;

    delete []array1;
    delete []array2;
    
    return 0;
}