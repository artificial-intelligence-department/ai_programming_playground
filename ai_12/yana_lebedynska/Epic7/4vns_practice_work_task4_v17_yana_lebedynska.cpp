#include <iostream>      //підключаю бібліотеку <iostream>, яка дозволяє підключати потік виведення(cout) і введеня(cin) у програму
#include <random>        //бібліотека для генерації випадкових чисел (в ній об'єкти random_device, default_random_engine, )
using namespace std;     //підключаю директиву, яка дозволяє використовувати простір імен std(standard) без явного зазначення кожного елемента з цього простору імен

int main()
{
    const int numberOfSequences = 3;                  //задаю змінні типу int для кількості і довжини послідовностей (тип int, так як змінні можуть бути тільки цілочисельні; констатні, бо їх змінювати вже не можна)
    const int lengthOfEachSequence = 10;

    random_device randomDevice;                       //оголошую об'єкт ramdomDevice типу random_device, який буде джерелом випадкових чисел 
    default_random_engine a(randomDevice());        //оголошую об'єкт gen генератора випадкових чисел типу default_random_engine (за замовчуванням), який ініціалізується значеннями, отриманими від об'єкта randomDevice
    uniform_int_distribution<> distribution(1, 10);   //створюю конструкцію для генерації рандомних цілочисельних значень від 1 до 10 включно

    for(int i = 0; i < numberOfSequences; i++)         //за допомогою циклу for роблю 3 різні послідовності (рахунок починається від нуля, бо перша послідовність в с++ буде нульвою по рахунку)
    {
        cout << "The sequence " << (i+1) << " -> ";    //за допомогою cout з <iostream> виожу для кожної послідовності текстове повідомлення
        
        double sum = 0.0;                              //задаю нецілочисельну змінну суми (початкове значення 0.0, бо потім до цієї суми додаватимуться інші значення)
        for(int l = 0; l < lengthOfEachSequence; l++)   
        {
            int randomNumber = distribution(a);       //задаю змінну randomNumber, в яку записуватимуться рандомні числа
            cout << randomNumber << " ";                //через пробіл під час кожної ітерації вивожу у консоль кожне число
            sum += randomNumber;                        //під час кожної ітерації додаю до суми значення кожного числа
        }

        double avarage = sum / lengthOfEachSequence;             //задаю нецілочисельну змінну середнього арифметичного і шукаю його ділячи суму чисел послідовності на їх кількість
        cout << endl << "The avarage is: " << avarage << endl;   //вивожу у консоль під час кожної ітерації середнє ариф. поточної послідовності
        cout << endl;                                            //використовую endl (end line) для переходу на новий рядок
    }

    return 0;       //повертаю цілочисельне значення 0 операційній системі, як знак успішного завершення програми (0 бо тип повертаючого значення має бути int (цілочисельне))
}