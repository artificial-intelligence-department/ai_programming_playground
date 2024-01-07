#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Country {
    string name;
    string official_language;
    string currency;
    double exchange_rate_to_usd;
};

int write(Country warr[]) {
    ofstream wf("countries.bin", ios::out | ios::binary); // для запису в бін
    if (!wf) {
        cout << "Cannot open the file.";
        return 1;
    }
    for (int i = 0; i < 4; i++)
        wf.write((char*)&warr[i], sizeof(Country)); //байтове представлення структури у файл
    wf.close();
    if (!wf.good()) { 
        cout << "Error occurred at writing time!" << endl;
        return 1;
    }
    return 0;
}

int read(Country rarr[]) {
    ifstream rf("countries.bin", ios::out | ios::binary);
    if (!rf) {
        cout << "Cannot open the file.";
        return 1;
    }
    for (int i = 0; i < 4; i++)
        rf.read((char*)&rarr[i], sizeof(Country));
    rf.close();
    if (!rf.good()) {
        cout << "Error occurred at reading time!" << endl;
        return 1;
    }
    return 0;
}

int main() {
    const int SIZE = 4;
    Country warr[SIZE]; //масив і ініціалізація даних для кожної країни
    warr[0].name = "Ukraine";
    warr[0].official_language = "Ukrainian";
    warr[0].currency = "UAH";
    warr[0].exchange_rate_to_usd = 0.036;

    write(warr);

    Country rarr[SIZE]; // масив для зчитування даних 
    read(rarr);

    cout << "Country details:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Name: " << rarr[i].name << endl;
        cout << "Official Language: " << rarr[i].official_language << endl;
        cout << "Currency: " << rarr[i].currency << endl;
        cout << "Exchange Rate to USD: " << rarr[i].exchange_rate_to_usd << endl;
        cout << endl;
    }

    return 0;
}