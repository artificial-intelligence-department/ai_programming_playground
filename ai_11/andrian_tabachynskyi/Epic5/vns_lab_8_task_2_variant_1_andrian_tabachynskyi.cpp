#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct CarOwner {
    string fullName;
    string carNumber;
    string phoneNumber;
    string passportNumber;
};


void addCarOwnersToFile(const string& filename, int numOwners);
void deleteCarOwnerByCarNumber(const string& carNumber, const string& filename);

int main() {
    const string filename = "carOwners.txt";

    int numOwners;
    cout << "Enter the number of car owners: ";
    cin >> numOwners;

    addCarOwnersToFile(filename, numOwners);

    string carNumberToDelete;
    cout << "Enter the car number to delete the owner: ";
    cin >> carNumberToDelete;

    deleteCarOwnerByCarNumber(carNumberToDelete, filename);

    return 0;
}




void addCarOwnersToFile(const string& filename, int numOwners) {
    ofstream outFile(filename);
    if (!outFile.is_open()) {
        cerr << "Error opening file for writing.";
        return;
    }

    CarOwner owner;
    for (int i = 0; i < numOwners; ++i) {
        cout << "Enter full name (first, middle, last): ";
        cin.ignore(); // Ігнорувати попередній символ нового рядка
        getline(cin, owner.fullName);
        cout << "Enter car number: ";
        cin >> owner.carNumber;
        cout << "Enter phone number: ";
        cin >> owner.phoneNumber;
        cout << "Enter passport number: ";
        cin >> owner.passportNumber;

        outFile << owner.fullName << endl
            << owner.carNumber << endl
            << owner.phoneNumber << endl
            << owner.passportNumber << endl;
    }

    outFile.close();
}

void deleteCarOwnerByCarNumber(const string& num, const string& file) {
    ifstream reading(file);
    if (!reading.is_open()) {
        cerr << "Error opening file";
        return;
    }

    vector<CarOwner> owners;
    CarOwner owner;
    string line;

    while (getline(reading, owner.fullName) &&
        getline(reading, owner.carNumber) &&
        getline(reading, owner.phoneNumber) &&
        getline(reading, owner.passportNumber)) {
        if (owner.carNumber != num) {
            owners.push_back(owner);
        }
    }

    reading.close();

    ofstream writing(file);

    for (auto& o : owners) {
        writing << o.fullName << endl
            << o.carNumber << endl
            << o.phoneNumber << endl
            << o.passportNumber << endl;
    }

    writing.close();
}

