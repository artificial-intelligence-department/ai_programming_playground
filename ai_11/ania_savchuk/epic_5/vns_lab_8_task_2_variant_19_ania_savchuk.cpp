#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Film{
    string name;
    string director;
    string country;
    double profit;
};

void create_file(string filename, vector<Film> &films) {
    ofstream outf(filename, ios::binary);
    if (!outf.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    for (int i = 0; i < films.size(); i++) {
        outf.write(reinterpret_cast<char*>(&films[i]), sizeof(Film));
    }
    outf.close();
}

void print_file(vector<Film> &films) {
    ifstream prf("films.bin", ios::binary);
    if (!prf.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    for (int i = 0; i < films.size(); i++) {
        cout << "Film " << i+1 << ":" << endl;
        cout << "Name: " << films[i].name << endl;
        cout << "Director: " << films[i].director << endl;
        cout << "Country: " << films[i].country << endl;
        cout << "Profit: " << films[i].profit << endl;
        cout << endl;
    }

    prf.close();
}

void delete_from_file(vector<Film> &films, int  n){
    while (n > 0 && !films.empty()) {
        films.pop_back();
        n--;
    }
}


void add_to_file(vector<Film> &films, string film_name, string director, string country, double profit) {
    films.push_back({film_name, director, country, profit});
}

int main() {
    string filename = "films.bin";
    vector<Film> films = {
        {"The Shawshank Redemption", "Frank Darabont", "USA", 58},
        {"The Godfather", "Francis Ford Coppola", "USA", 245},
        {"The Dark Knight", "Christopher Nolan", "USA", 1003},
        {"12 Angry Men", "Sidney Lumet", "USA", 2},
        {"Schindler's List", "Steven Spielberg", "USA", 321},
    };

    create_file(filename,films);
    cout << "Created file: " << endl; 
    print_file(films);

    delete_from_file(films, 2);
    cout << "File after deletion: " << endl;
    print_file(films);

    add_to_file(films, "The Lion King", "Roger Allers", "USA", 968);
    cout << "File with new film: " << endl;
    print_file(films);
}