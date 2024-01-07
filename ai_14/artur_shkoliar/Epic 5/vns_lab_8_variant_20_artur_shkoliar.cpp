#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Country 
{
    char name[50];
    char language[30];
    char currency[30];
    double exchange;
};

void print_country(const Country& country) 
{
    cout << "Назва: " << country.name << endl;
    cout << "Мова: " << country.language << endl;
    cout << "Валюта: " << country.currency << endl;
    cout << "Обмін відносно долара: " << country.exchange << endl;
}

void read_and_print_countries(const char* filename) 
{
    ifstream file(filename, ios::binary);

    if (!file.is_open()) 
    {
        cerr << "Помилка відкривання " << filename << endl;
        return;
    }

    Country country;
    while (file.read(reinterpret_cast<char*>(&country), sizeof(Country))) 
    {
        country.name[sizeof(country.name) - 1] = '\0';
        country.language[sizeof(country.language) - 1] = '\0';
        country.currency[sizeof(country.currency) - 1] = '\0';
        print_country(country);
    }

    file.close();
}

void destroy_country(const char* filename, const char* countryName) 
{
    ifstream inFile(filename, ios::binary);
    ofstream outFile("temp.bin", ios::binary | ios::trunc);

    if (!inFile.is_open() || !outFile.is_open()) 
    {
        cerr << "Помилка читання або відкривання файлу" << endl;
        return;
    }

    Country country;
    while (inFile.read(reinterpret_cast<char*>(&country), sizeof(Country))) 
    {
        country.name[sizeof(country.name) - 1] = '\0';
        country.language[sizeof(country.language) - 1] = '\0';
        country.currency[sizeof(country.currency) - 1] = '\0';

        if (strcmp(country.name, countryName) != 0)
        {
            if (!outFile.write(reinterpret_cast<const char*>(&country), sizeof(Country))) 
            {
                cerr << "Помилка написання " << endl;
                inFile.close();
                outFile.close();
                return;
            }
        }
    }

    inFile.close();
    outFile.close();

    remove(filename);
    rename("temp.bin", filename);
}


void add_countries(const char* filename, const Country& country1, const Country& country2) 
{
    ofstream outFile(filename, ios::binary | ios::app);

    if (!outFile.is_open()) 
    {
        cerr << "Помилка відкривання " << filename << endl;
        return;
    }

    if (!outFile.write(reinterpret_cast<const char*>(&country1), sizeof(Country))) 
    {
        cerr << "Помилка написання у файл " << filename << endl;
        outFile.close();
        return;
    }

    if (!outFile.write(reinterpret_cast<const char*>(&country2), sizeof(Country))) 
    {
        cerr << "Помилка написання у файл: " << filename << endl;
        outFile.close();
        return;
    }

    outFile.close();
}


int main() 
{
    const char* filename = "countries.bin";

    const char* countryToDelete = "Ukraine";
    destroy_country(filename, countryToDelete);

    Country newCountry1 = {"Японія", "японська", "йен", 146.24};
    Country newCountry2 = {"Австралія", "англійська", "австрдолар", 1.52};

    add_countries(filename, newCountry1, newCountry2);

    read_and_print_countries(filename);

    return 0;
}
