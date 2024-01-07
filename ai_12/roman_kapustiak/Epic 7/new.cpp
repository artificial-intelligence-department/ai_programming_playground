#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int PR_NUM = 962; // Вимога 4 - в коді використана як мінімум одна цілочисельна константа
const int m_size = 10;
const char* name = "Sum.txt";

float** createM(int size);
void sortM(float** m, double data);
void sortM(int** m, int data);
void printM(float** m);
int* sumM(float** m);
bool saveArray(int* arr);
int productCount(int *ar, int index, int prod);
int getArrayProd();
void deleteFile();
void printAr(int* a);

int main()
{
    float** m;
    double data; // Вимога 3 - в коді використана як мінімум одна дійсний з подвійною точністю змінна

    m = createM(m_size);

    cout << "TASK 1\n\n";
    printM(m);

    cout << "\nTASK 2\n\n";
    cout << "data: ";
    cin >> data;  // Вимога 21 - в коді використано оператори виведення та введення даних

    sortM(m, data * PR_NUM);

    printM(m);

    cout << "\nTASK 3\n\n";
    srand (time(NULL));

    int* res = sumM(m);
    printAr(res);

    cout << endl;
    
    cout << "\nTASK 4\n\n";
    bool saved = saveArray(res);

    cout << saved; 

    cout << "\nTASK 5\n\n";
    getArrayProd();

    cout << "\nTASK 6\n\n";
    deleteFile();

    return 0;
}
float** createM(int size)
{
    float** m; // Вимога 7 - в коді використаний двовимірний масив 
    m = new float*[size];

    for(int i = 0; i < size; i++) // Вимога 10 - в коді використаний for цикл 
    {
        m[i] = new float[size];

        for(int j = 0; j < size; j++)
        {
            m[i][j] = (pow(-1 * i, j) + sin(j) + 3.1) / pow(j+1, 2); //  Вимога 17 в коді використано математичні операції та математичні функції
        }
    }

    return m;
}
void sortM(float** m, double data)
{
    float temp; // Вимога 2 - в коді використана як мінімум одна дійсна змінна
    for(int k = 0; k < m_size; k++)
    {
        for (int i = 0; i < m_size - 1; i++) {

            for (int j = 0; ; j++)
            {
                if (m[j][k] > m[j + 1][k])
                {
                    temp = m[j][k];
                    m[j][k] = m[j + 1][k];
                    m[j + 1][k] = temp;
                }
                if(j < m_size - i - 1)
                {
                    break; // Вимога 11 - в коді використано оператори break і continue
                }
            }
        }
    }

    return;
}
void sortM(int** m, int data)
{
    int temp; // Вимога 1 - в коді використана як мінімум одна цілочисельна змінна
    for(int k = 0; k < m_size; k++)
    {
        for (int i = 0; i < m_size - 1; i++) {

            for (int j = 0; j < m_size - i - 1; j++)
            {
                if (m[k][j] < m[k][j + 1]) // Вимога 5 - в коді використані умовні оператори та розгалуження
                {
                    temp = m[k][j];
                    m[k][j] = m[k][j + 1];
                    m[k][j + 1] = temp;
                }
            }
        }
    }

    return;
}
void printM(float** m)
{
    for(int i =0; i < m_size; i++)
    {

        for(int j = 0; j < m_size; j++)
        {
            printf("%.3f ", m[i][j]);
        }
        cout << endl;
    }
}
int* sumM(float** m)
{
    int k;    
    int* result = new int[10]; // Вимога 6 - в коді використаний одновимірний масив
    for(int i = 0; i < m_size; i++)
    {
        int sum = 0;
        k = rand() % m_size;
        sum += (int) m[i][k];
        k = rand() % m_size;
        sum += (int) m[i][k];
        k = rand() % m_size;
        sum += (int) m[i][k];

        result[i] = sum;
    }

    return result;
}
bool saveArray(int* arr)
{
    fstream file;
    file.open(name, ios::out); // Вимога 20 - в коді використано функції роботи з файлами, для того, щоб зчитати з файлу

    if(!(file))
    {
        return false;
    }

    for(int i = 0; i < m_size; i++)
    {
        file << arr[i] << " ";
    }
    file.close();

    return true;
}
int productCount(int *ar, int index, int prod) //  Вимога 16 - в коді використано параметри та аргументи функції	
{
    if(index == m_size)
    {
        cout << prod << endl;
        return prod;
    }
    else if(index == 0)
    {
        prod = 1;
    }

    prod *= ar[index];

    return productCount(ar, index + 1, prod);
}
int getArrayProd()
{
    fstream file; // Вимога 19 - в коді використано функції роботи з файлами, для того, щоб записати у файл
    file.open(name, ios::in);
    int* arr = new int[m_size];
    int s;
    int i = 0;
    while(i < m_size) // Вимога 9 - в коді використаний while цикл
    {
        file >> s;
        arr[i] = s;
        i++;
    }
    file.close();

    return productCount(arr, 0, 1); //  Вимога 15 - в коді використано перевантаження функції 
}
void deleteFile()
{
    remove(name);
    cout << "Deleted\n";
    return;
}
void printAr(int* a)
{
    int i = 0;
    do // Вимога 8 - в коді використаний do while цикл
    {
        cout << a[i] << " ";
        i++;
    }
    while(i < m_size);
}
