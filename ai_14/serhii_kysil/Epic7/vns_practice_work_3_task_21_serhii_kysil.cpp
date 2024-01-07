#include <iostream>
using namespace std;
double bank(int money){ //параметр функції(16) використав функцію, щоб помістити дві задачі в один файл
    double first = money + (0.03 * money);
    double second = first + (0.03 * first);
    cout << "Сума вашого внеску після 2-х років: ";
    return second;
}
int main(){
    double first_om, second_om, summary_om;
    cout << "Величина першого опору (Ом) > ";
    cin >> first_om;
    cout << "Величина другого опору (Ом) > ";
    cin >> second_om;
    summary_om = first_om + second_om;
    cout << "Опір ланцюга: " << summary_om << " Ом" << endl;
    cout << "Введіть початковий внесок: ";
    int m;
    cin >> m; //функція введення даних(21), для введення аргумента функції
    cout << bank(m); //аргумент функції(16), для виклику функції bank
    return 0;
}
