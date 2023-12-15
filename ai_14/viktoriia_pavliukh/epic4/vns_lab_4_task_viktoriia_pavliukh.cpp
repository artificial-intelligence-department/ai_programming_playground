#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int randomDigits_size;
    cout << "Введіть розмір масиву: ";
    cin >> randomDigits_size;
    vector<int> randomDigits;
    for (int i = 0; i < randomDigits_size; i++)
    {
        randomDigits.push_back(rand());
        cout << randomDigits[i]<< " " ;
    }
    cout <<endl;
    if(randomDigits[randomDigits_size-1]==0){
                randomDigits.pop_back();
                cout << "Масив, після видалення останнього елемента: ";
        for(int i = 0; i < randomDigits_size; ++i)
            cout << randomDigits[i] << " ";
    }

    int index;
    cout << "Введіть індекс, після якого потрібно вставити новий елемент: ";
    cin >> index;

    if (index >= 0 && index < randomDigits_size)
    {
        randomDigits.insert(randomDigits.begin() + index + 1, 100);

        cout << "Масив після вставки нового елемента зі значенням 100: ";
        for (int i = 0; i < randomDigits.size(); ++i)
            cout << randomDigits[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "Некоректний індекс для вставки." << endl;
    }
    return 0;
}



