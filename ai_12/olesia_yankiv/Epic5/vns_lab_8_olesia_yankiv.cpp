#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Movie {
    string title;
    string director;
    string country;
    double cash;
};

void writeMoviesToFile(const string& filename, const vector<Movie>& movies);
void printMovie(const Movie& movie);
void deleteLastTwoElements(vector<Movie>& movies);
void addElementAfterTitle(vector<Movie>& movies, const string& targetTitle, const Movie& newMovie);

int main() {
    const string filename = "movies.bin";
    vector<Movie> movies = {
        {"The Notebook", "Nick Cassavetes", "USA", 156600000},
        {"Home Alone", "Cris Columbus", "USA", 476000000},
        {"Mulan", "Niki Caro", "China", 69973540},
    };

    // Write initial movies to the file
    writeMoviesToFile(filename, movies);

    cout << "Content of the file after operations:" << endl;
    for (const Movie& movie : movies) {
        printMovie(movie);
    }

    // Delete last two elements
    deleteLastTwoElements(movies);

    // Write modified movies to the file
    writeMoviesToFile(filename, movies);

    // Print content after deletion
    cout << "Content of the file after deletion:" << endl;
    for (const Movie& movie : movies) {
        printMovie(movie);
    }

    // Add a new element after an existing title
    Movie newMovie = {"Barbie", "Greta Gerwig", "USA", 50000000};
    addElementAfterTitle(movies, "Home Alone", newMovie);

    // Write modified movies to the file
    writeMoviesToFile(filename, movies);

    // Print content after addition
    cout << "Content of the file after addition:" << endl;
    for (const Movie& movie : movies) {
        printMovie(movie);
    }

    return 0;
}

void writeMoviesToFile(const string& filename, const vector<Movie>& movies) {
    ofstream file(filename, ios::binary | ios::out);

    if (!file.is_open()) {
        cerr << "Error opening the file." << endl;
        exit(EXIT_FAILURE);
    }

    file.write(reinterpret_cast<const char*>(movies.data()), sizeof(Movie) * movies.size());

    file.close();
}

void printMovie(const Movie& movie) {
    cout << "Title: " << movie.title << ", Director: " << movie.director
         << ", Country: " << movie.country << ", Revenue: " << movie.cash << endl;
}

void deleteLastTwoElements(vector<Movie>& movies) {
    if (movies.size() >= 2) {
        movies.resize(movies.size() - 2); // Resize the vector to remove the last two elements
    }
}

void addElementAfterTitle(vector<Movie>& movies, const string& targetTitle, const Movie& newMovie) {
    auto it = find_if(movies.begin(), movies.end(), [&targetTitle](const Movie& movie) {
        return movie.title == targetTitle;
    });

    if (it != movies.end()) {
        movies.insert(it + 1, newMovie);
    } else {
        cerr << "Element with title \"" << targetTitle << "\" is not found." << endl;
    }
}
