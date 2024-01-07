#include <iostream>
using namespace std;

int main()
{
    //Декларація змінних
    double s = 0.0, z = 0.0, x = 1.2, y = -0.8;
    //Обрахунки s та z за допомогою pow - піднесення до степення та косинусів та синусів
    s = 1 + x + pow(x, 2) / 2 + pow(x, 3) / 3 + pow(x, 4) / 4;
    z = (sin(pow(x, 3) + pow(cos(y), 2)));
    //Вивід результатів
    cout << "S: " << s << endl;
    cout <<"Z: " << z << endl;
}

