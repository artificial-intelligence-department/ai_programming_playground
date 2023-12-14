#include<iostream>
#include<math.h>

using namespace std;

struct trapezium //14. в коді використано структури
{
    double a;
    double b;
    double h;

    void area_trapezium(){
        cout << "Площа трапеції: " << ((a+b)/2*h);
    }
};


void volume_of_a_cube(int a){
    cout << "Обєм куба із цілочисельними значенями: " << pow(a, 3) << endl; //17. в коді використано математичні операції та математичні функції
}

void volume_of_a_cube(double a){
    cout << "Обєм куба із дійсними значенями: " << pow(a, 3) << endl; //17. в коді використано математичні операції та математичні функції
}

int main(){
    int a1;
    double a2;  //2. в коді використана як мінімум одна дійсна змінна
    trapezium trapezium1;
    cout << "Введіть цілочисельне значення: ";
    cin >> a1;

    cout << "Введіть дійсне значення: ";
    cin >> a2;

    volume_of_a_cube(a1); //12. в коді використано перевантаження функції
    volume_of_a_cube(a2); //12. в коді використано перевантаження функції

    cout << "Введіть 1 основу трапеції: ";
    cin >> trapezium1.a;

    cout << "Введіть 2 основу трапеції: ";
    cin >> trapezium1.b;
    
    cout << "Введіть висоту трапеції: ";
    cin >> trapezium1.h;
    
    trapezium1.area_trapezium();
    
    return 0;
}