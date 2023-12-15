#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Car {
    char brand[20];
    char serialNumber[20];
    int registrationNumber;
    int year;
};

void File(const vector<Car>& cars, const string& FileName)
{
    ofstream file(FileName);
    if (!file)
    {
        cerr << "An error occurred while opening/creating the file" << endl;
        return;
    }
    for (const Car& c : cars)
    {
        file << c.brand << "\t" << c.serialNumber << "\t" << c.registrationNumber << "\t" << c.year << endl;
    }
    file.close();
}

void DeleteCars(vector<Car>& cars, const char* FileName)
{
    if (cars.size() >= 3)
    {
        cars.erase(cars.begin(), cars.begin() + 3);
    }
    File(cars, FileName);  // Викликаємо функцію File для оновлення файлу
}

bool AddCar(const char* FileName)
{
    Car newcar;
    cout << "Enter the information about a car you want to add:\n";
    cout << "brand: ";
    cin >> newcar.brand;
    cout << "serialNumber: ";
    cin >> newcar.serialNumber;
    cout << "registrationNumber: ";
    cin >> newcar.registrationNumber;
    cout << "year: ";
    cin >> newcar.year;

    string afterCar;
    cout << "After which car do you want to insert a new one?\n";
    cin >> afterCar;
    ifstream file1(FileName);
    if (!file1)
    {
        cerr << "An error occurred while reading data from the file" << endl;
        return false;
    }
    vector<Car> cars;
    string str;
    while (getline(file1, str))
    {
        istringstream iss(str);
        Car c;
        iss >> c.brand >> c.serialNumber >> c.registrationNumber >> c.year;
        cars.push_back(c);
    }
    file1.close();

    ofstream file2("temp.bin");
    if (!file2)
    {
        cerr << "An error occurred while writing data into the file" << endl;
        return false;
    }

    bool found = false;
    for (const Car& c : cars)
    {
        file2 << c.brand << "\t" << c.serialNumber << "\t" << c.registrationNumber << "\t" << c.year << endl;
        if (string(c.brand) == afterCar)
        {
            file2 << newcar.brand << "\t" << newcar.serialNumber << "\t" << newcar.registrationNumber << "\t" << newcar.year << endl;
            found = true;
        }
    }

    if (!found)
    {
        cerr << "This car doesn't exist." << endl;
        return false;
    }

    file2.close();
    remove(FileName);
    rename("temp.bin", FileName);
    return true;
}

void Print(const char* FileName)
{
    ifstream file(FileName);
    if (!file)
    {
        cerr << "An error occurred while printing the file's content" << endl;
        return;
    }
    string str;
    while (getline(file, str))
    {
        cout << str << endl;
    }
    file.close();
}

int main() {
    vector <Car> cars = {
            {"Volvo", "AK", 2888, 2015},
            {"Ford", "AB", 1250, 2000},
            {"Mercedes", "CE", 3378, 1999},
            {"Zhiguli", "AA", 6499, 1970},
            {"Ferrari", "XK", 8822, 1989}
    };

    File(cars, "file1.bin");
    Print("file1.bin");
    DeleteCars(cars, "file1.bin");
    if (!AddCar("file1.bin")) return 1;
    Print("file1.bin");

    return 0;
}
