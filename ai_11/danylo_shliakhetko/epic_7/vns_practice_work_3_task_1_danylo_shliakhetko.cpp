#include <iostream>
using namespace std;

int main()
{
    // Виводимо повідомлення
    cout << "Обчислення об'єму паралелепіпеда.\n"
         << "Введіть в одному рядку довжину, ширину і висоту паралелепіпед(в сантиметрах).\n"
         << "Числа розділяйте пропусками.\n"
         << "Після введення останнього числа натискуйте < Enter > ";

    // Cтворюємо дійсні змінні a, b, h
    float a, b, h;

    // Заповнюємо змінні a, b, h з користувацького вводу
    cin >> a >> b >> h;

    // Виводимо повідомлення разом з результатом - об'ємом паралалепіпед
    cout << "Об'єм паралелепіпеда " << a * b * h << " см.куб.";
    return 0;
}