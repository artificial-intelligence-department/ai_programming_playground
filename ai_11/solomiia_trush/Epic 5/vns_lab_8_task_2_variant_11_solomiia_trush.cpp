#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Video_Tape {
    string title;
    string director;
    double duration;
    double price;
};

void print_file(const vector<Video_Tape>& tapes) {
    for (const auto& tape : tapes) {
        cout << tape.title << " " << tape.director << " " << tape.duration << " " << tape.price << endl;
    }
}

void write_file(const vector<Video_Tape>& tapes, const string& filename) {
    ofstream file(filename, ios::binary | ios::out);
    if (!file.is_open()) {
        cerr << "Error opening file for writing" << endl;
        return;
    }
    for (const auto& tape : tapes) {
        file.write(reinterpret_cast<const char*>(&tape), sizeof(Video_Tape));
    }
    file.close();

}

void Delete_high_price(vector<Video_Tape>& tapes, double high_price) {
    vector<Video_Tape> newTapes;
    for (const auto& tape : tapes) {
        if (!(tape.price > high_price)) {
            newTapes.push_back(tape);
        }
    }
    tapes = move(newTapes);
}

void AddTape (vector<Video_Tape>& tapes) {

    for (int i=0; i<3; i++) {
        Video_Tape newTape;
        cout << endl;
        cout << "Enter title: " << endl;
        cin >> newTape.title;
        cout << "Enter director: " << endl;
        cin >> newTape.director;
        cout << "Enter duration: " << endl;
        cin >> newTape.duration;
        cout << "Enter price: " << endl;
        cin >> newTape.price;

        tapes.push_back(newTape);
    }
}



int main() {
    vector<Video_Tape> tapes = {
        {"Kill Bill", "Quentin Tarantino", 120, 9.5},
        {"Openheimer", "Christopher Nolan", 150, 15.7},
        {"Thor 4", "Taika Waititi", 150, 11.2},
    };

    cout << "Original file : " << endl;
    print_file(tapes);

    double high_price;
    cout << endl;
    cout << "Enter the maximum price : ";
    cin >> high_price;
    Delete_high_price(tapes, high_price);

    cout << endl;
    cout << "File after deletion : " << endl;
    print_file(tapes);

    AddTape(tapes);
    cout << endl;
    cout << "File after adding new tapes : " << endl;
    print_file(tapes);

    write_file(tapes, "videotapes.txt");

    return 0;
}