#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Videotape {
    string title;
    string director;
    int duration;
    int price;
};

void printVideotape(const Videotape& tape) {
    cout << "Title: " << tape.title << endl;
    cout << "Director: " << tape.director << endl;
    cout << "Duration: " << tape.duration << endl;
    cout << "Price: " << tape.price << endl;
}

void writeToFile(const vector<Videotape>& tapes) {
    ofstream outFile("videotapes.bin", ofstream::binary | ofstream::trunc);

    if (!outFile.is_open()) {
        cout << "Error opening output file" << endl;
        return;
    }

    for (const Videotape& tape : tapes) {
        outFile.write(reinterpret_cast<const char*>(&tape), sizeof(Videotape));
    }

    outFile.close();
}

void deleteByPrice(int setPrice) {
    ifstream inFile("videotapes.bin", ifstream::binary);

    if (!inFile.is_open()) {
        cout << "Error opening input file." << endl;
        return;
    }

    vector<Videotape> tapes;
    Videotape tape;

    while (inFile.read(reinterpret_cast<char*>(&tape), sizeof(Videotape))) {
        if (tape.price <= setPrice) {
            tapes.push_back(tape);
        }
    }

    inFile.close();

    ofstream outFile("videotapes.bin", ofstream::binary | ofstream::trunc);

    if (!outFile.is_open()) {
        cout << "Error opening output file." << endl;
        return;
    }

    for (const Videotape& t : tapes) {
        outFile.write(reinterpret_cast<const char*>(&t), sizeof(Videotape));
    }

    outFile.close();
}

void printBinary() {
    ifstream inFile("videotapes.bin", ifstream::binary);

    if (!inFile.is_open()) {
        cout << "Error opening file for printing" << endl;
        return;
    }

    Videotape tape;
    int i = 0;

    while (inFile.read(reinterpret_cast<char*>(&tape), sizeof(Videotape))) {
        cout << "Videotape " << ++i << ":\n";
        printVideotape(tape);
        cout << endl;
    }

    inFile.close();
}

void addToEnd(const Videotape& newTape) {
    ofstream outFile("videotapes.bin", ofstream::binary | ofstream::app);

    if (!outFile.is_open()) {
        cout << "Error opening output file." << endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&newTape), sizeof(Videotape));

    outFile.close();
}

int main() {

    vector<Videotape> tapes = {
        {"Home Alone", "John Hughes", 100, 170},
        {"The Devil Wears Prada", "David Frankel", 90, 150},
        {"Jumanji", "Joe Johnston", 110, 200},
        {"Spiderman", "Sam Raimi", 80, 180},
    };

    writeToFile(tapes);

    cout << "Initial binary file content:\n";
    printBinary();

    cout << "------------------\n";
    cout << "Enter the highest acceptable price for videotapes in the collection: ";
    int nPrice;
    cin >> nPrice;
    cout << "------------------\n";
    deleteByPrice(nPrice);

    cout << "Videotapes after deleting by price:\n";
    printBinary();

    cout << "------------------\n";
    cout << "Adding 3 new videotapes to the end of the file...\n";
    for (int i = 0; i < 3; ++i) {
        Videotape newTape;
        cout << "Enter details for new videotape " << i + 1 << ":\n";
        cout << "Title: ";
        cin.ignore();
        getline(cin, newTape.title);
        cout << "Director: ";
        getline(cin, newTape.director);
        cout << "Duration: ";
        cin >> newTape.duration;
        cout << "Price: ";
        cin >> newTape.price;

        addToEnd(newTape);
    }

    cout << "Updated binary file content:\n";
    printBinary();

    return 0;
}
