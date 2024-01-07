#include <iostream>

using namespace std;

int main() {

    int notebooks, pencils;  //в коді використано декілька цілочисельних змінних
    float n_price, p_price;

    cout << "Введіть вартість зошита (якщо з копійками, то через крапку): ";
    cin >> n_price;
    cout << "Введіть вартість олівця (якщо з копійками, то через крапку): ";
    cin >> p_price;
    cout << "Введіть кількість зошитів: ";
    cin >> notebooks;
    cout << "Введіть кількість олівців: ";
    cin >> pencils;
    if (pencils <=0 || notebooks <=0 || p_price <=0 || n_price <=0 ) {  // використано оператори умови і 
        cout << "Ви маєте КУПИТИ і олівець, і зошит!";                  // розгалуження для точнішого виводу
        return 0;
    }

    float sum;
    sum = n_price*notebooks + p_price*pencils;
    if (notebooks == 1 && pencils ==1) {
        cout << "Загальна вартість 1 зошита і 1 олівця " << sum << " гривень";
    }
    else if (notebooks == 1) {
        cout << "Загальна вартість 1 зошита i " << pencils << " олівців " << sum << " гривень";
    }
    else if (pencils == 1) {
        cout << "Загальна вартість " << notebooks << " зошитів і 1 олівця " << sum << " гривень";
    }
    else {
        cout << "Загальна вартість " << notebooks << " зошитів і "<< pencils << " олівців " << sum << " гривень";
    }

return 0;

}