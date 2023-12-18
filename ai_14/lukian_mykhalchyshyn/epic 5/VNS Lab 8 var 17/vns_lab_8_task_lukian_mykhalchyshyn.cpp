#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Film 
{
    char title [150];
    char director [150];
    int year;
    int cost;
};

void print_film (const Film& film) 
{
    cout << "Назва: " << film.title << endl;
    cout << "Режисер: " << film.director << endl;
    cout << "Рік випуску: " << film.year << endl;
    cout << "Вартість: " << film.cost << " грн\n\n";
}

void file_information (const string& filename) 
{
    ifstream file (filename, ios::binary); //відкриття бінарного файлу

    if (!file.is_open()) 
    {
        cerr << "Помилка відкриття файлу для читання\n";
        return;
    }

    Film film; //створення Film для збережених даних які вже зчитані

    while (file.read (reinterpret_cast <char*> (&film), sizeof(Film))) 
    {
        print_film (film);
    }

    file.close();
}

void add_new_movie (const string& filename, const Film& newFilm) 
{
    vector <Film> films; //зберігаєм фільми в векторі

    ifstream inFile (filename, ios::binary);

    if (inFile.is_open()) 
    {
        Film currentFilm; //зчитуєм фільми які вже є в вектор

        while (inFile.read (reinterpret_cast <char*> (&currentFilm), sizeof (Film))) 
        {
            films.push_back (currentFilm);
        }

        inFile.close();
    }

    // Додаєм новий фільм на початок вектору
    films.insert (films.begin(), newFilm);

    // перезапис файлу
    ofstream outFile (filename, ios::binary | ios::trunc);

    if (outFile.is_open()) 
    {
        for (const Film& film : films) // записуєм дані з вектору в файл
        {
            outFile.write (reinterpret_cast <const char*> (&film), sizeof (Film));
        }
        outFile.close();
    }
    else 
    {
        cerr << "Помилка відкриття файлу для запису\n";
    }
}

void deleting_Movie (const string& filename, int max_cost_film) 
{
    ifstream inFile (filename, ios::binary);

    if (!inFile.is_open()) 
    {
        cerr << "Помилка відкриття файлу для читання\n";
        return;
    }

    vector <Film> films; //створення вектора в яку збережем обов'язкові фільми
    Film currentFilm;

    while (inFile.read (reinterpret_cast <char*> (&currentFilm), sizeof (Film))) //додавання  фільмів у вектор якщо не перевищено ціну
    {
        if (currentFilm.cost <= max_cost_film) 
        {
            films.push_back (currentFilm);
        }
    }

    inFile.close();

    ofstream outputFile(filename, ios::binary | ios::trunc); // перезаписуєм файл

    if (!outputFile.is_open()) 
    {
        cerr << "Помилка відкриття файлу для запису\n";
        return;
    }

    for (const Film& film : films) // запис фільму що лишився
    {
        outputFile.write (reinterpret_cast <const char*> (&film), sizeof (Film));
    }

    outputFile.close();
}

int main() {
    const string filename = "films.bin";

    vector<Film> films;

    Film f1 = {"Minecraft", "Joe Han", 2023, 150};
    Film f2 = {"Fort Zankudo", "Hau Pelini", 2022, 175};
    Film f3 = {"Magic Book", "Van Chen", 2021, 250};

    films.push_back(f1); //додавання Film до вектору films
    films.push_back(f2);
    films.push_back(f3);

    // Запис даних в файл
    ofstream file (filename, ios::binary | ios::trunc);

    if (file.is_open()) 
    {
        for (const Film& film : films) 
        {
            file.write (reinterpret_cast <const char*> (&film), sizeof (Film)); //запис даних про кожен фільм
        }
        file.close();
    } 
    else 
    {
        cerr << "Помилка відкриття файлу для запису\n";
        return 1;
    }

    cout << "-----Вміст файлу перед знищенням елементів-----\n";
    file_information (filename);

    int max_cost_film = 240;

    // Знищення елементів
    deleting_Movie (filename, max_cost_film);

    cout << "-----Вміст файлу після знищення елементів-----\n";
    file_information (filename);

    // Новий фільм, який додається на початок файлу
    Film newFilm = {"Kruty", "Olexi Ponomarev", 2019, 199};

    // Додавання нового фільму на початок файлу
    add_new_movie (filename, newFilm);

    cout << "-----Вміст файлу з дованням нового фільму-----\n";
    file_information (filename);

    return 0;
}