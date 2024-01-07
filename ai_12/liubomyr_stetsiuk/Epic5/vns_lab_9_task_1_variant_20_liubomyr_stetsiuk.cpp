#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Country
{
    string name;
    string language;
    string currency;
    double currencyRate;
};

void printCountry(const Country &country)
{
    cout << "Назва: " << country.name << endl;
    cout << "Державна мова: " << country.language << endl;
    cout << "Грошова одиниця: " << country.currency << endl;
    cout << "Курс валюти відносно $: " << country.currencyRate << endl;
    cout << "-----------------------------" << endl;
}

bool deleteCountry(const string &filename, const string &nameToDelete)
{
    ifstream fileIn(filename, ios::binary);
    if (!fileIn.is_open())
    {
        cout << "Помилка відкриття файлу для зчитування." << endl;
        return false;
    }

    ofstream fileOut("temp.dat", ios::binary);
    if (!fileOut.is_open())
    {
        cout << "Помилка відкриття тимчасового файлу." << endl;
        return false;
    }

    Country tempCountry;
    bool found = false;
    while (fileIn.read(reinterpret_cast<char *>(&tempCountry), sizeof(Country)))
    {
        if (tempCountry.name != nameToDelete)
        {
            fileOut.write(reinterpret_cast<const char *>(&tempCountry), sizeof(Country));
        }
        else
        {
            found = true;
        }
    }

    fileIn.close();
    fileOut.close();

    if (remove(filename.c_str()) != 0)
    {
        cout << "Помилка видалення оригінального файлу." << endl;
        return false;
    }

    if (rename("temp.dat", filename.c_str()) != 0)
    {
        cout << "Помилка перейменування тимчасового файлу." << endl;
        return false;
    }

    if (!found)
    {
        cout << "Елемент з назвою '" << nameToDelete << "' не знайдено." << endl;
        return false;
    }

    cout << "Елемент з назвою '" << nameToDelete << "' був успішно видалений." << endl;
    return true;
}

void addCountries(const string &filename)
{
    ofstream fileOut(filename, ios::binary | ios::app);
    if (!fileOut.is_open())
    {
        cout << "Помилка відкриття файлу для запису." << endl;
        return;
    }

    Country newCountry1 = {"Country1", "Language1", "Currency1", 1.5};
    Country newCountry2 = {"Country2", "Language2", "Currency2", 2.5};

    fileOut.write(reinterpret_cast<const char *>(&newCountry1), sizeof(Country));
    fileOut.write(reinterpret_cast<const char *>(&newCountry2), sizeof(Country));

    fileOut.close();

    cout << "Додано 2 нові елементи в кінець файлу." << endl;
}

int main()
{
    const string filename = "countries.dat";
    vector<Country> countries = {
        {"Ukraine", "Ukrainian", "Hryvnia", 27.21},
        {"USA", "English", "Dollar", 1.0},
        {"Germany", "German", "Euro", 0.89}};

    ofstream fileOut(filename, ios::binary);
    if (fileOut.is_open())
    {
        for (const auto &country : countries)
        {
            fileOut.write(reinterpret_cast<const char *>(&country), sizeof(Country));
        }
        fileOut.close();
    }
    else
    {
        cout << "Помилка відкриття файлу для запису початкових даних." << endl;
        return 1;
    }

    ifstream fileIn(filename, ios::binary);
    if (fileIn.is_open())
    {
        Country tempCountry;
        while (fileIn.read(reinterpret_cast<char *>(&tempCountry), sizeof(Country)))
        {
            printCountry(tempCountry);
        }
        fileIn.close();
    }
    else
    {
        cout << "Помилка відкриття файлу для зчитування початкових даних." << endl;
        return 1;
    }

    deleteCountry(filename, "Germany");

    addCountries(filename);

    return 0;
}
