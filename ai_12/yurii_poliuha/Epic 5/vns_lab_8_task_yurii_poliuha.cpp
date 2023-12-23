#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Car{
    char marka[30];
    char serial_number[10];
    int register_number;
    int year;
};

enum FileOpenResult {Success, Fail};

FileOpenResult WriteToFile(const vector<Car>& cars, const string& FileName);
FileOpenResult ReadFromFile(const string& title);

int main(){
    string title;
    cout << "Enter the title of the file: ";
    getline(cin, title);

    int amount;
    cout << "Enter amount of car: ";
    cin >> amount;
    vector<Car> cars(amount);

    for(int i = 0; i < amount; i++){
        cout << "Enter brand name of car " << i + 1 << ": ";
        cin >> cars[i].marka;
        cout << "Enter serial number of car " << i + 1 << ": ";
        cin >> cars[i].serial_number;
        cout << "Enter register number of car " << i + 1 << ": ";
        cin >> cars[i].register_number;
        cout << "Enter year of car " << i + 1 << ": ";
        cin >> cars[i].year;
    }
    
    FileOpenResult result = WriteToFile(cars, title);
    if(result == Success) cout << "SUCCESS" << endl;
    else if(result == Fail) cout << "ERROR" << endl;

    result = ReadFromFile(title);
    if(result == Success) cout << "SUCCESS" << endl;
    else if(result == Fail) cout << "ERROR" << endl;

    if(cars.size() >= 3){
        cars.erase(cars.begin(), cars.begin() + 3);
        WriteToFile(cars, title);
    }

    return 0;
}

FileOpenResult WriteToFile(const vector<Car>& cars, const string& title){
    ofstream file(title, ios::app);

    if (!file.is_open()) return Fail;
    for (const Car& c : cars)
        file << c.marka << "\t" << c.serial_number << "\t" << c.register_number << "\t" << c.year << endl;
    file.close();

    return Success;
}

FileOpenResult ReadFromFile(const string& title)
{
    ifstream file(title, ios::app);

    if(!file.is_open()) return Fail;
    string str;
    while (getline(file, str))
    {
        cout << str << endl;
    }
    file.close();
    return Success;
}