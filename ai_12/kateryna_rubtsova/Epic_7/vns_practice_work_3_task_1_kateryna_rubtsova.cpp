#include <iostream>

using namespace std;

int main()
{
    // Оголошення змінних для величин опорів
    double R1, R2, R;
    // Введення величин опорів від користувача
    cout << "Введіть величину першого опору: ";
    cin>>R1;
    cout << "Введіть величину другого опору: ";
    cin>>R2;
    // Перевірка на невірно заданий опір (від'ємне значення)
    if(R1 < 0 || R2 < 0){
        cout<<"Невірно заданий опір.";
        return 0;
    }
    // Виведення величин даних опорів на екран
    cout<<"Величина першого опору (Ом) > "<< R1<<endl;
    cout<<"Величина другого опору (Ом) > "<< R2<<endl;
    // Обчислення та виведення загального опору ланцюга
    R = R1 + R2;
    cout<<"Опір ланцюга: "<< R <<" Ом.";
    
    return 0;
}