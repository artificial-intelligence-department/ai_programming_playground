#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct CAR
{
    char model[15];
    int year;
    int price;
    char color[15];
};

int main()
{
    vector<CAR> cars = {
        {"BMW", 2016, 30000, "Black"},
        {"Mercedes", 2006, 20000, "Black"},
        {"Audi", 2011, 16000, "White"},
        {"Opel", 2001, 6000, "Red"},
        {"Renault", 2009, 10000, "White"}};

    ofstream fileBin("file.dat", ios::binary);

    if (!fileBin.is_open())
    {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }

    fileBin.write(reinterpret_cast<char *>(cars.data()), cars.size() * sizeof(CAR));

    if (fileBin.fail())
    {
        cerr << "Error writing to the binary file." << endl;
        return 2;
    }

    fileBin.close();

    cout << "Data written to file.dat successfully." << endl;

    ifstream inputFile("file.dat", ios::binary);

    if (!inputFile.is_open())
    {
        cerr << "Error opening file for reading." << endl;
        return 3;
    }

    vector<CAR> readCars(cars.size());

    inputFile.read(reinterpret_cast<char *>(readCars.data()), readCars.size() * sizeof(CAR));

    if (inputFile.fail())
    {
        cerr << "Error reading from the binary file." << endl;
        return 4;
    }

    inputFile.close();

    cout << "\nCars newer than 2010:\n";

    for (int i = 0; i < readCars.size(); i++)
    {
        const CAR &car = readCars[i];

        if (car.year > 2010)
        {
            cout << " Модель: " << car.model << "\n Рік: " << car.year
                 << "\n Ціна: " << car.price << "\n Колір: " << car.color << "\n\n";
        }
    }

    return 0;
}
