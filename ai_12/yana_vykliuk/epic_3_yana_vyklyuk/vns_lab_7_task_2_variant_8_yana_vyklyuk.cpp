#include <iostream>
#include <string>

using namespace std;

struct japanese_calendar
{
    string name;
    string colour;
};

japanese_calendar The_name(int year)
{
    string old_japanese_names[12] = {"Щур", "Бик","Тигр", "Кролик", "Дракон", "Змія", "Кінь", "Коза", "Мавпа", "Півень", "Собака", "Свиня"};
    string old_japanese_colours[5] = {"Білий/а", "Блакитний/а", "Зелений/а", "Червоний/а", "Жовтий/а"};

    japanese_calendar input_year;

    int start_year = 1900;
    if (year < start_year)
    {
        cout << "Невідома назва заданого року за старояпонським календарем." << endl;
        input_year.name = "Невідомий/а";
        input_year.colour = "Невідомий/а";
        return input_year;
    }

    int value = (year - start_year) % 12;

    int colour = (year - start_year) % 5;

    cout << "Навза Вашого року за старояпонським календарем: " << old_japanese_colours[colour] << " " << old_japanese_names[value] << endl;

    input_year.colour = old_japanese_colours[colour];
    input_year.name = old_japanese_names[value];

    return input_year;
}

string The_name(string month)
{
    string signs[12] = {"Овен", "Телець", "Близнюки", "Рак", "Лев", "Діва", "Терези", "Скорпіон", "Стрілець", "Козеріг", "Водолій", "Риби"};
    string months[12] = {"Квітень", "Травень", "Червень", "Липень", "Серпень", "Вересень", "Жовтень", "Листопад", "Грудень", "Січень", "Лютий", "Березень"};

    int index = -1;

    for (int i=0; i < 12; i++)
    {
        if(month == months[i])
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        cout << "Введіть дійсний місяць!" << endl;
        return "Недійсно";
    }

    cout << "Ваш знак зодіаку: " << signs[index] << endl;

    return signs[index];
}

int main()
{
    int year;
    string month;
    
    cout << "Введіть рік за григоріанським календарем: " << endl;
    cin >> year;

    cout << "Введіть місяць з великої букви " << endl;
    cin >> month;
    
    The_name(year);
    The_name(month);
    
    return 0;
}
