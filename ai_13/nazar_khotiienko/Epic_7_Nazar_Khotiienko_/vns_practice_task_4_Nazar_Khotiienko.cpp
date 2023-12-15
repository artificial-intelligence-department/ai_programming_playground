// 16 Варіант
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // встановлює генератор рандомних чисел на основі поточного часу
    srand(time(0));
    // створення змінної
    int Long = 10;
    // створення одновимірного масиву
    int mas[Long];

    // цикл заповнення одновимірного масиву рандомними числами від 1 до 10
    for (int i = 0; i < Long; ++i)
    {
        mas[i] = rand() % 10 + 1;
    }
    // цикл виведення даних одновимірного масиву
    for (int i = 0; i < Long; ++i)
    {
        cout << mas[i]<<" ";
    }
    // виведення enter
    cout <<endl;
    //створення дійсної змінної
    double sum = 0;
    //цикл додавання до змінної всіх елементів масиву
    for (int i = 0; i < Long; ++i) {
        sum += mas[i];
    }
    // розрахунок середнього арифметичного
    double end = sum / Long;
    // вивід середнього арифметичного
    cout << end <<endl;
}