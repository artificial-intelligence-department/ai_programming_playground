#include <iostream>
using namespace std;
int main(){
    int n; //цілочисельна змінна(1), для визначення кількості членів 
    float s = 0; //дійсна змінна(2), для збереження суми членів
    cout << "Введіть кількість чисел для підсумовування: ";
    cin >> n;
    if (n <= 0){ //умовний оператор(5), для заборони введенню від'ємного значення n
        cout << "Кількість чисел повинна бути додатним цілим числом." << endl;
        return 1;
    }
    for (int i = 1; i <= n; ++i){ //цикл for(10), для підрахунку усіх членів
        s += i;
    }
    cout << "Сума перших " << n << " цілих додатних чисел: " << s << endl;
    return 0;
}
