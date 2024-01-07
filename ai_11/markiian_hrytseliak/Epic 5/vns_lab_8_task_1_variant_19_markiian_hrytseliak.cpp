#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Film 
{
    string title;
    string director;
    string country;
    double revenue;
};

void printFilm(const Film& film) {
    cout << "Title: " << film.title << endl;
    cout << "Director: " << film.director << endl;
    cout << "Country: " << film.country << endl;
    cout << "Revenue: " << film.revenue <<"billion $"<< endl;
    cout << "-----------------------------" << endl;
}

void writeFilmToFile(const Film& film, const string& filename) {
    ofstream file(filename, ios::binary | ios::app);

    if (!file.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&film), sizeof(Film));
    file.close();
}

void readAndPrintFileContents(const string& filename) {
    ifstream file(filename, ios::binary);

    if (!file.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    Film film;
    while (file.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        printFilm(film);
    }

    file.close();
}

void removeLastTwoFilms(const string& filename) {
    ifstream fileIn(filename, ios::binary);

    if (!fileIn.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    vector<Film> films;
    Film film;
    while (fileIn.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        films.push_back(film);
    }

    fileIn.close();

    // Check if there are two films to remove
    if (films.size() >= 2) {
        // Remove the last two films
        films.pop_back();
        films.pop_back();
    } else {
        cerr << "Not enough films to remove!" << endl;
        return;
    }

    // Write the remaining films back to the file
    ofstream fileOut(filename, ios::binary | ios::trunc);

    if (!fileOut.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const Film& f : films) {
        fileOut.write(reinterpret_cast<const char*>(&f), sizeof(Film));
    }

    fileOut.close();
}


void addFilmAfterTitle(const string& filename, const string& targetTitle, const Film& newFilm) {
    ifstream fileIn(filename, ios::binary);

    if (!fileIn.is_open()) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    // Read all films into a vector
    vector<Film> films;
    Film film;
    while (fileIn.read(reinterpret_cast<char*>(&film), sizeof(Film))) {
        films.push_back(film);
    }

    fileIn.close();

    // Find the target film by title
    auto it = find_if(films.begin(), films.end(), [&targetTitle](const Film& f) {
        return f.title == targetTitle;
    });

    if (it != films.end()) {
        // Insert the new film after the target film
        films.insert(it + 1, newFilm);
    } else {
        cerr << "Film with the specified title not found!" << endl;
        return;
    }

    // Write the updated films back to the file
    ofstream fileOut(filename, ios::binary | ios::trunc);

    if (!fileOut.is_open()) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    for (const Film& f : films) {
        fileOut.write(reinterpret_cast<const char*>(&f), sizeof(Film));
    }

    fileOut.close();
}

int main() {
    const string filename = "C:/Users/Gil/OneDrive/Documents/GitHub/desktop-tutorial/Programming/Code/Epic 5/films.bin";

    // Form the file with initial data
    Film films[] = {
        {"Oppenheimer", "Cristopher Nolan", "USA", 0.9},
        {"Titanic", "James Cameron", "USA", 0.5},
        {"Inglorious Basterds", "Quentin Tarantino", "France", 0.5},
        {"Killers of the flower moon", "Martin Scorseze", "Usa", 0.4},
        {"Napoleon", "Ridley Scott", "France", 0.4}
    };

    for (const Film& film : films) {
        writeFilmToFile(film, filename);
    }

    cout << "Initial file contents:" << endl;
    cout << "-----------------------------" << endl;
    readAndPrintFileContents(filename);

    return 0;
}