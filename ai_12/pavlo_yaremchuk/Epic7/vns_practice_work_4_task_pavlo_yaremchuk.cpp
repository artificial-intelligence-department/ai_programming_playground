#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Оголошення змінної two для зберігання значень степенів двійки
    int two;

    //Виведення заголовка для ступенів двійки
    cout << "степінь:" << " степінь двійки:" << endl;

    //Цикл для обчислення та виведення степенів двійки від 0 до 10
    for (int i = 0; i < 11; ++i)
    {
        //Обчислення 2 в степені i
        two = pow(2, i);

        //Виведення результату
        cout << i << "\t " << two << endl;
    }

    return 0;
}