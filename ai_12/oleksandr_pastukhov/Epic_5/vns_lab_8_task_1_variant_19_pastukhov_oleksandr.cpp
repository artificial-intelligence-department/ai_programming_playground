#include <iostream>
#include <fstream>
#include <string>
#include <cstring>


struct Movie {
    char title[100];
    char director[100];
    char country[30];
    double revenue;
};

void writeMoviesToFile(char* filename, int n);
void readMoviesFromFile(char* filename, int n);
void deleteLastTwoMovies(char* filename);
void addMovieAfterTitle(char* filename, char* targetTitle, Movie& newMovie);

int main() {
    using namespace std;

    int n;
    cout << "How many movies do you want to enter? ";
    cin >> n;
    cin.ignore();

    writeMoviesToFile("movies.txt", n);
    readMoviesFromFile("movies.txt", n);

    deleteLastTwoMovies("movies.txt");
    readMoviesFromFile("movies.txt", n);

    Movie newMovie;
    cout << "Enter details for the movie to add after: " << endl;
    cout << "Title: ";
    cin.getline(newMovie.title, sizeof(newMovie.title));

    cout << "Director: ";
    cin.getline(newMovie.director, sizeof(newMovie.director));

    cout << "Country: ";
    cin.getline(newMovie.country, sizeof(newMovie.country));

    cout << "Revenue: $";
    cin >> newMovie.revenue;

    cin.ignore();

    addMovieAfterTitle("movies.txt", "Target Movie Title", newMovie);
    readMoviesFromFile("movies.txt", n);

    return 0;
}

void writeMoviesToFile(char* filename, int n) {
    Movie* movies = new Movie[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter title: ";
        cin.getline(movies[i].title, sizeof(movies[i].title));

        cout << "Enter director: ";
        cin.getline(movies[i].director, sizeof(movies[i].director));

        cout << "Enter country: ";
        cin.getline(movies[i].country, sizeof(movies[i].country));

        cout << "Enter revenue: $";
        cin >> movies[i].revenue;

        cin.ignore(); 
    }

    ofstream outFile(filename, ios::out | ios::binary);

    if (!outFile.is_open()) {
        cerr << "Failure to open the file for writing." << endl;
        delete[] movies;
        return;
    }

    outFile.write(reinterpret_cast<char*>(movies), n * sizeof(Movie));

    outFile.close();
    delete[] movies;
}

void readMoviesFromFile(char* filename, int n) {
    Movie* movies = new Movie[n];

    ifstream inFile(filename, ios::in | ios::binary);

    if (!inFile.is_open()) {
        cerr << "Failure to open the file for reading." << endl;
        delete[] movies;
        return;
    }

    inFile.read(reinterpret_cast<char*>(movies), n * sizeof(Movie));

    for (int i = 0; i < n; i++) {
        cout << "Title: " << movies[i].title << endl;
        cout << "Director: " << movies[i].director << endl;
        cout << "Country: " << movies[i].country << endl;
        cout << "Revenue: $" << movies[i].revenue << endl;
        cout << "------------------------" << endl;
    }

    inFile.close();
    delete[] movies;
}

void deleteLastTwoMovies(char* filename) {
    ifstream inFile(filename, ios::in | ios::binary);
    ofstream tempFile("temp.bin", ios::out | ios::binary);

    if (!inFile.is_open() || !tempFile.is_open()) {
        cerr << "Failure to open the file for reading/writing." << endl;
        return;
    }

    int totalMovies = 0;
    Movie currentMovie;

    while (inFile.read(reinterpret_cast<char*>(&currentMovie), sizeof(Movie))) {
        totalMovies++;
    }

    inFile.clear();
    inFile.seekg(0, ios::beg); 

    for (int i = 0; i < totalMovies - 2; i++) {
        inFile.read(reinterpret_cast<char*>(&currentMovie), sizeof(Movie));
        tempFile.write(reinterpret_cast<char*>(&currentMovie), sizeof(Movie));
    }

    inFile.close();
    tempFile.close();

    remove(filename);
    rename("temp.bin", filename);
}

void addMovieAfterTitle(char* filename, char* targetTitle, Movie& newMovie) {
    ifstream inFile(filename, ios::in | ios::binary);
    ofstream tempFile("temp.bin", ios::out | ios::binary);

    if (!inFile.is_open() || !tempFile.is_open()) {
        cerr << "Failure to open the file for reading/writing." << endl;
        return;
    }

    Movie currentMovie;
    bool targetFound = false;

    while (inFile.read(reinterpret_cast<char*>(&currentMovie), sizeof(Movie))) {
        tempFile.write(reinterpret_cast<char*>(&currentMovie), sizeof(Movie));

        if (strcmp(currentMovie.title, targetTitle) == 0) {
            tempFile.write(reinterpret_cast<char*>(&newMovie), sizeof(Movie));
            targetFound = true;
        }
    }

    inFile.close();
    tempFile.close();

    if (!targetFound) {
        cerr << "Target movie not found." << endl;
        remove("temp.bin");
        return;
    }

    remove(filename);
    rename("temp.bin", filename);
}
