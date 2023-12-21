#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct CAR {
    char brand[20];
    int year;
    int price;
    char colors[50];
};

void FileOutput(const char *filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    CAR carData;
    while (fread(&carData, sizeof(carData), 1, file)) {
        cout << "Brand: " << carData.brand << " Year: " << carData.year
             << " Price: " << carData.price << " Colors: " << carData.colors << endl;
    }

    fclose(file);
}

void addCar(const char *filename, const CAR& car) {

    vector<CAR> carVector;
    FILE* file = fopen(filename, "rb");
    if (file) {
        CAR currentCar;
        while (fread(&currentCar, sizeof(currentCar), 1, file)) {
            carVector.push_back(currentCar);
        }
        fclose(file);
    }

    carVector.insert(carVector.begin(), car);

    file = fopen(filename, "wb");
    if (file) {
        for (const auto& currentCar : carVector) {
            fwrite(&currentCar, sizeof(currentCar), 1, file);
        }
        fclose(file);
    } else {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }
}

void deleteCar(const char *filename, const int& conditionYear) {
    FILE* inputFile = fopen(filename, "rb");
    if (!inputFile) {
        cout << "Error opening file for reading: " << filename << endl;
        return;
    }

    vector<CAR> carVector;
    CAR currentCar;

    while (fread(&currentCar, sizeof(currentCar), 1, inputFile)) {
        if(currentCar.year >= conditionYear) {
            carVector.push_back(currentCar);
        }
    }

    fclose(inputFile);

    FILE* outputFile = fopen(filename, "wb");
    if (!outputFile) {
        cout << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto& currentCar : carVector) {
        fwrite(&currentCar, sizeof(currentCar), 1, outputFile);
    }

    fclose(outputFile);
}

int main() {
    const char *filename = "cars.bin";
    int yearToDelete;

    CAR newCar1 = {"Toyota", 1999, 30000, "Blue"};
    CAR newCar2 = {"Ford", 2005, 25000, "Red"};
    CAR newCar3 = {"Honda", 2023, 35000, "Silver"};

    addCar(filename, newCar1);
    addCar(filename, newCar2);
    addCar(filename, newCar3);

    cout << "Starting file contents:\n";
    FileOutput(filename);

    cout << "Delete cars older than (write year of release): \n";
    cin >> yearToDelete;
    deleteCar(filename, yearToDelete);

    cout << "\nFile contents after deleting cars with the year under " << yearToDelete << ":\n";
    FileOutput(filename);

    CAR newCar4 = {"Chevrolet", 2017, 40000, "Black"};
    addCar(filename, newCar4);

    cout << "\nFile contents after adding a new car:\n";
    FileOutput(filename);

    return 0;
}