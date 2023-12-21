#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Film {
    string title;
    string director;
    string country;
    double revenue;
};

void printToFile(const vector<Film>& films, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл для запису\n";
        return;
    }

    for (const Film& film : films) {
        file.write(reinterpret_cast<const char*>(&film), sizeof(Film));
    }

    file.close();
}


void printFromFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Не вдалося відкрити файл для читання\n";
        return;
    }

    Film film;
    while (file.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        cout << "Назва: " << film.title << endl;
        cout << "Режисер: " << film.director << endl;
        cout << "Країна: " << film.country << endl;
        cout << "Прибуток: " << film.revenue << endl;
        cout << "----------------------\n";
    }

    file.close();
}

void addFilm(const Film& newFilm, const string& filename) {
    ofstream file(filename, ios::binary | ios::app);
    if (!file) {
        cerr << "Не вдалося відкрити файл для додавання\n";
        return;
    }

    file.write(reinterpret_cast<const char*>(&newFilm), sizeof(Film));

    file.close();
}


void deleteFilm(const string& titleToDelete, const string& filename) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Не вдалося відкрити файл для читання\n";
        return;
    }

    ofstream outFile("temp.dat", ios::binary);
    if (!outFile) {
        cerr << "Не вдалося відкрити тимчасовий файл для запису\n";
        inFile.close();
        return;
    }

    Film currentFilm;
    bool found = false;

    while (inFile.read(reinterpret_cast<char*>(&currentFilm), sizeof(Film))) {
        if (currentFilm.title != titleToDelete) {
            outFile.write(reinterpret_cast<const char*>(&currentFilm), sizeof(Film));
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove(filename.c_str());
    rename("temp.dat", filename.c_str());

    if (!found) {
        cout << "Фільм з назвою " << titleToDelete << " не знайдено.\n";
    } else {
        cout << "Фільм з назвою " << titleToDelete << " видалено.\n";
    }
}

int main() {
    vector<Film> films = {
        {"Оппенгеймер", "Крістофер Нолан", "США", 1000000.0},
        {"Інтерстелер", "Крістофер Нолан", "США", 2000000.0},
        {"Одного разу в Голівуді", "Квентин Тарантіно", "Ірландія", 3000000.0},
    };

    const string filename = "films.dat";

 
    printToFile(films, filename);

    cout << "Вміст файлу після формування:\n";
    printFromFile(filename);

    deleteFilm("Фільм2", filename);

    Film newFilm = {"Новий фільм", "Новий режисер", "Нова країна", 5000000.0};
    addFilm(newFilm, filename);

    cout << "Вміст файлу після змін:\n";
    printFromFile(filename);

    return 0;
}
