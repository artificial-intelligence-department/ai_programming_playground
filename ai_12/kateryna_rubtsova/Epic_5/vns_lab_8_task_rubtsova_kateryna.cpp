#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>


using namespace std;

struct Human {
    string surname;
    string name;
    string patronymic;
    int birth_year;
    int height;
    int weight;
};
void printToFile(const vector<Human>& people, const char* filename) {
    ofstream outFile(filename, ios::out | ios::binary);

    if (!outFile.is_open()) {
        cout << "Error opening file for writing.\n";
        return;
    }

    for (const Human& p : people) {
        outFile << p.surname << " " << p.name << " " << p.patronymic << " "
                << p.birth_year << " " << p.height << " " << p.weight << "\n";
    }

    outFile.close();
}

void printToScreen(const vector<Human>& people) {
    cout << "Surname\t\tName\t\tPatronymic\tBirth Year\tHeight\tWeight\n";
    cout << "--------------------------------------------------------------\n";

    for (const Human& p : people) {
        cout << p.surname << "\t\t" << p.name << "\t\t" << p.patronymic << "\t\t"<< p.birth_year << "\t\t" << p.height << "\t\t" << p.weight << "\n";
    }
}
Human inputNewHuman() {
    Human newHuman;
    cout << "Enter surname: ";
    cin >> newHuman.surname;
    cout << "Enter name: ";
    cin >> newHuman.name;
    cout << "Enter patronymic: ";
    cin >> newHuman.patronymic;
    cout << "Enter birth year: ";
    cin >> newHuman.birth_year;
    cout << "Enter height: ";
    cin >> newHuman.height;
    cout << "Enter weight: ";
    cin >> newHuman.weight;
    
    return newHuman;
}
void addHumanAfterSurname(vector<Human>& people, const string& targetSurname, const Human& newHuman) {
    auto it = find_if(people.begin(), people.end(), [&targetSurname](const Human& p) {
        return p.surname == targetSurname;
    });

    if (it != people.end()) {
        people.insert(it + 1, newHuman);
        cout << "Person added after the person with surname " << targetSurname << ".\n";
    } else {
        cout << "Person with surname " << targetSurname << " not found.\n";
    }
}

void deletePeopleByHeightAndWeight(vector<Human>& people, int targetHeight, int targetWeight) {
    people.erase(remove_if(people.begin(), people.end(), [targetHeight, targetWeight](const Human& p) {
        return p.height == targetHeight && p.weight == targetWeight;
    }), people.end());

    cout << "Persons with height " << targetHeight << " and weight " << targetWeight << " deleted.\n";
}

int main() {
    string targetSurname;
    int targetHeight, targetWeight;
    vector<Human> people = {
        {"Yankiv", "Olesia", "Volodymyrivna", 2006, 175, 65},
        {"Stepova", "Mariia", "Andriivna", 2006, 170, 60},
        {"Rubtsova", "Kateryna", "Ihorivna", 2006, 170, 60}
    };

    printToScreen(people);

    Human newHuman = inputNewHuman();
    cout<<"After who?\n";
    cin>> targetSurname;
    addHumanAfterSurname(people, targetSurname, newHuman);

    printToScreen(people);
    cout<<"Height to delete?\n";
    cin>> targetHeight;
    cout<<"Weight to delete?\n";
    cin>> targetWeight;

    deletePeopleByHeightAndWeight(people, targetHeight, targetWeight);

    printToScreen(people);
    printToFile(people, "homosapien.txt");

    return 0;
}