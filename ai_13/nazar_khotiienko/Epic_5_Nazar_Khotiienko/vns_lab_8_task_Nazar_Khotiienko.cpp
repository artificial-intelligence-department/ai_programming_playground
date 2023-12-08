#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int Long = 3;

struct Information
{
    string nosiy;
    double obem;
    string name;
    string author;

    void PRINT()
    {
        cout << "Носій: " << nosiy << endl;
        cout << "Об'єм: " << obem << endl;
        cout << "Назва: " << name << endl;
        cout << "Автор: " << author << endl;
        cout << endl;
    }
};

int main()
{

    Information neww{"XXX", 100, "XXX", "XXX"};

    Information info[Long] = {{"USB", 16, "Best", "User777"},
                              {"DVD", 8, "Great", "Developer123"},
                              {"CD", 4, "Awesome", "Coder456"}};


    cout << "Вкажіть елемент із заданим об’ємом інформації: ";
    int a;
    cin >> a;

    for (int i = 0; i < Long; ++i)
    {
        if (info[i].obem == a)
        {
            info[i] = neww;
            break; // Зупиняємо цикл, якщо інформація знайдена
        }
    }

       for (int i = 0; i < Long; ++i)
    {
    info[i].PRINT();
    }

return 0;
}

//  g++ -std=c++11 Lab_8.cpp -o Lab_8
//  ./Lab_8
