#include <iostream>  //підключаю бібліотеку для вводу виводу
using namespace std; // підключаю простір імен  std

int factorial(int n)//оголошуємо функцію факторіал
{
    if (n == 0)//умова виходу з рекурсії
    {
        return 1;//функція повертає 1
    }
    else
    {
        return n * factorial(n - 1);//рекурсивний виклик функцією самої себе
    }
}
int main()
{
    int number;//оголошую змінну типу int
    cin >> number;//зчитуємо дані
    int result = factorial(number);//обраховуємо факторіал викликаючи функцію factorial
    cout << result;//виводимо результат
}