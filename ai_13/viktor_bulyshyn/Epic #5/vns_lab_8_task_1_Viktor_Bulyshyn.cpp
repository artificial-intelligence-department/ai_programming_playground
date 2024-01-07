#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

// Створення структури Стадіон
struct Stadium {
    string name;
    string address;
    int capacity;
    string sports;

    // Структура за замовчанням
    Stadium() : name(""), address(""), capacity(0), sports("") {}

    // структура
    Stadium(const string& n, const string& a, int c, const string& s)
        : name(n), address(a), capacity(c), sports(s) {}

    // вивід інформації про Стадіон
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Sports: " << sports << endl << endl;
    }
};

// функція для зміни структури
void displayFile(const string& filename);
void deleteStadium(const string& filename, const string& nameToDelete);
void addStadium(const string& filename, int position, const Stadium& stadium1, const Stadium& stadium2);

int main() {
    const string filename = "stadiums.dat";

// заповнення файлу данними 
    ofstream initialFile(filename, ios::binary);

    Stadium stadium1("Stadium1", "Address1", 10000, "Football");
    Stadium stadium2("Stadium2", "Address2", 15000, "Hockey");
    Stadium stadium3("Stadium3", "Address3", 20000, "Basketball");

    initialFile.write(reinterpret_cast<const char*>(&stadium1), sizeof(Stadium));
    initialFile.write(reinterpret_cast<const char*>(&stadium2), sizeof(Stadium));
    initialFile.write(reinterpret_cast<const char*>(&stadium3), sizeof(Stadium));

    initialFile.close();

    cout << "Initial state of the file:" << endl;
    displayFile(filename);

    cout << "Initial state of the file:" << endl;
    displayFile(filename);

    // видалення елементу з заданою назвою (з умови)
    string stadiumToDelete = "Stadium2";
    deleteStadium(filename, stadiumToDelete);
    cout << "\nAfter deleting the stadium \"" << stadiumToDelete << "\":" << endl;
    displayFile(filename);

    // добавлення двох елементів після зазначеного номеру
    int positionToAdd = 1;  // add after the first element
    Stadium newStadium1("New Stadium1", "New Address1", 12000, "Tennis");
    Stadium newStadium2("New Stadium2", "New Address2", 18000, "Volleyball");
    addStadium(filename, positionToAdd, newStadium1, newStadium2);

    cout << "\nAfter adding new stadiums:" << endl;
    displayFile(filename);

    return 0;
}

// функція для видалення елемента із заданою назвою
void deleteStadium(const string& filename, const string& nameToDelete) {
    ifstream fileIn(filename, ios::binary);
    ofstream fileOut("temp.dat", ios::binary);

    if (!fileIn || !fileOut) {
        cerr << "Error opening the file." << endl;
        exit(1);
    }

    Stadium tempStadium;
    while (fileIn.read(reinterpret_cast<char*>(&tempStadium), sizeof(Stadium))) {
        if (tempStadium.name != nameToDelete) {
            fileOut.write(reinterpret_cast<const char*>(&tempStadium), sizeof(Stadium));
        }
    }

    fileIn.close();
    fileOut.close();

    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

void addStadium(const string& filename, int position, const Stadium& stadium1, const Stadium& stadium2) {
    ifstream fileIn(filename, ios::binary);
    ofstream fileOut("temp.dat", ios::binary);

    if (!fileIn || !fileOut) {
        cerr << "Error opening the file." << endl;
        exit(1);
    }

    Stadium tempStadium;
    int currentPosition = 1;

    while (fileIn.read(reinterpret_cast<char*>(&tempStadium), sizeof(Stadium))) {
        fileOut.write(reinterpret_cast<const char*>(&tempStadium), sizeof(Stadium));

        if (currentPosition == position) {
            fileOut.write(reinterpret_cast<const char*>(&stadium1), sizeof(Stadium));
            fileOut.write(reinterpret_cast<const char*>(&stadium2), sizeof(Stadium));
        }

        currentPosition++;
    }

    fileIn.close();
    fileOut.close();

    remove(filename.c_str());
    rename("temp.dat", filename.c_str());
}

void displayFile(const string& filename) {
    ifstream fileIn(filename, ios::binary);

    if (!fileIn) {
        cerr << "Error opening the file." << endl;
        return;
    }

    Stadium tempStadium;
    while (fileIn.read(reinterpret_cast<char*>(&tempStadium), sizeof(Stadium))) {
        tempStadium.display();
    }

    fileIn.close();
}
