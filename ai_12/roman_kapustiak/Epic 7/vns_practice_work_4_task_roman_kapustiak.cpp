#include <iostream>
#include <fstream>

using namespace std;

const int LENGTH = 10;
const int SEQUENCES_COUNT = 3;  // Вимога #4 - в коді використана як мінімум одна цілочисельна константа

struct Sequences  // Вимога #14 - в коді використано структури 
{
    int data[SEQUENCES_COUNT][LENGTH]; // Вимога #7 - в коді використаний двовимірний масив, для збереження даних послідовностей.
    float average[SEQUENCES_COUNT];  // Вимога #6 - в коді використаний одновимірний масив, для збереження середніх арифметичних значень послідовностей.
};

void GenerateSequence(int array[], int length, int index);

int main()
{
    Sequences s;
    int temp = 0; // Вимога #1 - в коді використана як мінімум одна цілочисельна змінна
    string buffer;
    fstream file;
    file.open("Sequences.txt", ios::out);  // Вимога #19 - в коді використано функції роботи з файлами, для того, щоб записати у файл послідовності.
    srand (time(NULL));

    for(int i = 0; i < SEQUENCES_COUNT; i++)
    {
        GenerateSequence(s.data[i], LENGTH, 0);
        temp = 0;

        for(int j = 0; j < LENGTH; j++)
        {
            file << s.data[i][j] << " ";
            temp += s.data[i][j];
        }
        s.average[i] = (float) temp / LENGTH;
        file << endl;
    }

    file.close();

    file.open("Sequences.txt", ios::in);  // Вимога #20 - в коді використано функції роботи з файлами, для того, щоб зчитати з файлу послідовності.

    int k = 0;
    getline(file, buffer);
    do
    {
        cout << buffer;
        cout << "Average: " << s.average[k] << endl;
        k++;
    }
    while(getline(file, buffer));   // Вимога #8 - в коді використаний do while цикл для порядкового читання полсідовностей з файлу.

    return 0;
}
void GenerateSequence(int array[], int length, int index)
{
    if(index == length)
    {
        return;
    }
    int v = rand() % 10 + 1;
    array[index] = v;
    GenerateSequence(array, length, index + 1);  // Вимога #15 - в коді використано рекурсивну функцію для генерації значень послідовності.
    return;
}
