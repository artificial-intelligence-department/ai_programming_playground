#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Country
{
    string name;
    string language;
    string currency;
    double exchangeRate;
};

void writeStringToFile(ofstream &file, const string &str)
{
    size_t size = str.size();
    file.write((char *)&size, sizeof(size));
    file.write(str.c_str(), size);
}
void writeStringToFile(ofstream &file, const double &db)
{
    string str = to_string(db);
    size_t size = sizeof(str);
    file.write((char *)&size, sizeof(size));
    file.write(str.c_str(), size);
}

string readStringFromFile(ifstream &file)
{
    size_t size;
    file.read((char *)&size, sizeof(size));
    string str(size, ' ');
    file.read(&str[0], size);
    return str;
}

void writeToFile(const vector<Country> &countries, const string &filename)
{
    cout << "writing countries file..." << endl;
    ofstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Error writing file" << endl;
        return;
    }
    for (const Country &country : countries)
    {
        writeStringToFile(file, country.name);
        writeStringToFile(file, country.language);
        writeStringToFile(file, country.currency);
        writeStringToFile(file, country.exchangeRate);
    }
    file.close();
}

vector<Country> readFromFile(const string &filename)
{
    cout << "reading countries file..." << endl;
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cout << "Error opening file" << endl;
        return {};
    }
    vector<Country> countries;
    while (file.peek() != EOF)
    {
        Country country;
        country.name = readStringFromFile(file);
        country.language = readStringFromFile(file);
        country.currency = readStringFromFile(file);
        country.exchangeRate = stod(readStringFromFile(file));
        countries.push_back(country);
    }
    file.close();
    return countries;
}

void printCountries(const vector<Country> &countries)
{
    for (const Country &country : countries)
    {
        cout << "Name: " << country.name << " Language: " << country.language
             << " Currency: " << country.currency << " Exchange rate: " << country.exchangeRate << endl;
    }
}

void removeCountry(vector<Country> &countries, const string &name)
{
    cout << "removing country " << name << endl;
    countries.erase(remove_if(countries.begin(), countries.end(), [name](const Country &country)
                              { return country.name.compare(name) == 0; }),
                    countries.end());
}
void addCountry(vector<Country> &countries, const Country &country)
{
    cout << "adding a country " << country.name << endl;
    countries.push_back(country);
}

int main()
{
    vector<Country> countries = {
        {"Ukraine", "Ukrainian", "Hryvnia", 39.676767},
        {"USA", "English", "Dollar", 1.0},
    };

    writeToFile(countries, "countries.bin");

    countries = readFromFile("countries.bin");
    printCountries(countries);

    removeCountry(countries, "USA");
    addCountry(countries, {"France", "French", "Euro", 1.0});
    addCountry(countries, {"Spain", "Spanish", "Euro", 1.0});

    writeToFile(countries, "countries.bin");

    countries = readFromFile("countries.bin");
    printCountries(countries);

    return 0;
}
