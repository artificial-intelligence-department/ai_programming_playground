//v-16
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//фунція для генерації випадкових чисел і запису їх в вектор
vector<int> random_nums(int size) {
    vector<int> v(size);
    for (int i = 0; i < size; ++i) {
        //якщо любе число поділити на 10, то залишок буде від 0 до 9 і 1 додаємо, щоб було від 1 до 10
        v[i] = rand() % 10 + 1;
    }
    return v;
}

//функція для виведення вектора на екран
void print_vector(vector<int> v) {
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

//функція для знаходження середнього арифметичного
double find_avg(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
    }
    //приводимо до типу double, щоб отримати дробове число
    return static_cast<double>(sum) / v.size();
}

int main() {
    //задаэмо сід, який залежить від часу для генерації випадкових чисел(час завжди різний, отже і сід теж)
    srand(time(0));

    //створюємо вектор і заповнюємо його випадковими числами
    vector<int> numbers = random_nums(10);
    print_vector(numbers);
    cout << find_avg(numbers) << endl;

    return 0;
}