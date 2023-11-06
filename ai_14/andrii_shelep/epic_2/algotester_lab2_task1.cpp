#include <iostream>

using namespace std;

int main(){
    int r[100000];
    unsigned int N;
//вводимо к-ть чисел у масиві    
    cin >> N;
//вводимо числа
    for (int i = 0; i < N; i++) {
        cin >> r[i];
    }
//відсортовуємо масив(в умові не сказано чи масив відсортований)
    for (int j = 0; j < N - 1 ; j++){
        for (int i = 0; i < N - j - 1; i++) {
            if (r[i] > r[i+1]){
                int temp = r[i];
                r[i] = r[i+1];
                r[i+1] = temp;
            }
        }
    }
    
    switch (N)
    {
//якщо в масиві 1 елемент, то відкинувши його, ми отримаємо 0
        case 1:
            cout << 0;
        break;
//якщо в масиві 2 елементи, то потрібно залишити мінімальний
        case 2:
            cout << r[0];
        break;
//якщо в масиві більше елементів, то потрібно відкинути мінімальне або максимальне значення        
        default:
            if (r[N-1] - r[1] > r[N-2] - r[0]){
                cout << r[N-2] - r[0];
            } else if (r[N-1] - r[1] <= r[N-2] - r[0]){
                cout << r[N-1] - r[1];
            }
    }
    return 0;
}