#include <iostream>
#include <list>
using namespace std;

        // Функція для видалення К елементів, починаючи з заданого номера
        void deleteElements(list<int>&lst, int start, int K) 
        {
        if (start < 0, start >= lst.size(), K <= 0) return;
        auto it = lst.begin();
        advance(it, start);
        while (K-- > 0 && it != lst.end()) 
        {
            it = lst.erase(it);
        }
    }

    // Функція для додавання елемента перед елементом із заданим ключем
    void addElement(std::list<int>&lst, int key, int newElement)
    {
        for (auto it = lst.begin(); it != lst.end(); ++it) 
        {
            if (*it == key)
            {
                lst.insert(it, newElement);
                break;
            }
        }
    }

    int main()
    {
       list<int> lst = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        // Видалити 3 елементи, починаючи з 2-го номера
        deleteElements(lst, 2, 3);

        // Додати елемент 100 перед елементом із ключем 5
        addElement(lst, 5, 100);

        for (int x : lst) 
        {
            cout << x << ' ';
        }
        cout << endl;

        return 0;
    }
