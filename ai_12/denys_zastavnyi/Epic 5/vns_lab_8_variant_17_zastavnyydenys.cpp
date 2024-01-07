#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Film {
    string title;
    string director;
    int year;
    double cost;
};

void createBinaryFile(const char *fileName, vector<Film> &films) {
    ofstream file(fileName, ios::binary | ios::trunc);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу для запису." << endl;
        return;
    }

    file.write(reinterpret_cast<char *>(films.data()), sizeof(Film) * films.size());
    file.close();
}

void printBinaryFile(const char *fileName) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cerr << "Помилка при відкритті файлу для читання." << endl;
        return;
    }

    Film film;
    while (file.read(reinterpret_cast<char *>(&film), sizeof(Film))) {
        cout << "Title: " << film.title << ", Director: " << film.director
             << ", Year: " << film.year << ", Cost: " << film.cost << endl;
    }

    file.close();
}

void deleteFilmsByCost(const char *fileName, double maxCost) {
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open()) {
        cerr << "Помилка при відкритті файлу для читання." << endl;
        return;
    }

    ofstream outFile("temp.dat", ios::binary | ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Помилка при відкритті файлу для запису." << endl;
        inFile.close();
        return;
    }

    Film film;
    while (inFile.read(reinterpret_cast<char *>(&film), sizeof(Film))) {
        if (film.cost <= maxCost) {
            outFile.write(reinterpret_cast<char *>(&film), sizeof(Film));
        }
    }

    inFile.close();
    outFile.close();

    remove(fileName);
    rename("temp.dat", fileName);
}

void addFilm(const char *fileName, Film newFilm) {
    ifstream inFile(fileName, ios::binary);
    if (!inFile.is_open()) {
        cerr << "Помилка при відкритті файлу для читання." << endl;
        return;
    }

    ofstream outFile("temp.dat", ios::binary | ios::trunc);
    if (!outFile.is_open()) {
        cerr << "Помилка при відкритті файлу для запису." << endl;
        inFile.close();
        return;
    }

    outFile.write(reinterpret_cast<char *>(&newFilm), sizeof(Film));

    Film film;
    while (inFile.read(reinterpret_cast<char *>(&film), sizeof(Film))) {
        outFile.write(reinterpret_cast<char *>(&film), sizeof(Film));
    }

    inFile.close();
    outFile.close();

    remove(fileName);
    rename("temp.dat", fileName);
}

int main() {
    vector<Film> films = {
        {"Inception", "Christopher Nolan", 2010, 25.99},
        {"The Shawshank Redemption", "Frank Darabont", 1994, 20.50},
        {"Forrest Gump", "Robert Zemeckis", 1994, 15.75}
    };

    const char *fileName = "films.bin";

    createBinaryFile(fileName, films);

    cout << "Contents of the binary file:" << endl;
    printBinaryFile(fileName);

    double maxCostToDelete = 15.0;
    cout << "\nDeleting films with cost more than " << maxCostToDelete << endl;
    deleteFilmsByCost(fileName, maxCostToDelete);

    cout << "\nContents of the binary file after deletion:" << endl;
    printBinaryFile(fileName);

    Film newFilm = {"Titanic", "James Cameron", 1997, 18.25};
    cout << "\nAdding a new film:" << endl;
    addFilm(fileName, newFilm);

    cout << "\nContents of the binary file after addition:" << endl;
    printBinaryFile(fileName);

    return 0;
}
