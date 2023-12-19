#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

// Ініціалізація масиву з випадкових чисел, довжина задана користувачем
void GetArray(int a[], int arrSize) {
    // Ініціалізація генератора випадкових чисел за поточним часом
    srand(time(0));
    // Генерація випадкових чисел для масиву
    for (int i = 0; i < arrSize; ++i) {
        a[i] = rand() % 977; // Генерація чисел від 0 до 976
    }
}

void PrintArray (const int a[], int arrSize){
    for (int i; i< arrSize; i++){
        cout << a[i] << " ";
    } 
}

    //створюємо новий вектор на основі старого, ігноруючі числа кратні 7-ми
vector<int> Delete7Multiplicity(vector<int>& myVector)
{
    vector<int> newVector;
    for(int i = 0; i < myVector.size(); i++)
    {
        if(myVector[i] % 7 != 0)
            newVector.push_back(myVector[i]);
    }
    return newVector;
}

void Print7Multiplicity(vector<int>& myVector){
cout << "Vector after deleting: ";
//змінній нам присвоюється при кожній ітерації елемент вектора, з яким потім виконується умова
    for (int num : myVector) {
        cout << num << " ";
    }
    cout << endl;
}
int main() {
    unsigned int arrSize;
    int a[100];
    cout << "Enter number of elements in array (from 1 to 100): ";
    cin >> arrSize;
    GetArray (a, arrSize);
    cout << "Your array: ";
    PrintArray(a, arrSize);
    cout << endl;
    vector<int> myVector(a, a + arrSize);
    // Викликаємо функцію для видалення елементів, які діляться на 7
    myVector = Delete7Multiplicity(myVector);
    // Викликаємо функцію для виведення елементів після видалення
    Print7Multiplicity(myVector);
return 0;
}