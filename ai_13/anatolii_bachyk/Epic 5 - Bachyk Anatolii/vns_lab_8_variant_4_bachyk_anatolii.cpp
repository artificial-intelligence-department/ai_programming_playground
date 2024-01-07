#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Human {
    string surname;
    string name;
    string patronymic;
    string address;
    string phone_number;
    int age;
};

void writeData(const string& filename, const vector<Human>& data) {
    ofstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка при відкритті файлу для запису.\n";
        return;
    }
    for (const auto& item : data) {
        file.write(reinterpret_cast<const char*>(&item), sizeof(Human));
    }
}

vector<Human> readData(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Помилка при відкритті файлу для читання.\n";
        return {};
    }
    vector<Human> data;
    Human item;
    while (file.read(reinterpret_cast<char*>(&item), sizeof(Human))) {
        data.push_back(item);
    }
    return data;
}

void printData(const vector<Human>& data) {
    for (const auto& item : data) {
        cout << item.surname << ' ' << item.name << ' ' << item.patronymic << '\n';
        cout << item.address << '\n';
        cout << item.phone_number << '\n';
        cout << item.age << '\n';
    }
}

vector<Human> removeByAge(vector<Human>& data, int age) {
    vector<Human> newData;
    for (const auto& item : data) {
        if (item.age != age) {
            newData.push_back(item);
        }
    }
    return newData;
}

void insertAfterNumber(vector<Human>& data, const string& number, const Human& newHuman) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->phone_number == number) {
            data.insert(it + 1, newHuman);
            break;
        }
    }
}

int main() {
    vector<Human> data = {
        {"Бачик", "Анатолій", "Андрійович", "Львів, вул. Шевченка, 1", "+38066234567", 17},
        {"Сидоров", "Олег", "Васильович", "Київ, вул. Хрещатик, 47", "+380501777568", 50},
        {"Мельник", "Сергій", "Олексійович", "Одеса, вул. Дерибасівська, 3", "+38413234569", 63}
    };
    writeData("data.bin", data);

    vector<Human> read_data = readData("data.bin");
    printData(read_data);

    read_data = removeByAge(read_data, 40);
    printData(read_data);

    Human newHuman = {"Щербовських", "Андрій", "Миколайович", "Харків, вул. Сумська, 4", "+380511234570", 41};
    insertAfterNumber(read_data, "+380501774567", newHuman);
    printData(read_data);

    return 0;
}