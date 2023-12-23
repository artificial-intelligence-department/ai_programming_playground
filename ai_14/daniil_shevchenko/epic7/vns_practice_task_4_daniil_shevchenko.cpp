
#include <iostream>
#include <cstdarg>
#include <fstream>
#include <string>
using namespace std;
double average(int amount, ...) //Використання еліпсису(...) для створення функції без конкретної кількості аргументів
{                               //Спочатку йде змінна amount, що позначає кількість аргументів, далі йде вказана кількість чисел
                                //через кому, середнє арифметичне яких треба знайти (вимога 13)
    va_list list;
    va_start(list, amount);
    double sum = 0;
    for (int i = 0; i < amount; i++)
    {
        double x = va_arg(list, double);
        sum = sum + x;
    }
    double ave = sum / amount;
    return ave;
}
void print(int index, double number[5]) //використання рекурсивної функції(викликає саму себе), що буде виводити введені з клавіатури значення в оберненому порядку (вимога 15)
{
    if (index < 0)
    {
        return;
    }
    if (index >= 0)
    {
        cout << "The number # " << index + 1 << " equals " << number[index] << endl;
        return print(index - 1, number);
    }
}

int main()
{
    double number[5]; //створення одновимірного масиву для збереження 5 введених чисел (вимога 6)
    int i = 0;
    do //використання цикла do while з окремо створеним лічильником(цикл буде виконуватись хоча б один раз, а потім перевіряти вимогу продовження циклу) (вимога 8) 
    {
        cout << "Enter the number # " << i + 1 << " : ";
        cin >> number[i];
        i++;
    } while (i < 5);
    double ave = average(5, number[0], number[1], number[2], number[3], number[4]);
    cout << "The average value is " << ave << endl;;
    ofstream out("Task4.txt"); //використання бібліотеки fstream і експортного потоку для створення файлу і запису в нього введених чисел та їх середнього значення (вимога 19)
    if (!out)
    {
        cout << "An error occured while initializing a text file";
        exit(1);
    }
    for (int i = 0; i < 5; i++)
    {
        out << "The number # " << i + 1 << " equals " << number[i] << endl;
    }
    out << "The average value is " << ave;
    ifstream in("Read.txt"); //використання бібліотеки fstream і імпортного потоку для зчитування тексту з файлу і виведення його на екран (вимога 20)
    if (!in)
    {
        cout << "Cant find file for reading from" << endl;

    }
    else
    {
        string input;
        while (getline(in, input))
        {
            cout << input << endl;

        }
    }
    print(4, number);
}


