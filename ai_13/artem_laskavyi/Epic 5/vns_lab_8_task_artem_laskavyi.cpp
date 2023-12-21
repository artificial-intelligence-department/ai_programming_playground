#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Movie{
    string name;
    string director;
    int releaseYear;
    int price;
};

void printMovie(const Movie& movie) {
    cout << "Name of the movie: " << movie.name << endl;
    cout << "Director of the movie: " << movie.director << endl;
    cout << "Year of release: " << movie.releaseYear << endl;
    cout << "Price: " << movie.price << endl;
}

void structToBinary(const vector<Movie>& movies){
    ofstream outf("movies.bin", ofstream::binary | ofstream::trunc);

    if (!outf.is_open()) {
        cout << "Error while opening output file" << endl;
        return;
    }

    for (const Movie& movie : movies) {
        outf.write(reinterpret_cast<const char*>(&movie), sizeof(Movie));
    }

    outf.close();
}

void delByPrice(int setPrice) {
    ifstream inFile("movies.bin", fstream::binary);
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return;
    }

    vector<Movie> movies;
    Movie movie;

    while (inFile.read(reinterpret_cast<char*>(&movie), sizeof(Movie))) {
        if (movie.price <= setPrice) {
            movies.push_back(movie);
        }
    }

    inFile.close();

    structToBinary(movies);
}

void printBinary(int size) {
    ifstream inf("movies.bin", ifstream::binary);

    if (!inf.is_open()) {
        cout << "Error while opening file for printing" << endl;
        return;
    }

    Movie movie;
    for (int i = 0; i < size; ++i) {
        inf.read(reinterpret_cast<char*>(&movie), sizeof(Movie));

        cout << "Movie " << i + 1 << ":\n";
        printMovie(movie);
        cout << endl;
    }

    inf.close();
}

 void addToFront(const Movie& newMovie) {
    vector<Movie> movies;
    ifstream inf("movies.bin", ifstream::binary);

    if (!inf.is_open()) {
        cout << "Error while opening binary file for reading." << endl;
        return;
    }

    Movie movie;
    while (inf.read(reinterpret_cast<char*>(&movie), sizeof(Movie))) {
        movies.push_back(movie);
    }

    inf.close();

    ofstream outf("movies.bin", ofstream::binary | ofstream::trunc);

    if (!outf.is_open()) {
        cout << "Error while opening binary file for writing." << endl;
        return;
    }

    movies.insert(movies.begin(), newMovie);

    for (const Movie& m : movies) {
        outf.write(reinterpret_cast<const char*>(&m), sizeof(Movie));
    }

    outf.close();
}

int main() {

    vector<Movie> movies = {
        {"The Godfather", "Francis Coppola", 1972, 170},
        {"Pulp Fiction", "Quentin Tarantino", 1994, 150},
        {"Forrest Gump", "Robert Zemeckis", 1994, 200},
        {"Fight Club", "David Fincher", 1999, 150},
    };

    structToBinary(movies);

    printBinary(movies.size());
    cout << "------------------\n";
    cout << "Enter highest price that is acceptable in the movie collection\n";
    int nprice;
    cin >> nprice;
    cout << "------------------\n";
    delByPrice(nprice);

    Movie newMovie =  {"Interstellar", "Christopher Nolan", 2014, 165}; 
    addToFront(newMovie);

    cout << "Modified binary file:\n";
    printBinary(movies.size());

    return 0;
}
