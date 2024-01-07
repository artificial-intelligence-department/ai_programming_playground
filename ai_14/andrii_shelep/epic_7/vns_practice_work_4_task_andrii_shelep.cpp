#include <iostream>
#include <cstdarg> //для роботи з функціями зі змінною кількістю параметрів

using namespace std;

void showResults(int n,...) //функція зі змінною кількістю параметрів, що виводить їх значення. Використовую еліпсис у цій функції
{
    va_list list; 
    va_start(list, n);

    for(; n>0; n--)
    {
        cout << " " << va_arg(list, double) << "\t";
    }
    va_end(list);
}

double FindAverage(double* seq, int size) // функція для обчислення середнього арифметичного послідовності чисел
{
    double average;
    double sum = 0;
    for(int i = 0; i < size; i++){
        sum+=seq[i]; //додаю всі числа
    }
    average = sum/size; //ділю суму всіх чисел на їх кількість та отримую середнє
    return average;
}

int main(){
    int count;
    cout << "Введіть кількість чисел: ";
    cin >> count; //вводимо кількість чисел

    double* sequence = new double[count]; //використовую динамічний масив для дробових чисел
    cout << "Введіть числа: " << endl;
    for(int i = 0; i < count; i++){
        cin >> sequence[i]; //вводимо ці числа
    }

    double average = FindAverage(sequence, count); //викликаємо функцію знаходження середнього арифметичного
    double min_value = sequence[0]; //ініціалізовую для мінімального і максимального значення перше число
    double max_value = sequence[0];
    int i = 0;
    for(int i = 1; i < count; i++)
    {
        if(sequence[i]<min_value) //якщо наступне число більше за мінімальне, то оновлюю мінімальне значення
            min_value = sequence[i];
        if(sequence[i]>max_value) //якщо наступне число більше за максимальне, то оновлюю максимальне значення
            max_value=sequence[i];
    }
    
    cout << "\tRESULTS" << endl;
    cout << "average\t min\t max" << endl;
    showResults(3, average, min_value, max_value); //виклик функції для виведення результатів

    delete[] sequence; //звільняю пам'ять, виділену для масиву
    return 0;
}