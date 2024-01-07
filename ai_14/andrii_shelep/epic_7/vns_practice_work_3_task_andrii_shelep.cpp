#include <iostream>
#include <string> //для роботи з рядками
#include <iomanip> //підключаю для використання setprecision
#include <fstream> //для роботи з файлами

using namespace std;

struct Travel //структура Travel
{
    int distance;
    float consumption;
    float price;
};

void WriteToFile(const char* name, double total_price)
{
    ofstream ofile(name); //відкриваю файл для запису
    if(ofile.is_open()) //перевіряю чи файл відкрито
    {
        ofile << "Вартість поїздки: " << fixed << setprecision(2) << total_price << " грн."; //записую у файл вартість поїздки
        cout << "Запис у файл пройшов успішно!" << endl;
    } else {
        cout << "error opening file" << endl;
    }
    ofile.close(); // закриваю файл
}

void ReadFromFile(const char* name)
{
    ifstream ifile(name); //відкриваю файл для зчитування
    if(ifile.is_open()) //перевіряю чи файл відкрито
    {
        string line;
        while(getline(ifile, line)) //зчитую файл поки не дійду до кінця
        {
            cout << line << endl; //виводжу вмістиме
        }
    } else {
        cout << "error opening file" << endl;
        return;
    }
    ifile.close();
}

int main(){
    Travel travel;

    cout << "  Обчислення вартості поїздки на дачу і назад" << endl;
    cout << "Введіть початкові дані:" << endl;
    cout << "Відстань до дачі (км): ";
    cin >> travel.distance; //вводимо відстань до дачі
    cout << "Витрата бензину (літрів на 100 км пробігу): ";
    cin >> travel.consumption; //вводимо розхід палива
    cout << "Ціна літра бензину (грн): ";
    cin >> travel.price; //вводимо ціну 1 літрa палива

    int total_distance = travel.distance*2; //шукаємо загальну відстань (відстань до дачі і назад)
    float petrol = total_distance*travel.consumption/100; //обчислюємо скільки літрів палива витратиться на поїздку
    float total_price = petrol*travel.price; //обчислюємо ціну на цей об'єм палива

    cout << "Поїздка на дачу і назад обійдеться в " << fixed << setprecision(2) << total_price << " грн." << endl; //виводимо результат; використано setprcision для виведення 2-ох знаків після коми

    WriteToFile("travel.txt", total_price);
    ReadFromFile("travel.txt");

    cout << endl << "  Обчислення сили струму" << endl; //завдання з обчисленням сили струму
    float i, u, r;
    cout << "Введіть значення опору у Ом: ";
    cin >> r; //вводимо значення опору
    while(r<=0) //створив цикл; якщо користувач введе від'ємний або нульовий опір, то просимо його ввести ще раз поки він не введе додатнє значення
    {
        cout << "Опір не може бути від'ємним чи дорівнювати нулю. Введіть ще раз значення опору: ";
        cin >> r;
    }
    cout << "Введіть значення напруги у В: ";
    cin >> u; //вводимо значення напруги
    i = u/r; //знаходимо силу струму за законом Ома
    cout << "Сила струму дорівнює " << setprecision(3) << i << " A" << endl; //виводимо силу струму у амперах, використовуючи setprecision для виведення трьох знаків після коми
    return 0;
}