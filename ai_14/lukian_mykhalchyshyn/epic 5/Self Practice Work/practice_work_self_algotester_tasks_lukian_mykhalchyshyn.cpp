#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Person
{
    string name;
    int age;
    string work;
    int sallary;
    string preferences;
};

int main() 
{
    Person user;

    cout << "Введіть своє ім'я: ";
    getline(cin, user.name);

    cout << "Введіть свій вік: ";
    cin >> user.age;

    cin.ignore();

    cout << "Введіть ким ви працюєте: ";
    getline(cin, user.work);

    cout << "Введіть свою зарплату: ";
    cin >> user.sallary;

    cin.ignore();

    cout << "Введіть свої уподобання: ";
    getline(cin, user.preferences);

    cout << endl << "------ Дані користувача ------";
    cout << endl << "Ім'я: " << user.name << endl;
    cout << "Вік: " << user.age << endl;
    cout << "Робота: " << user.work << endl;
    cout << "Зарплата: " << user.sallary << " $ " << endl;
    cout << "Уподобання: " << user.preferences << endl;

    ofstream File ("user information.txt");

    if (File.is_open())
    {
        File << "Ім'я: " << user.name << endl;
        File << "Вік: " << user.age << endl;
        File << "Робота: " << user.work << endl;
        File << "Зарплата: " << user.sallary << " $ " << endl;
        File << "Уподобання: " << user.preferences << endl;
    
        File.close();

        cout << "Все збережено в File.txt\n";
    }
    else
    {
        cout << "Помилка відкриття File.txt\n";
    }

    return 0;
}
