#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Stadium
{
    string name;
    int yearBuilt;
    int numFields;
    string sports;

    Stadium() : yearBuilt(0), numFields(0) {}

    Stadium(string n, int y, int fields, string s)
        : name(n), yearBuilt(y), numFields(fields), sports(s) {}
};

// Функція для запису стадіонів у двійковий файл
void writeStadiumsToBinaryFile(const vector<Stadium> &stadiums, const string &filename)
{
    ofstream binaryFile(filename, ios::binary);

    if (!binaryFile.is_open())
    {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }

    for (const auto &stadium : stadiums)
    {

        binaryFile.write(reinterpret_cast<const char *>(&stadium), sizeof(Stadium));
    }

    binaryFile.close();
}

void removeAndAddStadiums(int year, const string &filename)
{
    ifstream binaryFileInput(filename, ios::binary);

    if (!binaryFileInput.is_open())
    {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }

    vector<Stadium> stadiums;
    Stadium tempStadium;

    while (binaryFileInput.read(reinterpret_cast<char *>(&tempStadium), sizeof(Stadium)))
    {
        if (tempStadium.yearBuilt >= year)
        {
            stadiums.push_back(tempStadium);
        }
    }

    binaryFileInput.close();

    stadiums.push_back(Stadium("New Stadium 1", 2022, 3, "Soccer"));
    stadiums.push_back(Stadium("New Stadium 2", 2023, 1, "Golf"));

    // Перезаписуємо файл з оновленими даними
    writeStadiumsToBinaryFile(stadiums, filename);

    // Виводимо новий вміст бінарного файлу в термінал
    ifstream binaryFileOutput(filename, ios::binary);
    cout << "\nNew content of the binary file after removing and adding stadiums:\n";

    while (binaryFileOutput.read(reinterpret_cast<char *>(&tempStadium), sizeof(Stadium)))
    {
        cout << "Name: " << tempStadium.name << endl;
        cout << "Year built: " << tempStadium.yearBuilt << endl;
        cout << "Number of fields: " << tempStadium.numFields << endl;
        cout << "Sports: " << tempStadium.sports << endl;
        cout << "------------------------\n";
    }

    binaryFileOutput.close();
}

int main()
{
    // Створення вектора для зберігання стадіонів
    vector<Stadium> stadiums;

    // Додавання декількох стадіонів у вектор
    stadiums.push_back(Stadium("Stadium 1", 2000, 2, "Football"));
    stadiums.push_back(Stadium("Stadium 2", 1995, 3, "Basketball"));
    stadiums.push_back(Stadium("Stadium 3", 2010, 1, "Tennis"));
    stadiums.push_back(Stadium("Stadium 4", 1980, 4, "Athletics"));
    stadiums.push_back(Stadium("Stadium 5", 2005, 2, "Rugby"));

    // Виведення інформації про стадіони в термінал
    for (const auto &stadium : stadiums)
    {
        cout << "Name: " << stadium.name << endl;
        cout << "Year built: " << stadium.yearBuilt << endl;
        cout << "Number of fields: " << stadium.numFields << endl;
        cout << "Sports: " << stadium.sports << endl;
        cout << "------------------------" << endl;
    }

    // Виклик функції для запису стадіонів у двійковий файл
    writeStadiumsToBinaryFile(stadiums, "stadiums.dat");

    // Запит користувача про рік
    int yearToRemove;
    cout << "Enter the year to remove stadiums built before: ";
    cin >> yearToRemove;

    removeAndAddStadiums(yearToRemove, "stadiums.dat");

    return 0;
}
