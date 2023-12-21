#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Car {
    string brand;
    int serialNumber;
    string regNumber;
    int year;
};

void manipulateFile() {
    fstream file("cars.bin", ios::binary | ios::in | ios::out | ios::trunc);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    vector<Car> cars = {
            {"BMW", 12345, "AA1234BB", 2010},
            {"Toyota", 67890, "CC5678DD", 2015},
            {"Ford", 44556, "GG1122HH", 2020},
            {"Mercedes", 77889, "II3344JJ", 2019}
    };

    file.write(reinterpret_cast<const char*>(cars.data()), cars.size() * sizeof(Car));

    file.seekg(0, ios::beg);
    Car tempCar;
    cout << "File content:\n";
    while (file.read(reinterpret_cast<char*>(&tempCar), sizeof(Car))) {
        cout << "Brand: " << tempCar.brand << ", Registration Number: " << tempCar.regNumber << endl;
    }

    file.seekp(3 * sizeof(Car), ios::beg);
    int newCount = 2;
    while (file.read(reinterpret_cast<char*>(&tempCar), sizeof(Car))) {
        file.seekp(-sizeof(Car), ios::cur);
        file.write(reinterpret_cast<const char*>(&tempCar), sizeof(Car));
        file.seekp(sizeof(Car), ios::cur);
    }
    file.close();

    fstream("cars.bin", ios::binary | ios::in | ios::out).close();
    file.open("cars.bin", ios::binary | ios::in | ios::out);
    file.seekp(0, ios::end);
    file.write(reinterpret_cast<const char*>(&tempCar), sizeof(Car));

    file.close();
}


int main() {
    manipulateFile();
    return 0;
}