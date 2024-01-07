#include <iostream>         //підключаю бібліотеку <iostream>, яка дозволяє підключати потік виведення(cout) і введеня(cin) у програму
#include <cmath>            //підключаю бібліотеку <cmath>, яка містить функції для математичних операцій, таку як std::pow а також містить значення числа Пі
using namespace std;        //підключаю директиву, яка дозволяє використовувати простір імен std(standard) без явного зазначення кожного елемента з цього простору імен

double calculateTotalPrice(double copybookPrice, double pencilPrice, int copybookNumber, int pencilNumber)      //створюю функції, яка повертатиме значення типу double, і яка приймає змінні copybookPrice, pencilPrice, copybookNumber, pencilNumber 
{
    return copybookNumber * copybookPrice + pencilNumber * pencilPrice;         //функція повертатиме суми добутків кількості зошитів(олівців) на ціну одного зошита(олівця)
}

double calculateVolumeOfCylinder(double r1, double r2, double h)        //створюю функцію, яка повертатиме значення типу double, і яка прийматиме змінні r1, r2, h
{
    double r;           //задаю змінну типу double (бо для її обрахунку викоритовуватимуться змінні цього типу)

    if(r1 > r2)         //перевіряю умову чи r1 більше r2
    {
        r = M_PI * h * (pow(r1, 2) - pow(r2, 2));       //якщо умова справджується, то змінній r присвоюється формула, в якій r2 віднімається від r1 (це роблю для того, щоб об'єм не виходив від'ємний)
    }
    else        //якщо перша умова не справдилась
    {
        r = M_PI * h * (pow(r2, 2) - pow(r1, 2));       //якщо це так, то змінній r присвоюється формулаЮ в якій r1 вднімається від r2
    }

    return r;       //функція повертатиме порахований об'єм
}

int main()      //початкова функція; вказую нею, що коли програма запуститься, її виконання почнеться саме з цієї функції
{
    double priceCopybook, pricePencil;      //задаю змінні типу double цінам, так як вони можуть бути нецілими
    int copybookNumber, pencilNumber;       //задаю змінні типу int кількостям, так як вони можуть бути тільки цілими числами

    cout << endl;                                           //використовую endl (end line) для переходу на новий рядок
    cout << "|| The first part of program ||" << endl;      //за допомогою cout роблю виводи тексту у консоль
    cout << "Enter the price of one copybook: ";
    cin >> priceCopybook;                                   //за допомогою cin даю можливість користувачу ввести значення для необхідних змінних
    cout << "Enter the number of copybooks: ";
    cin >> copybookNumber;

    cout << "Enter the price of one pencil: ";
    cin >> pricePencil;                              
    cout << "Enter the number of copybooks: ";
    cin >> pencilNumber;

    double totalPrice = calculateTotalPrice(priceCopybook, pricePencil, copybookNumber, pencilNumber);  //задаю змінну нецілочисельного типу і через функцію присвоюю їй порахованe з її змінними вартість

    cout << "The price of purchase is: " << totalPrice << endl;     //за допомогою cout з бібліотеки 'iostream' вивожу значення у консоль
    cout << endl;

    double radius1, radius2, height;        //задаю змінні типу double для радіусів і висоти, так як вони можуть бути не цілими числами

    cout << "|| The second part of program ||" << endl;
    cout << "Enter the length of first radius: ";
    cin >> radius1;
    cout << "Enter the length of second radius: ";
    cin >> radius2;
    cout << "Enter the length of height: ";
    cin >> height;

    double volume = calculateVolumeOfCylinder(radius1, radius2, height);        //задаю змінну нецілочисельного типу і через функцію присвоюю їй порахований з її змінними об'єм

    cout << "The volume of cylinder is: " << volume;

    return 0;        //повертаю цілочисельне значення 0 операційній системі, як знак успішного завершення програми (0 бо тип повертаючого значення має бути int (цілочисельне))
}
