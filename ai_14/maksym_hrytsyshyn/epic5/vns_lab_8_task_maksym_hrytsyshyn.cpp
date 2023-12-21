#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
using namespace std;

struct Schoolkid {
    string surname;
    string firstName;
    string patronymic;
    int grade;
    string phoneNumber;
    int marks[4];
};

void fillinfile(const char* file, vector<Schoolkid>& list) {
    ofstream fout(file, ios::binary);
    if (!fout.is_open()) {
        cerr << "An error occurred while attempting to open the file for input" << endl;
        return;
    } else {
        cout << "File is opened." << std::endl;
        for (int i=0; i < list.size(); i++) {
            fout.write(reinterpret_cast<const char*>(&list[i]), sizeof(Schoolkid));
        }
    }    
    fout.close();
} 
    
void deleteschoolkid(vector<Schoolkid> &list) {
    for (int i = 0; i < list.size(); ) {
        bool hasLowGrade = false;
        for (int j = 0; j < 4; ++j) {
            if (list[i].marks[j] <= 2) {
                hasLowGrade = true;
                break;
            }
        }
        if (hasLowGrade) {
            list.erase(list.begin() + i);
        } else {
            ++i;
        }
    }
 
} 

void addSchoolkid(vector<Schoolkid> &list) {
    list.insert(list.begin(), { "Leniv", "Olha", "Petrivna", 6, "+380536971254", {5, 4, 4, 5} });
}
    
void outputFile(vector<Schoolkid> &list) {
    ifstream fin("schoolkid.bin", ios::binary);
    if (!fin.is_open()) {
        cerr << "An error occurred while attempting to open the file for output" << std::endl; 
        return;  
    }
    
    cout << "File is opened." << endl;
    for (int i = 0; i < list.size(); i++){
        cout << "Surname: " << list[i].surname << endl;
        cout << "Name: " << list[i].firstName << endl;
        cout << "Patronymic: " << list[i].patronymic << endl;
        cout << "Grade: " << list[i].grade << endl;
        cout << "Phone number: " << list[i].phoneNumber << endl;
        for(int j = 0; j < 4; j++) {
            cout << "Marks(math/physics/Ukrainian/literature): " << list[i].marks[j] << endl;
        }
        cout << endl;
    }
    fin.close();
}

int main() {
    const char* file = "schoolkid.bin";
    
    vector<Schoolkid> list = {
    {"Hrytsyshyn", "Maksym", "Ivanovych", 11, "+380999999999", {5, 5, 5, 5} },
    {"Skrypnyk", "Khris", "Oleksandrivna", 7, "+380675543445", {3, 2, 4, 4} },
    {"Mul", "Oleh", "Romanovych", 9, "+380584290538", {3, 2, 4, 5} },
    {"Petrova", "Olena", "Klymentiyivna", 10, "+380956490022", {5, 3, 4, 4} },
    };

    fillinfile(file, list);
    outputFile(list);
    deleteschoolkid(list);
    cout << "File after deletion: " << endl;
    outputFile(list);
    addSchoolkid(list);
    cout << "File after adding: " << endl;
    outputFile(list);

    return 0;
}